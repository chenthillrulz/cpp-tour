// Example 1: Wrapping a raw cursor int fetch
// operation.
// Fetch an integer from the
//     cursor "cr"
//     at column "col"
//     in the value "val"
void FetchIntField(db_cursor& cr, 
    unsigned int col, int& val)
{
    // Verify type match
    if (cr.column_type[col] != DB_INTEGER)
        throw std::runtime_error(
        "Column type mismatch");
    // Do the fetch
    db_integer temp;
    if (!db_access_column(&cr, col))
        throw std::runtime_error(
        "Cannot transfer data");
    memcpy(&temp, cr.column_data[col],
        sizeof(temp));
    // Required by the DB API for cleanup
    db_release_column(&cr, col);
    // Convert from the database native type to int
    val = static_cast<int>(temp);
}


// Looking into our fictitious database API header, we might find something like this:

#define DB_INTEGER 1
#define DB_STRING 2
#define DB_CURRENCY 3
...
typedef long int db_integer;
typedef char     db_string[255];
typedef struct {
    int integral_part;
    unsigned char fractionary_part;
} db_currency;
...



// Example 2: Wrapping a raw cursor double fetch operation.
//
void FetchDoubleField(db_cursor& cr, unsigned int col, double& val)
{
    if (cr.column_type[col] != DB_CURRENCY)
        throw std::runtime_error("Column type mismatch");
    if (!db_access_column(&cr, col))
        throw std::runtime_error("Cannot transfer data");
    db_currency temp;
    memcpy(&temp, cr.column_data[col], sizeof(temp));
    db_release_column(&cr, col);
    val = temp.integral_part + temp.fractionary_part / 100.;
}


// Let's enumerate the differences between the two pieces of code:


//The input type: double as opposed to int.
//	+ Another type, used internally: db_currency versus db_integer.
//	+ A constant value: DB_CURRENCY versus DB_INTEGER.
//	+ An algorithm: An expression versus the static_cast.



// Example 4: Defining DbTraits
//
// Most general case not implemented
template <typename T> struct DbTraits;
// Specialization for int
template <>
struct DbTraits<int>
{
    enum { TypeId = DB_INTEGER };
    typedef db_integer DbNativeType;
    static void Convert(DbNativeType from, int& to)
    {
        to = static_cast<int>(from);
    }
};
// Specialization for double
template <>
struct DbTraits<double>
{
    enum { TypeId = DB_CURRENCY };
    typedef db_currency DbNativeType;
    static void Convert(const DbNativeType& from, double& to)
    {
        to = from.integral_part + from.fractionary_part / 100.;
    }
};


// Example 5: A generic, extensible FetchField using DbTraits
//
template <class T>
void FetchField(db_cursor& cr, unsigned int col, T& val)
{
    // Define the traits type
    typedef DbTraits<T> Traits;						// HIGHLIGHTED
    if (cr.column_type[col] != Traits::TypeId)
        throw std::runtime_error("Column type mismatch");
    if (!db_access_column(&cr, col))
        throw std::runtime_error("Cannot transfer data");
    typename Traits::DbNativeType temp;					// HIGHLIGHTED
    memcpy(&temp, cr.column_data[col], sizeof(temp));
    Traits::Convert(temp, val);						// HIGHLIGHTED
    db_release_column(&cr, col);
}

// That's it—we just implemented and used a traits class template.

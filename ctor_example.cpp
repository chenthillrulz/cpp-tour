#include <iostream>

using namespace std;

class Example
{
    private:
    int a, b;
    
    public:
    
    Example ():a(0), b(0)
    {
	    cout << "Default constructor called " << endl;
    }
    
    Example (int i, int ii):a(i), b(ii)
    {
	    cout << "Parametrized constructor called " << endl;
    }
    
    Example (Example &eg)
    {
	    cout << "Copy constructor called " << endl;

	    a = eg.a;
	    b = eg.b;
    }

    Example & operator= (Example &from)
    {
	    cout << "Assignment operator called " << endl;
	    
	    a = from.a;
	    b = from.b;

	    return *this;
    }

    ~Example ()
    {
	    cout << "Destructor called " << endl;
    }
};

// Pass by value.
static Example
do_nothing (Example eg_pas_val)
{
	return eg_pas_val;
}

int
main ()
{
    // default constructor gets called
    Example eg_default; 

    // Parametrized constructor gets called
    Example eg_ovl (5,6);

    // Copy constructor gets called
    Example eg_cop (eg_ovl);


    // Calls the copy constructor twice. One will passing the value and one while returning. 
    // A temporary object is created and destroyed implicitly while returning the value.
    // Destructors for two objects is called
    do_nothing (eg_cop);


    // Assignment operator called
    eg_default = eg_cop;


    // Destructors for three objects is called
}

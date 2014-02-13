#include <iostream>
#include <list>

using namespace std;

class Employee
{
	public:
		Employee (const char *pName):name(pName) {}
		Employee(string sName, string sAddress):name(sName),address(sAddress)
		{}
		
		string name;
		string address;
};

// Lets figure out the temporaries from this function
static string 
GetAddrFromName (list<Employee> l, string name)
{
	for( list<Employee>::iterator i = l.begin(); i != l.end(); i++ )
	{
		if( (*i).name == name )
		{
			return (*i).address;
		}
	}
	return "";
}

static void
printEmployeeDetails (Employee emp)
{
	cout << "Name - " << emp.name << endl;
	cout << "Address - " << emp.address << endl;
}

int 
main ()
{
	list<Employee> empList;
	Employee emp("Ravi", "Bangalore");
	string sFind = "Koushik";

	empList.push_back(emp);
	Employee emp1("Koushik","Provo");
	empList.push_back (emp1);

	cout << "Finding address of " << sFind << endl;
	cout << "Found the address " << GetAddrFromName (empList, sFind) << endl;

	// How about GetAddrFromName (empList, "Koushik");

	printEmployeeDetails ("Koushik");
	
	return 0;	
}

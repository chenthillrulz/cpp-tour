#include <iostream>
#include <memory>
#include <stdlib.h>

using namespace std;

const int NumElements = 10;
const int dataLimit = 30;

class Roll
{
	public:
	Roll () 
	{
	}

	void startRolling ()
	{
		cout << "started rolling!!" << endl;
	}

	~Roll ()
	{
	}
};

int main ()
{
	int *a = new int [NumElements]; // Allocating an array
	double &d = *new (nothrow) double(5.2); // Allocating an object and assigning it to a reference


	string *illustration = NULL;
	try 
	{
		illustration = new string ("Illustrating allocation"); // Allocating a single object
	}
	catch (bad_alloc &ba)
	{
		cerr << "bad_alloc caught: " << ba.what() << endl;
	}
	
	
	// Initialize random seed
	srand(time(NULL));
	for (int i = 0; i < NumElements; i++) {
		a[i] = rand () % dataLimit;
	}

	cout << "a[2] - " << a[2] << "\nillustration string - " << illustration << "\ndouble val - " << d << endl;

	// delete [] a[2] // deleting the content of an array
	delete [] a; // deleting an array
	delete &d; // deleting a reference

	Roll *pRoll = new Roll (); // Create a class instance dynamically
	pRoll->startRolling ();
	delete pRoll; // release the memory
}

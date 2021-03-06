#include <iostream>

using namespace std;

// Default access specifier is private for class
class Illustrate // Try replacing keyword class to struct
{
	public:
		constexpr static const float Version = 0.1; // c++-11 keyword constexpr
		int a; // Accessible outside the class

		// Member function
		// Note the implicit this pointer
		void play ()
		{
			cout << "Illustrating classes \n";
		}			
	protected:
		int b; // Accessible by the inherited class
	private:		
		// member variable
		int c; // Not accessible outside the class

};

int main ()
{
	Illustrate is;

	cout << "Version - " << is.Version << endl;
	
	is.play ();

	// TryMe
	//cout << is.b;

	cout << is.a << endl;
}

#include <iostream>
#include <string>

using namespace std;

class IAnimal
{
	public:
		virtual void setName (string) = 0;
		virtual void eat () = 0;
		virtual void sleep () = 0;
};

class Horse : public IAnimal
{
	public:
		Horse () {}
		void setName (string name) {this->name = name;}
		void eat () {cout << name << " is Eating \n";}
		void sleep () {cout << name << " is tired and gets to sleep \n";}
		void talk () {cout << " horse talk \n";}
		void run () {cout << name << " Super fast run \n";}
	private:
		string name;
};


int main ()
{
	Horse hor;

	hor.setName ("Horse");
	hor.run ();
	hor.sleep ();

	cout << "Size of IAnimal: " << sizeof (IAnimal) << endl; 
	cout << "Size of Horse: " << sizeof (Horse) << endl; 

	cout << "Bye Bye " << endl;
}

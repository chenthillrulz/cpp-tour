#include <iostream>
#include <string>

using namespace std;

class Empty 
{
    public :
	void dummy_function () {}
	Empty () { cout << "Empty Constructor \n";}
	~Empty () {cout << "Empty Destructor \n";}
};

class Animal : public Empty
{
	public:
		Animal (string nam = "Who am I ?"):name(nam)
		{
			cout << "Animal Constructor \n";
		}

		void eat () {cout << name << " is Eating \n";}
		void sleep () {cout << name << " is Sleeping \n";}
		void speak () {}

		~Animal () {cout << "Animal Destructor \n";}
	protected:
		string name;
};

class Cat : public Animal
{
	public:
		Cat ():Animal("cat") {cout << "Cat constructor \n";}
		// Over-rides the base implementation
		void speak () {cout << "Meoow \n";}
		~Cat () {cout << "Cat Destructor \n";}
};

class Dog : public Animal
{
	public:
		Dog ():Animal("dog") {cout << "Dog Constructor \n";}
		void speak () {cout << "Woof \n";}
		~Dog () {cout << "Dog Destructor \n";}
};

int main ()
{
	Animal a;
	Cat myPet1;
	Dog myPet2;
	Animal *p = &myPet2;

	myPet1.eat ();
	myPet2.speak ();
	myPet1.sleep ();
	
	// Note that this makes animal to sleep
	p->sleep ();
	a.sleep ();

	// Size of empty
	cout << "Size of Empty: " << sizeof (Empty) << endl;
	
	// Size of Animal is not sizeof Animal + 1
	cout << "Size of Animal: " << sizeof (Animal) << endl;
	cout << "Size of Dog: " << sizeof (Dog) << endl;

	cout << "Bye Bye " << endl;
}

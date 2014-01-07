#include <iostream>
#include <string>

using namespace std;

class Animal
{
	public:
		Animal (string nam = "Who am I ?"):name(nam)
		{
		}

		void eat () {cout << name << " is Eating \n";}
		void sleep () {cout << name << " is tired and gets to sleep \n";}
		void talk () {}
	protected:
		string name;
};


class Bird : public Animal
{
	public:
		Bird ():Animal("bird") {}
		// Over-rides the base implementation
		void talk () {cout << "birds talking \n";}
		void fly () {cout << name << " flying \n";}
};

class Horse : public Animal
{
	public:
		Horse ():Animal("horse") {}
		void talk () {cout << " horse talk \n";}
		void run () {cout << name << " Super fast run \n";}
};

class FlyingHorse: public Bird, public Horse
{
	public:
		FlyingHorse ():Animal ("Flying Horse"){}
};

int main ()
{
	FlyingHorse fh;

	fh.run ();
	fh.fly ();
	fh.sleep ();

	cout << "Bye Bye " << endl;
}

#include <iostream>
#include <string>

using namespace std;

// All classes are not suitable for base classes
class Animal
{
	public:
		Animal (string nam = "Who am I ?"):name(nam)
		{
		}

		virtual void eat () {cout << name << " is Eating \n";}
		virtual void sleep () {cout << name << " is Sleeping \n";}
		virtual void speak () {}
		~Animal () {cout << "Destroying Animal \n";}
	protected:
		string name;
};

class Cat : public Animal
{
	public:
		Cat ():Animal("Cat") {}
		// Over-rides the base implementation
		void speak () {cout << "Meoow \n";}
		~Cat () {cout << "Destroying cat \n";}
};

class Dog : public Animal
{
	public:
		Dog ():Animal("Dog") {}
		void speak () {cout << name << ": Woof \n";}
		~Dog () {cout << "Destroying Dog \n";}
};

class BullDog : public Dog
{
	public:
		BullDog () {name = "Bull Dog";}
		void speak () {cout << name << ": Wrrrrrrrrroof \n";}
		~BullDog () {cout << "Destroying Bull Dog \n";}
};

int main ()
{
	Animal *doggy = new Dog ();
	Animal *bullDoggy = new BullDog ();

	// Note that after this point the client is independent of the derived classes. Derived classes depend on implementation details
	doggy->speak ();
	
	// Note that speak is not marked virtual in Dog class, but still BullDog functions is called.
	bullDoggy->speak ();

	// Am i deleting the whole object ? ;-)
	delete doggy;
	delete bullDoggy;
	
	cout << "Bye Bye " << endl;
}

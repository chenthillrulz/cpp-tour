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

		// Gets weight in pounds
		virtual int getWeight () const {return 0;}
		virtual void eat () {cout << name << " is Eating \n";}
		virtual void sleep () {cout << name << " is Sleeping \n";}
		virtual void speak () {}
		virtual ~Animal () {}
		
	protected:
		string name;
		int weight;
};

class Dog : public Animal
{
	public:
		Dog ():Animal("Dog") {}
		void speak () {cout << name << ": Woof \n";}
		void run () {cout << name << ": Running \n";}

		// Lets ignore setWeight for this demonstration
		int getWeight () const 
		{
			return 20; // In pounds
		}
		~Dog () {}

	private:
};

class Bird: public Animal
{
	public:
		Bird () {name = "Bird";}
		void speak () {cout << name << " singing \n";}
		int getWeight () const {return 3;}
		
		// Speciality of bird
		void fly () {cout << name << " Flyin!! \n";}
		~Bird () {}
};

int main ()
{
	// Consider we used the creational design pattern to abstract the derived classes
	Animal *doggy = new Dog ();
	Animal *bird = new Bird ();
	Animal a;

	doggy->speak ();
	bird->speak ();

	// I would like make the bird fly and dog run from my plugin code
	Bird *realBird = dynamic_cast <Bird *> (bird);
	if (realBird != NULL)
		realBird->fly ();
	
	// Try changing it to static_cast
	Bird *fakeBird = dynamic_cast <Bird *> (doggy);
	if (fakeBird != NULL)
		fakeBird->fly ();
	
	// Uncomment me to see bad_cast exception thrown
	// Bird &b = dynamic_cast <Bird &> (a);

	// safe casting
	float weightInKG = static_cast<float> (doggy->getWeight () / 2.2046);
	cout << "Dog's weight in kg - " << weightInKG << endl;

	delete doggy;
	delete bird;
	
	cout << "Bye Bye " << endl;
}

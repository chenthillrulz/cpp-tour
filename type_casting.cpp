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
		virtual int getWeight () const = 0;
		virtual void eat () {cout << name << " is Eating \n";}
		virtual void sleep () {cout << name << " is Sleeping \n";}
		virtual void speak () {}
		virtual ~Animal () {}
		
		int readWeightFromFile () {return 20;}
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
			// My Base class implementor did not use a const
			int ret = const_cast<Dog *>(this)-> readWeightFromFile ();

			return ret;
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

	doggy->speak ();
	bird->speak ();

	// I would like make the bird fly and dog run from my plugin code
	Bird *realBird = dynamic_cast <Bird *> (bird);
	if (realBird != NULL)
		realBird->fly ();

	// safe casting
	float weightInKG = static_cast<float> (doggy->getWeight () / 2.2046);
	cout << "Dog's weight in kg - " << weightInKG << endl;

	delete doggy;
	delete bird;
	
	cout << "Bye Bye " << endl;
}

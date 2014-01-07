#include <iostream>
#include <string>

using namespace std;

class Animal
{
	public:
		Animal (string nam = "Who am I ?"):name(nam)
		{
		}

		virtual void eat () {cout << name << " is Eating \n";}
		virtual void sleep () {cout << name << " is Sleeping \n";}
		virtual void speak () {}
		virtual ~Animal () {cout << "Destroying Animal \n";}
	protected:
		string name;
};

class Cat : public Animal
{
	public:
		Cat ():Animal("cat") {}
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
		void speak () {cout << name << ":  Wrrrrrrrrroof \n";}
		~BullDog () {cout << "Destroying Bull Dog \n";}
};

class AnimalFactory
{
	public:
		enum ANIMAL {
			CAT,
			DOG,
			BULLDOG
		};
	
		static Animal * make_animal (ANIMAL choice)
		{
			switch (choice)
			{
				case CAT:
					return new Cat ();
				case DOG:
					return new Dog ();
				case BULLDOG:
					return new BullDog ();
				default:
					throw ("Choice not defined");
			}
		}

		static Animal * make_animal (string choice)
		{
			if (choice == "cat")
				return new Cat ();
			else if (choice == "dog")
				return new Dog ();
			else if (choice == "bulldog")
				return new BullDog ();
			else
				throw ("Choice not defined");
		}
};

int main ()
{
	// Note that client is independent of the derived classes. Derived classes depend on implementation details
	Animal *doggy = AnimalFactory::make_animal (AnimalFactory::DOG);
	Animal *bullDoggy = AnimalFactory::make_animal ("bulldog");

	doggy->speak ();
	bullDoggy->speak ();

	delete doggy;
	delete bullDoggy;
	
	cout << "Bye Bye " << endl;
}

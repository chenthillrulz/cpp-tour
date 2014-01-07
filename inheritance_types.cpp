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
		void sleep () {cout << name << " is Sleeping \n";}
		void speak () {}
		void run () {cout << name << " is Running \n";}
	protected:
		string name;
};

class Cat : public Animal
{
	public:
		Cat ():Animal("cat") {}
		// Over-rides the base implementation
		void speak () {cout << "Meoow \n";}
};

class Dog : public Animal
{
	public:
		Dog ():Animal("dog") {}
		void speak () {cout << "Woof \n";}
};

// Robot is implemented in terms of Animal
// It is more like composition. But can take advantage of typedefs inside Animal
class Robot : private Animal
{
	public:
		Robot ():Animal ("Bot") {}
		using Animal::run;
};

int main ()
{
	Robot bot;

	bot.run ();

	//Uncomment me
	//bot.speak ();

	cout << "Bye Bye " << endl;
}

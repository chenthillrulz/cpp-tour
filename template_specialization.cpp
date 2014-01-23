#include <iostream>
#include <vector>

using namespace std;


// initialize is non-type parameter
// one can pass another parameter type too eg:
// template <typename T, typename U> 
template <class T, int initialSize>
class MyContainer
{
	private:
		vector <T> arrayList;
	public:
		MyContainer () 
		{
			arrayList.reserve (initialSize);
		}

		void addItem (T item) 
		{
			arrayList.push_back (item);
		}

		void displayItems ()
		{
			cout << "Displaying items from class template " << endl;
			for (typename vector<T>::iterator it = arrayList.begin (); it != arrayList.end (); ++it)
			{
				cout << *it << " ";
			}
			cout << endl;
		}
};

template <class T, int initialSize>
class MyContainer <T*, initialSize>
{
	public:
		MyContainer () 
		{
			arrayList.reserve (initialSize);
		}

		void addItem (T *item) 
		{
			arrayList.push_back (item);
		}

	
		void displayItems ()
		{
			cout << "Displaying items from partially specialized class " << endl;
			for (typename vector<T *>::iterator it = arrayList.begin (); it != arrayList.end (); ++it)
			{
				cout << **it << " ";
			}
			cout << endl;
		}
	private:
		vector<T *> arrayList;
};

// Partial specialization for bool
template<int initialSize>
class MyContainer <bool, initialSize>
{
	public:
		MyContainer ()
		{
			arrayList.reserve (initialSize);
		}

		void addItem (bool item) 
		{
			arrayList.push_back (item);
		}


		void displayItems ()
		{
			cout << "Displaying items from partially specialized class " << endl;
			for (typename vector<bool>::iterator it = arrayList.begin (); it != arrayList.end (); ++it)
			{
				cout << *it << " ";
			}
			cout << endl;
		}
	private:
		vector<bool> arrayList;
};

// Full specialization for bool would be
// template <>
// class MyContainer <bool, 10>

// Note if the base class did not contain a non-type parameter the full specialization for bool will be
// template <>
// class MyContainer <bool>

int main ()
{
	MyContainer <int, 5> cont;

	cont.addItem (5);
	cont.addItem (6);
	cont.addItem (7);
	cont.addItem (8);

	cont.displayItems ();

	MyContainer <string *, 3> sCont;

	sCont.addItem (new string ("Federer"));
	sCont.addItem (new string ("Nadal"));
	sCont.addItem (new string ("Djokovic"));
	
	// Uses specialized template function to display items
	sCont.displayItems ();

	return 0;
}

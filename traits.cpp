#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct is_pointer 
{
	static const bool val_type = true;
};

template <typename T>
struct is_pointer<T*>
{
	static const bool val_type = false;
};

int
main ()
{
	cout << "is int pointer type ? " << is_pointer<int>::val_type << endl;
	cout << "is int* pointer ? " << is_pointer<int *>::val_type << endl;

	return 0;
}

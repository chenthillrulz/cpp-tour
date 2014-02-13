#include <iostream>

using namespace std;

template <int N>
struct Factorial 
{
	// This can also be a static const int
	enum { value = N * Factorial<N - 1>::value };
};

template <>
struct Factorial<0> 
{
	enum { value = 1 };
};

int 
main ()
{
	int calc = Factorial <10>::value;

	cout << "Factorial of 10 - " << calc << endl;
	return 0;
}

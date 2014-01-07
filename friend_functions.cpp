#include <iostream>

using namespace std;

class Complex
{
	public:
	// Default constructor
	Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

	friend ostream& operator<< (ostream &out, Complex &c);
	private:
		double real;
		double imag;
};

ostream & operator << (ostream &out, Complex &c)
{
	out << "Complex number Real part: " << c.real << " Imaginary part: " << c.imag;

	return out;
}

int main ()
{
	Complex c (3.0, 1.0);

	cout << c << endl;
}

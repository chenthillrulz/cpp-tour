#include <iostream>
#include <fstream>

using namespace std;

class Point
{
	private:
		int iX;
		int iY;
	public:
		Point ():iX(0),iY(0) {}
		Point (int x, int y):iX(x),iY(y) {}

		// Copy constructor. Finds its use primary with a deep copy
		Point (const Point &from);

		ostream & toStream (ostream &out) const;
		istream & fromStream (istream &in);

		// copy assignment operator
		Point & operator= (const Point &from);

		bool operator== (const Point &b);

		Point & operator++ ();
		Point operator++(int);

		// Implement the commented member functions
		//Point & operator-- ();
		//Point & operator--(int) ();

		Point & operator+= (const Point &add);
		//Point & operator-= ();

		Point operator+ (const Point &add);
		//Point opeartor- (const Point &b);

};
	
Point::Point (const Point &from)
{
	iX = from.iX;
	iY = from.iY;
}

ostream & Point::toStream (ostream &out) const
{
	out << "coordinate x - " << iX << endl;
	out << "coordinate y - " << iY << endl;
	return out;
}

istream & Point::fromStream (istream &in)
{
	in >> iX;
	in >> iY;

	return in;
}

ostream & operator<< (ostream &out, const Point &p)
{
	p.toStream(out);
	return out;
}

istream & operator>> (istream &in, Point &p)
{
	p.fromStream (in);
	return in;
}

Point & Point::operator= (const Point &from)
{
	iX = from.iX;
	iY = from.iY;

	return (*this);
}

bool Point::operator== (const Point &b)
{
	return (iX == b.iX && iY == b.iY);
}

Point & Point::operator++ ()
{
	++iX;
	++iY;

	return (*this);
}

// Note the temp object. This causes post increment
// to be less efficient than pre-increment
Point Point::operator++(int)
{
	Point temp(*this);
	++iX;
	++iY;

	return temp;
}

Point & Point::operator+= (const Point &toAdd)
{
	iX += toAdd.iX;
	iY += toAdd.iY;

	return (*this);
}

Point Point::operator+ (const Point &add)
{
	Point temp (*this);

	temp += add;

	return temp;
}

int
main ()
{
	ifstream ifs ("/tmp/input_point.txt", ifstream::in);
	Point a;

	// uses the overloaded operator to extract input from file stream
	cout << "Extracting input from fstream \n";
	ifs >> a;
	cout << a;

	Point b(4,5);
	Point c,d,e;

	// chaining or cascading the operator
	cout << "\nCascading operations using assignment operator \n";
	c = d = e = b;
	cout << d;
	
	cout << "\nUsing pre-increment operat\n";
	++d;
	cout << d;
	
	cout << "\nUsing addition assignment operator d+=c \n";
	d += c;
	cout << d;

	cout << "\nUsing addition operator k = a+b \n";
	Point k;
	k = a + b;
	cout << k;

	return 0;	
}

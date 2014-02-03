#include <iostream>

using namespace std;

class Point
{
	private:
		int iX;
		int iY;
	public:
		Point () {}
		Point (int x, int y):iX(x),iY(y) {}

		// Copy constructor. Finds its use primary with a deep copy
		Point (const Point &from) {}

		ostream & toStream (ostream &out) const;
		istream & fromStream (istream &in);

		// copy assignment operator
		Point & operator= (const Point &from);

		bool operator== (const Point &b);

		Point & operator++ ();
		Point operator++(int);

		//Point & operator-- ();
		//Point & operator--(int) ();

		Point & operator+= (const Point &add);
		//Point & operator-= ();

		Point operator+ (const Point &add);
		//Point opeartor- (const Point &b);

};
	
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
	
}

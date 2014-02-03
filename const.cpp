#include <iostream>

using namespace std;

class Point
{
	private:
		int iX;
		int iY;
	public:
		Point (int x, int y):iX(x), iY(y) {}

		int getX () const 
		{
			return iX;
		}

		int getY() const
		{
			return iY;
		}


};

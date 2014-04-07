#include <iostream>
#include <fstream>

using namespace std;

class MakeHeap 
{
	private:
		int *a, length;
	public:
		MakeHeap (int *input, int len):a(input),length(len)
		{}

		int left (int index) 
		{
			return 2*index + 1;	
		}

		int right (int index)
		{
			return 2 * index + 2;
		}

		bool operator()(int index)
		{
			if (index >= length)
				return true;
			bool isLeftOutOfBound = this->operator()(left(index));
			bool isRightOutOfBound = this->operator()(right (index));

			if (isLeftOutOfBound)
				return false;
			else if (isRightOutOfBound)
			{
				if (a[index] < a[left(index)])
					swap (a[index], a[left(index)]);
			} else {
				int cmpIndex = left(index);
				if (a[right(index)] > a[left(index)])
					cmpIndex = right(index);
				if (a[index] < a[cmpIndex])
					swap (a[index], a[cmpIndex]);
			}
			return false;
		}
};

int
main ()
{
	int *a = NULL;
	int arrayLen = 0;

	cin >> arrayLen;
	a = new int [arrayLen];

	for (int i = 0; i < arrayLen; i++)
	{
		cin >> a[i];
		cout << a[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < arrayLen; i++) 
	{
		MakeHeap mh(a+i, arrayLen-i);
		mh(0);
	}

	for (int i = 0; i < arrayLen; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}

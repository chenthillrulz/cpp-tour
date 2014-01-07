#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int NumElements = 10;
const int dataLimit = 30;

template <typename T>
static void
interchange (T &a, T &b)
{
  T temp;

  temp = a;
  a = b;
  b = temp;
}

int main ()
{
  int a[NumElements];
  int swapCount = 0;


  // Initialize random seed
  srand(time(NULL));

  for (int i = 0; i < NumElements; i++) {
    a[i] = rand () % dataLimit;
  }

  
  cout << "Before swap a[0] - " << a[0] << " a[2] - " << a[2] << endl;
  interchange<int> (a[0], a[2]);
  cout << "After swap  a[0] - " << a[0] << " a[2] - " << a[2] << endl;
}

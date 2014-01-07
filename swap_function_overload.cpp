#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int NumElements = 10;
const int dataLimit = 30;

static void
swap (int &a, int &b)
{
  int temp;

  temp = a;
  a = b;
  b = temp;
}

// Overloaded swap function
static void
swap (int &a, int &b, int *swapCount)
{
  swap (a, b);
  (*swapCount)++;
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

  swap (a[0], a[2], &swapCount);
  swap (a[3], a[5], &swapCount);

  cout << "Number of swaps: " << swapCount << endl;
 
 //swapCount is not passed 
  swap (a[7], a[9]);
}

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int NumElements = 10;
const int dataLimit = 30;

static void
InsertionSort (int (&a) [NumElements])
{
  for (int i = 0; i < NumElements; i++) {
    int ins = a[i], insPos = i;

    // Find the position to insert the element a[i] into the sorted array 0-i
    for (int j = 0; j < i; j++) {
      if (a[j] > a[i]) {
	insPos = j;
	break;
      }
    }

    //Move the elements from insertion position upto i to make space for insertion of a[i]
    for (int k = i; k > insPos; k--) {
      a[k] = a[k-1];
    }

    // insert a[i]
    a[insPos] = ins;
  }
}

int main ()
{
  int a[NumElements];


  // Initialize random seed
  srand(time(NULL));

  for (int i = 0; i < NumElements; i++) {
    a[i] = rand () % dataLimit;
  }

  cout << "Input data" << endl;
  for (int i = 0; i < NumElements; i++)
    cout << a[i] << " ";
  cout << endl;

  InsertionSort (a);

  cout << "Output data" << endl;
  for (int i = 0; i < NumElements; i++)
    cout << a[i] << " ";
  cout << endl;

}

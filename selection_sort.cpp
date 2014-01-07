#include <iostream>
#include <stdlib.h>
#include <time.h>

//Use const instead of macros
const int NumElements = 10;
const int dataLimit = 30;

// Note the inline keyword and pass by reference
inline static void
swap (int &a, int &b)
{
  int temp;

  temp = a;
  a = b;
  b = temp;
}

// Note the array being passed by reference
static void
SelectionSort (int (&a)[NumElements])
{
  for (int i = 0; i < NumElements; i++) {
    int minIndex = i, min = a[i];
    
    for (int j=i; j < NumElements; j++) {
      if (a[j] < min) {
	min = a[j];
	minIndex = j;
      }
    }

    swap (a[i], a[minIndex]);
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
 
 // std is the namespace. :: is the scope resolution operator 
  std::cout << "Input data" << std::endl;
  for (int i = 0; i < NumElements; i++)
    std::cout << a[i] << " ";
  std::cout << std::endl;

  SelectionSort (a);

  std::cout << "Output data" << std::endl;
  for (int i = 0; i < NumElements; i++)
    std::cout << a[i] << " ";
  std::cout << std::endl;

}

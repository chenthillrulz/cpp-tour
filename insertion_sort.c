#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMELEMENTS  10
#define DATALIMIT 30

static void
InsertionSort (int (*a) [NUMELEMENTS])
{
  int i, j, k;

  for (int i = 0; i < NUMELEMENTS; i++) {
    int ins = (*a)[i], insPos = i;

    // Find the position to insert the element a[i] into the sorted array 0-i
    for (int j = 0; j < i; j++) {
      if ((*a)[j] > (*a)[i]) {
	insPos = j;
	break;
      }
    }

    //Move the elements from insertion position upto i to make space for insertion of a[i]
    for (int k = i; k > insPos; k--) {
      (*a)[k] = (*a)[k-1];
    }

    // insert a[i]
    (*a)[insPos] = ins;
  }
}

int main ()
{
  int a[NUMELEMENTS];


  // Initialize random seed
  srand(time(NULL));

  for (int i = 0; i < NUMELEMENTS; i++) {
    a[i] = rand () % DATALIMIT;
  }

  printf ("Input data \n");
  for (int i = 0; i < NUMELEMENTS; i++)
	  printf ("%d ", a[i]);
  printf ("\n");

  InsertionSort (&a);

  printf ("Output data \n");
  for (int i = 0; i < NUMELEMENTS; i++)
	  printf ("%d ", a[i]);
  printf ("\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMELEMENTS  10
#define DATALIMIT 30

static void
swap (int *a, int *b)
{
  int temp;

  temp = *a;
  *a = *b;
  *b = temp;
}

static void
sort (int (*a)[NUMELEMENTS])
{
  int i, j;

  for (i = 0; i < NUMELEMENTS; i++) {
    int minIndex = i, min = (*a)[i];
    
    for (j=i; j < NUMELEMENTS; j++) {
      if ((*a)[j] < min) {
	min = (*a)[j];
	minIndex = j;
      }
    }

    swap (&(*a)[i], &(*a)[minIndex]);
  } 
}

int main ()
{
  int a[NUMELEMENTS];
  int i;

  // Initialize random seed
  srand(time(NULL));

  for (i = 0; i < NUMELEMENTS; i++) {
    a[i] = rand () % DATALIMIT;
  }
  
  printf ("Input data \n");
  for (i = 0; i < NUMELEMENTS; i++)
	  printf ("%d ", a[i]);
  printf ("\n");

  sort (&a);

  printf ("Output data \n");
  for (i = 0; i < NUMELEMENTS; i++)
	  printf ("%d ", a[i]);
  printf ("\n");
}

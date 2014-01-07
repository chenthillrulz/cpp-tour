#include <iostream>
using namespace std;

static double 
division (int a, int b) throw (const char *) // this is deprecated in c++=11
{
   if( b == 0 )
   {
      throw "Division by zero condition!";
      
      //TRYME
      // throw 21; // Will invoke the std:unexpected and if no unexpected handler is set, will terminate the program
   }
   return (a/b);
}

static int
addition (int a, int b) // noexcept keyword replaces throw in c++-11 
{
	return a + b;
}

int main ()
{
   int x = 50;
   int y = 0;
   double z = 0;
 
   try {
     z = division(x, y);
     cout <<  z << endl;
   }catch (const char* msg) {
     cerr << "Exception thrown - " << msg << endl;
   }

   cout << "Addition x+y - " << addition (x,y) << endl;

   return 0;
}

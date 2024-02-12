/* Programmer: Ash Corcoran
   Date: 11/9/2021
   Description: A program to test a recursive function
   Help Received From: C++ Programming: Program Design Including Data Structures by D.S. Malik, Chapter 15, https://www.cplusplus.com/articles/DE18T05o/, https://www.geeksforgeeks.org/int_max-int_min-cc-applications/
   How to Compile: g++ CorcoranProgram3.cpp
   How To Run: ./a.out
*/

#include <iostream>
#include <string>
using namespace std;

//max and min values of ints in C++ from https://www.geeksforgeeks.org/int_max-int_min-cc-applications/
const int MAXINT= 2147483647;
const int MININT= -2147483648;

int repower(int, int);

int main()
{
   int userResponseA=1;
   int userResponseB=0;  

   cout << "Please enter a non-zero value for the first number (or 0 to quit)" << endl;
   cin >> userResponseA;  


   while(userResponseA!=0)
   {
      cout << "Please enter a non-negative number to raise the first number to." << endl;
      cin >> userResponseB;
      
     if(userResponseA<46000 && userResponseB<31 || userResponseB && userResponseA>-46000 && userResponseB>-31)  
         cout << userResponseA << " to the " << userResponseB << " power: " << repower(userResponseA, userResponseB) << endl;
     else
     {
        cout << "Overflow or Underflow experienced. Please enter a different set of numbers." << endl;
      }
      cout << "Please enter a non-zero value for the first number (or 0 to quit)" << endl;
      cin >> userResponseA;  
   }

   return 0;
}



int repower(int a, int b)
{
   if(b==0)
   {
      return 0;
   } 
   else if(b==1)
   {
      return a;
   } 
   else
   { 
       return a * repower(a,b-1);
   }
}

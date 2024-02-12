/* Programmer: Ash Corcoran
   Date: 8/31/22
   Class: CSC2710
   Instructor: Dr. Williams
   Assignment: Program 1
   Description: A program that implements sequential search, exchange sort, binary search, fibonacci term (recursive) and fibonacci term (iterative)
   Resources Used: Foundations of Algorothms, 5th Edition by Richard Neapolitan & KKumarss Mainipour
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


void printArray(const int[]);
int sequentialsearch(const int[], int);
void exchangesort(int[]);
int binarysearch(const int[], int);
int fibonacciRecursive(int, int&);
int fibonacciIterative(int, int&);

int main()
{
   //seeding rand()
   srand(time(NULL));

   //initializing array and setting all random values
   int array[100];
   for(int i=0; i<100; i++)
   {
      array[i] = rand() % 100 +1;
   }

   //printing current array values
   cout << "Your random array is: " << endl;
   printArray(array);
 
   int searchFor = 0;
   int found = -3;

   //sequential search
   cout << "What number would you like to search for?" << endl;
   cin >> searchFor;
   cout << "Searching for " << searchFor << " using sequential search." << endl;
   found = sequentialsearch(array,searchFor);
   if(found >=0)
      cout << "Found at postition " << found << endl;
   else
      cout << "Item not found." << endl;

   //exchange sort
   cout << "Sorting with exchange sort" << endl;
   exchangesort(array);
   cout  << "New array order: " << endl;
   printArray(array);

   //binary search
   cout << "What number would you like to search for?" << endl;
   cin >> searchFor;
   cout << "Searching for " << searchFor << " using binary search." << endl;
   found = binarysearch(array,searchFor);
   if(found >= 0)
      cout << "Found at position " << found << endl;   
   else
      cout << "Item not found." << endl;

   //fibonacci recursive
   int counter = 0;
   cout << "What term of the fibonacci sequence would you like to calculate?" << endl;
   cin >> searchFor;
   cout << "Calculating the " << searchFor << " term using the recursive fibonacci method." << endl;
   cout << fibonacciRecursive(searchFor, counter) << endl;
   cout << "Total Number of Additions: " << counter << endl;

//fibonacci iterative
   counter = 0;
   cout << "Calculating the " << searchFor << " term using the iterative fibonacci method." << endl;
   cout << fibonacciIterative(searchFor, counter) << endl;
   cout << "Total Number of Additions: " << counter << endl;

   return 0;
}

void printArray(const int array[])
{
   cout << "[";
   for(int i=0; i<100; i++)
   {
      cout << array[i];
      if(i<99)
         cout << ", ";
   }
   cout << "]" << endl;
}

int sequentialsearch(const int array[], int searchFor)
{
  int counter = 0;
  int location = 0;
  while((location < 100) && (array[location] != searchFor))
  {
     counter++;
     location++;
  }
  cout << "Total compares: " << counter << endl;
  if(location >= 100)   
    return -1;
  else
    return location;
}

void exchangesort(int array[])
{
   int i;
   int j;
   int temp;
   int counter = 0;
   for(i=0; i<100; i++)
   {
      for(j=i+1; j<100; j++)
      {
         if(array[j] < array[i])
         {
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
            counter++;
         }
      }
   }
   cout << "Total swaps: " << counter << endl;
}

int binarysearch(const int array[], int i)
{
   int low =-1; 
   int high =100;
   int mid =0;
   int location = -1;
   while(low<=high && location == -1)
   {
      mid = (low+high)/2;
      if( i == array[mid])
         location = mid;
      else if (i < array[mid])
         high = mid - 1;
      else
         low = mid + 1;
  }
  return location;

}

int fibonacciRecursive(int i, int& counter)
{
   if(i<=1)
   {
      return i;
   }
   else
   {
      counter++;
      return fibonacciRecursive(i-1, counter) + fibonacciRecursive(i-2, counter);
   }
}

int fibonacciIterative(int n, int& counter)
{
   int f[n];
   f[0]=0;
   if(n>0)
   {
      f[1] = 1;
      for(int i=2; i<=n; i++)
      {
         counter++;
         f[i] = f[i-1] + f[i-2];
      }

   }
   return f[n];

   return 0;
}

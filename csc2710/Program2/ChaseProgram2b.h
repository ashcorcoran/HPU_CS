/*
   Student: Chase Caldwell
   Group: Ash, Owen, Chase, Sam,  
   Class: 2710
   Date: 9/26/2022
   Teacher: Dr. Williams
   About: Algorithms made/used are the quicksort and mergesort functions.  Also compares are calculated for each algortihm.
   

*/

#include <iomanip>
#include <iostream>
using namespace std;

void merge (int h, int m, const int U[], const int V[], int S[], int& counter) // merge part of the mergesort function
{
   int i=0, j=0, k=0;
   while (i < h && j < m)
   {
      counter++; //counter is the counter for the amount of compares
      if (U[i] < V[j])
      {
         S[k] = U[i];
         i++;
      }
      else
      {
         S[k] = V[j];
         j++;
      }
      k++;
   }
   counter++;
   if (i>h)
   {
   //copy V[j . . m] to S[k . . h+m]
      while (j<m)
      {
         S[k] = V[j];
         j++;
         k++;
      }
   }
   else
   {
   //copy U[i . . h] to S[k . . h+m]
      while (i<h)
      {
         S[k] = U[i];
         i++;
         k++;
      }
   }
}

void mergesort (int S[], int n, int& counter)
{
   counter++; //counter is the counter for the amount of compares
   if (n>1)
   {
      const int h = n/2, m = n-h;
      int U[h], V[m];
      //copy S[1 . . h] to U[]
      for (int x=0; x<h; x++)
      {
         U[x]=S[x];
//         cout << U[x] << " ";
      }
//      cout << endl << endl << "First Array Done" << endl << endl;
      //copy S[h+1 . . n] to V[]
      for (int x=0; x<m; x++)
      {
         V[x]=S[h+x];
//         cout << V[x] << " ";
      }
//      cout << endl << endl << "Second Array Done" << endl << endl;
      mergesort(U, h, counter);
      mergesort(V, m, counter);
//      cout << "Merging" << endl << endl;
      merge(h, m, U, V, S, counter);
   }

};

void partition (int low, int high, int& pivotpoint, int S[], int& counter)
{
   int i;
   int j;
   int Sitem;
   j = low;
   int PI;
   PI = S[low];
   
   for (i=low+1; i<high; i++)
   {
      counter++;  //counter is the counter for the amount of compares
      if(S[i] < PI)
      {
         j++;
         //exchange S[i] and S[j]
         Sitem = S[i];
         S[i] = S[j];
         S[j] = Sitem;
      }
   }
   pivotpoint = j;
   //exchange S[low] and S[pivotpoint]
   Sitem = S[low];
   S[low] = S[pivotpoint];
   S[pivotpoint] = Sitem;
};

void quicksort (int low, int high, int S[], int& counter)
{
   int pivotpoint;
   counter++;  //counter is the counter for the amount of compares
   if(high > low)
   {
      partition(low, high, pivotpoint, S, counter);
      quicksort(low, pivotpoint-1, S, counter);
      quicksort(pivotpoint+1, high, S, counter);
   }
};

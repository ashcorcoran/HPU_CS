//Algorithms Project
//Bubble and Insertion Sort
#include <iostream>
#include <ctime>
#include <chrono>

int bubblesort(int[],int);
int insertionsort(int[],int);

using namespace std;


int bubblesort(int arr[], int length)
{
   int compares=0;
   int temp=0;
   bool isSorted = false;
   while(!isSorted)
   {
      for(int i=0; i<length; i++)
      {
         isSorted = true;
         for(int j=1; j<length-i; j++)
         {
            compares++;
            if(arr[j]>arr[j+1])
            {
               isSorted = false;
               temp = arr[j+1];
               arr[j+1] = arr[j];
               arr[j] = temp;
            }
        }
      }
   }
   return compares; 
}

int insertionsort(int arr[], int length)
{
   int compares=0;
   int temp=0;
   int j=0;
   for(int i=2; i<=length; i++)
   {
      temp=arr[i];
      j=i-1;
      compares++;
      while(j>0 && arr[j]>temp)
      {
         arr[j+1] = arr[j];
         j--;
         compares++;
      }
      arr[j+1] = temp;

   }
   return compares;
}


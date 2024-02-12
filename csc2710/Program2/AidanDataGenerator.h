/*
Programmer: [Aidan Breshears]
Date:  [06/26/2022]
Program: [Data Generator]
Filename: [dataGenerator.h]
Description: [Contains functions to generate the following data types on a configurable scale (min to max) of configurable size: Almost sorted, randomly distributed, reverse sorted, many duplicates.]
Assistance received from: [Did this by myself, but it's meant to attach to the sorts created by other team members]
How to compile:  [g++ -Wall dataGenerator.h -o DataGen.h]
How to execute: [For inclusion with data sorting algorithms, each function returns an array of integers to be used later in the program.]

NOTES:.
All data-generator functions require being passed an array, a max value to generate, and the size of the array, in that order. askValues gets the latter two values (max and size).
Read the function description comments. Some of them are important.

*/

#include <stdio.h>
#include <iostream>

using namespace std;

void printArray(int array[], int size) //For testing
{
   for (int i = 0; i < size; i++)
   {
      cout << "a["<<i<<"]="<<array[i];
      if (i < size-1)
      {
         cout << ", ";
      }
   }
   cout << "\n";
}

void askValues (int &max, int &size) //Needs to be passed max and size values from main, should be called before calling a generator to collect values for it
{
//   cout << "Minimum value: ";
//   cin >> min;
   cout << "Maximum value: ";
   cin >> max;
   cout << "Size of array: ";
   cin >> size;
//cout << "min: " << min << ", max: " << max << ", size: " << size << ".\n"; //TEST CODE
}
//Asks for scale and size of array, returns those through reference.

int pseudoRand (int gen, int pos)
//Random number generator based on Unix time + position, intended to be from main array
{
   srand(time(0)+pos);
   int out = rand() % gen;
   if (out == 0)
   {
      out = 1;
   }
   return out;
}

void almostSorted(int array[], int max, int size) //This is seriously overengineered because I figured out a better way to do it 90% of the way through, but basically it generates a generally increasing array with some exceptions (that is, numbers smaller than the previous number)
{
   //int max, size;
   int temp = 0;

   //askValues(max, size);
   //int array[size];

   for (int count = 0; count <= size; count++)
   {
//cout << "test1 "; //TEST CODE
      array[count] = pseudoRand(count+1, count);
      if (count < size-1)
      {
         array[count+1] = pseudoRand(count+1, count+1);
      }
//cout << "test2 "; //TEST CODE
//cout << "pseudoRand: " << (pseudoRand(3, count)) << ", "; //TEST CODE
//cout << "c: " << count << ", Array[c]: " << array[count] << ", Array [c+1]: " << array[count+1] << " "; //TEST CODE
//cout << "Array[" << count << "]=" << array[count] << ", Array[" << count+1 << "]=" << array[count+1] << "\n"; //TEST CODE
      if ((pseudoRand(3, count) > 1) && ((array[count] > array[count+1]) || (array[count] < array[count-1] && count > 0)) && (count < size-1))
      {
//cout << "[REROLL LOOP TRIGGERED] "; //TEST CODE
         temp = 0;
         while (array[count] > array[count+1] || (array[count] < array[count-1] && count > 0))
         {
            if (array[count-1] == max && count > 0)
            {
               array[count-1] = max-1;
            }
            if (array[count+1] == 0)
            {
               array[count+1] = 1;
            }
//cout << " <NUMBER REROLL LOOP> "; //TEST CODE
//cout << "Array[" << count-1 << "]=" << array[count-1] << ", Array[" << count << "]=" << array[count] << ", Array[" << count+1 << "]=" << array[count+1] <<", "; //TEST CODE
               if (array[count] > array[count+1])
                  array[count+1] = pseudoRand(count+1, temp);
               temp++;
               if (array[count] < array[count-1])
                  array[count] = pseudoRand(count+1, temp);

//cout << "NEW Array[" << count-1 << "]=" << array[count-1] << ", NEW Array[" << count << "]=" << array[count] << ", NEW Array[" << count+1 << "]=" << array[count+1] << ", "; //TEST CODE
         }
//cout << " {END REROLL LOOP}\n"; //TEST CODEi
      }
//cout << "Array[" << count << "] = " << array[count] << ", "; //TEST CODE
//cout << "Array[c+1]: " << array[count+1] << ", "; //TEST CODE
   }
//cout << "\n"; //TEST CODE
//cout << "FINAL ARRAY: "; printArray(array, size); cout << "\n"; //TEST CODE

   //return array;
}

void randomSorted(int array[], int max, int size)
{
   //int max, size;

   //askValues(max, size);
   //int array[size];

   for (int count = 0; count <= size; count++)
   {
      array[count] = pseudoRand(max, count);
//cout << array[count] << ", "; //TEST CODE
   }
//cout << "\n"; //TEST CODE

   //return array;
}

void reverseSorted(int array[], int max, int size) //Generates a consistently descending array. Doesn't actually use "max" value, I should change that. Note that as-is, it tends to spit out a few numbers of moderate size followed by a bunch of 1s.
{

   int temp = 0;
   int pos = 0;

   array[pos] = pseudoRand(size, size);

   for (int count = size; count > 1; count--)
   {
      if (pos < size)
      {
         array[pos+1] = pseudoRand(count, count+1);
      }
      
      if ((array[pos] < array[pos+1]) && (pos < size-1))
      {
         temp = 0;
         while ((array[pos] < array[pos+1]))// || (array[pos+1] < (array[pos] = float(array[pos]))*0.9))
         {
            //if (array[pos-1] < 2)
               //array[pos-1] = 2;
            /*if (pos < size-2)
            {
               if (array[pos+2] == 0)
                     array[pos+2] = 1;
                  array[pos+1] = pseudoRand(array[pos+2], temp);
            }
               else
               array[pos+1] = pseudoRand(pos+1, temp);
            temp++;*/
         //array[pos] = pseudoRand(array[pos-1], temp);
         //if (pos < size)
            //{
               array[pos+1] = pseudoRand(array[pos], temp+1);
            //}
            temp++;
         }
         //if (array[pos] > array[pos-1])
            //array[pos-1] = pseudoRand(count+1, temp);
      }

//cout << "Array[" << pos-1 << "]=" << array[pos-1] << ", Array[" << pos << "]=" << array[pos] << ", Array[" << pos+1 << "]=" << array[pos+1] <<"\n"; //TEST CODE
      pos++;
   }

}

void manyDuplicates(int array[], int max, int size)
{
   //int max, size;

   //askValues(max, size);
   //int array[size];
   int timer = 5;
   int spot = 0;

   for (int count = 0; count <= size; count++)
   {
      array[count] = pseudoRand(max, count);
      if (timer < 1)
      {
         array[spot] = array[count];
         timer = 5;
         spot++;
//cout << "TIMER UP\n"; //TEST CODE
      }
//cout << "Loop\n"; //TEST CODE
    timer--;
//cout << array[count] << ", "; //TEST CODE
   }
//cout << "\n"; //TEST CODE

   //return array;
}

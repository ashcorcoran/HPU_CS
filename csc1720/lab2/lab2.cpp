/* Programmer: Ash Corcoran
   Date: 8/31/2021
   Assistance Received From: C++ Programming: Program Design Including Data Structures by D. S. Malik, Chapter 8: Arrays and Strings
   Description: A program that reads and processes data from the high and low temperatures of the year.
   How to compile: g++ lab2.cpp -o lab2.out
   How to run: ./lab2.out < temps.txt
*/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <array>

using namespace std;

//initializing variables
const int MONTHS = 12;
double highs[MONTHS];
double lows[MONTHS];
double threshold;

//function prototypes
void loadArrays(double[], double[]);
double averageOfArray(double[]);
double monthsAbove(double[], double[], double);
void printArray(double[]);

int main()
{

loadArrays(highs, lows);
cout << "Arrays loaded" << endl;
cout << "Average High Temperature: " << averageOfArray(highs) << " degrees" << endl;
cout << "Average Low Temperature: " << averageOfArray(lows) << " degrees"<< endl;
//finding threshold
cout << "What temperature would you like to use as the threshold for 'number of months where temp was above x'?" << endl;
cin >> threshold;
cout << "Months above "<< threshold << " degrees: " << monthsAbove(highs, lows, threshold);
cout << endl << "Highs: " << endl;
printArray(highs);
cout << "Lows: " << endl;
printArray(lows);
return 0;

}



void loadArrays(double array1[], double array2[])
{
   //loading file for input
   ifstream inFile;
   string fileName;
   cout << "What file would you like to take input from?" << endl << "(Please enter full filename, including extension)" << endl;
   cin >> fileName;
   inFile.open(fileName);
   
   //pulling data from file, splitting it into two arrays
   for(int index=0; index<(2*MONTHS); index++)
   {
      if(index<(MONTHS))
      {
         inFile >> array1[index];
      }
      if(index>=MONTHS)
      {
         inFile >> array2[index-MONTHS];
      }
   }

   inFile.close();

}

//finds average temp of array
double averageOfArray(double array1[])
{

   //initializing variables
   double sum = 0;
   double count = 0;
   double average;
 
   //summing array elements
   for(int index=0; index < MONTHS; index++)
   {
      sum = sum+array1[index];
      count++;
   }
  
   average = sum/count;

   //printing for debugging
   //cout << count << endl;
   //cout << sum << endl;
   //cout << average << endl;
   
   return average;
}

//finds number of months with a temp above threshold
double monthsAbove(double array1[], double array2[], double threshold)
{
   //initializing variables
   int count=0;

   for(int index=0; index<MONTHS; index++)
   {
   
      if(array1[index] > threshold)
      {
         count++;
      }
      if(array2[index] > threshold)
      {
         count++;
      }

   }

   return count;
}

void printArray(double array[])
{

   for(int index=0; index<MONTHS; index++)
   {
         cout <<  array[index] << "  ";
   }
   cout << endl;

}

/* Programmer: Ash Corcoran
   Date: 9/7/21
   Description: The implementation file for the couterType class
   Assistance Received From: C++ Programming with Advanced Data Structures by M.S Malik Chapter 10
   How To Compile:
   How To Run: n/a
*/

#include "counterType.h"
#include <iostream>

using namespace std;

//initializes counter to 0
void counterType::initializeCounter()
{
   counter = 0;
}

//sets counter to int 'a' as long as 'a' isn't a negative number
void counterType::setCounter(int a)
{
   if(a>=0)
   {
      counter = a;
   }
   else
   {
      counter = 0;
   }
}

//returns counter value as an int
int counterType::getCounter() const
{
   return counter;
}

//increments counter by 1
void counterType::incrementCounter()
{
   counter++;
}

//decreases counter by 1 as long as counter is greater than 0
void counterType::decrementCounter()
{
   if(counter>0)
   {
      counter--;
   }
}

//prints counter value to output stream
void counterType::displayCounter() const
{
   cout << counter;
}

//constructer with initialization value
counterType::counterType(int a)
{
   setCounter(a);
}

//default constructor
counterType::counterType()
{
   initializeCounter();
}

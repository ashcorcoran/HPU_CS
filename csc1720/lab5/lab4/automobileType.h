/* Programmer: Ash Corcoran
   Date: 9/14/21
   Description: Header File for the automobileType class
   Assistance Received from: C++ Programming with Advanced Data Structures by D.S. Malik Chapter 10
   How to Compile: n/a
   How to Run: N/a
*/

#ifndef automobileType_H
#define automobileType_H

#include <string>

using namespace std;

class automobileType
{
   public:
      void setValues(double oMeter, double fLevel, double mpg);
      //Function to set the values of odometer, fuelLevel, and mpg
      //This function checks if the parameters given are great or equal to 0. If they are less than zero, it initializes the values to 0
      // oMeter = odometer; fLevel = fuelLevel; mpg = milesPerGallon;
      string createDash();
      //This function vreates an annotated string description of the autmobile object's state and returns that string
      void drive(double m);
      //simulates the vehicle driving m miles and adjusts all private variables accordingly
      automobileType();
      //default constructor, everything is set to 0
      automobileType(double oMeter, double fLevel, double mpg:wq
);
      //constructor with parameters
      // odometer=oMeter; fuelLevel=fLevel; milesPerGallon=mpg;
   
   private:
      double odometer;
      double fuelLevel;
      double milesPerGallon;

};

#endif

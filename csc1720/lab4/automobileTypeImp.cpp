/* Programmer: Ash Corcoran
   Date: 9/14/21
   Description: This is the implementation file for the automobileType class. This class holds a car's odometer reading, fuel level, and fuel efficiency
   Assistance Received From: C++ Programming with Advanced Data Structures by D.S. Malik, Chapter 10 and Will Hagenlock for assistance with compiler errors
   How to Compile: cc -c automobileTypeImp.cpp 
   How to Run:n/a
*/

#include "automobileType.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


//default constructor, sets everything to 0
automobileType::automobileType()
{
   setValues(0,0,0);
}

//constructor with parameters
automobileType::automobileType(double oMeter, double fLevel, double mpg)
{
   setValues(oMeter,fLevel,mpg);
}

//sets values (odometer, fuelLevel, milesPerGallon
void automobileType::setValues(double oMeter, double fLevel, double mpg)
{

   //odometer, checks if value < 0
   if(oMeter>=0)
   {
      odometer = oMeter;
   }
   else
   {
      odometer = 0;
   }
   //fuelLevel, checks if value < 0 
   if(fLevel>=0)
   {
      fuelLevel = fLevel;
   }
   else
   {
      fuelLevel = 0;
   }
   //milesPerGallon, checks if value < 0
   if(mpg>=0)
   {
      milesPerGallon = mpg;
   }
   else
   {
      milesPerGallon = 0;
   }
}

//returns values in an annotated string
string automobileType::createDash()
{
   //variable declaration
   string str;
   //odometer
   str = "\nThis automobile has traveled " + to_string(odometer) + " miles.\n";
   //fuel level
   str = str+ "This automobile currently has " + to_string(fuelLevel) + " gallons remaing.\n";
   //milesPerGallon
   str = str+ "This automobile gets " + to_string(milesPerGallon) + " miles per gallon. \n";
   //miles until empty (fuelLevel*milesPerGallon)
   str= str+ "This automobile currently has " + to_string(fuelLevel*milesPerGallon) + " miles until empty.\n";

   return str;

}

//simulates driving m miles and adjusts private variables accordingly
void automobileType::drive(double m)
{
   if(m/milesPerGallon > fuelLevel)
   {
      cout << endl << "You ran out of gas!" << endl;
      cout << "You only managed to drive " + to_string(fuelLevel*milesPerGallon) + " out of " + to_string(m) + " miles." << endl;
      odometer = odometer+fuelLevel*milesPerGallon;   
      fuelLevel = 0;
   }
   else
   {
      odometer = odometer+m;
      fuelLevel = fuelLevel-m/milesPerGallon; 
   }

}

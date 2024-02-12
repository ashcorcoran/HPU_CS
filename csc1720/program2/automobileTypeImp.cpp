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


//default constructor, sets everything to 0, except mpg, which is set to 1
automobileType::automobileType()
{
   odometer=0;
   fuelLevel=0;
   milesPerGallon=1;
   tankCapacity=1;
}

//constructor with parameters, all values must be positive, mpg must be at least 1
automobileType::automobileType(double oMeter, double fLevel, double mpg, double tCap)
{
      if(tCap<0)
      {
         cerr << "Tank Capacity must be greater than or equal to 0, substuting 0." << endl;
         tankCapacity = 0.0;
      }
      else
      {
         tankCapacity = tCap;
      }
   

   if(oMeter>=0 && fLevel>=0 && fLevel<=tCap && mpg>0 && tCap>=0)
   {
      setValues(oMeter,fLevel,mpg);
   }
   else
   {
      //storage variables
      double subO = oMeter;
      double subF = fLevel;
      double subM = mpg;
 
      if(oMeter<0)
      {
         cerr << "Odometer Value is negative, substituting 0." << endl;
         subO = 0;
      }
      if(fLevel<0)
      {
         cerr << "Fuel Level is negative, substituing 0." << endl;
         subF = 0;
      }
      if(tCap<fLevel)
      {
         cerr << "Fuel Level exceeds Tank Capacity, substituting 0." << endl;
         subF = 0;
      }
      if(mpg<1)
      {
         cerr << "Miles per Gallon must be at least 1, substituting 1." << endl;
         subM = 1;
      }
      
      setValues(subO, subF, subM);

   }
}

//sets values (odometer, fuelLevel, milesPerGallon) All values must be positive, mpg must be at least 1
void automobileType::setValues(double oMeter, double fLevel, double mpg)
{

   if(oMeter>=0 && oMeter>=odometer && fLevel>=0 && fLevel<=tankCapacity && mpg>0)
   {
      odometer = oMeter;
      fuelLevel = fLevel;
      milesPerGallon = mpg;
   }
   else //case-specific error messages
   {

      if(oMeter<0)
      {
          cerr << "Invalid Input, please enter a positive number for Odometer." << endl;
      }
     

       if(oMeter<odometer)
      {      
          cerr << "Invalid Input, odometer can only be increased" << endl;
      }
      

      if(fLevel<0)
      {
         cerr << "Invalid Input, please enter a positive number for Fuel Level" << endl;
      }

      
      if(tankCapacity<fLevel)
      {
         cerr << "Tank Capacity: " << tankCapacity << endl << "Fuel Level: " << fLevel << endl;
         cerr << "Invalid Input, Fuel Level must not exceed Tank Capacity." << endl;
      }
      

      if(mpg<1)
      {
      cerr << "Invalid Input, Miles per Gallon must be greater than or equal to 1" << endl;
      }

   }
}

double automobileType::getOdometer() const
{
   return odometer;
}

double automobileType::getFuelLevel() const
{
   return fuelLevel;
}

double automobileType::getFuelEfficiency() const
{
   return milesPerGallon;
}

void automobileType::updateOdometer(double m)
{
   if(m<0)
   {
      cerr << "Invalid Input, odometer value must be positive" << endl;
   }
   if(m<odometer)
   {
      cerr << "Invalid Input, cannot reduce odometer" << endl;
   }
   if(m>=0 && m>=odometer)
   {
      odometer = m;
   }
}

void automobileType::addFuel(double g)
{
   if(g<0)
   {
      cerr << "Invalid Input, must be a positive number" << endl;
   }
   if((fuelLevel+g)>tankCapacity)
   {
      cerr << "Invalid Input, cannot exceed tank capacity." << endl;
   }
   if(g>=0 && (fuelLevel+g)>=tankCapacity)
   {
      fuelLevel+=g;
   }
}





//returns values in an annotated string
string automobileType::createDash() const
{
   //variable declaration
   string str;

   //odometer
   str = "\nThis automobile has traveled " + to_string(odometer) + " miles.\n";

   //tank capacity
   str= str+ "This automobile has a Tank Capacity of: " + to_string(tankCapacity) + "\n";

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
   //checks if m is a positive value
   if(m>=0)
   {
      //checks if there is enough fuel to drive m miles
      if(m/milesPerGallon > fuelLevel)
      {
         cerr << endl << "You ran out of gas!" << endl;
         cerr << "You only managed to drive " + to_string(fuelLevel*milesPerGallon) + " out of " + to_string(m) + " miles." << endl;
         odometer = odometer+fuelLevel*milesPerGallon;   
         fuelLevel = 0;
      }
      else // normal case
      {
         odometer = odometer+m;
         fuelLevel = fuelLevel-m/milesPerGallon; 
      }
   }
   else
   {
       cerr << "Invalid Input, cannot drive an negative amount" << endl;
   }
}

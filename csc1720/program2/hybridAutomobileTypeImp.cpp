/* Programmer: Ash Corcoram
   Date: 9/21/21
   Description: This is the implementations file for the hybridAutomobileType class. This class holds a car's charge level and charge efficiency.
   Assistance Recieved From: C++ Programming: Program Design Including Data Structures by D.S. Malik - chapter 11
   How to Compile: cc -c hybridAutomobileTypeImp.cpp
   How to Run: n/a
*/

#include "automobileType.h"
#include "hybridAutomobileType.h"
#include <iostream>
#include <iomanip>
#include <string>  

using namespace std;

//default constructor
hybridAutomobileType::hybridAutomobileType() : automobileType()
{
   setChargeLevel(0);
   setChargeEfficiency(0);
}


//parameterized constructor
hybridAutomobileType::hybridAutomobileType(double o, double f, double mpg, double tCap, double ch, double chEff) : automobileType(o,f,mpg,tCap)
{
   setChargeLevel(ch);
   setChargeEfficiency(chEff);
}


//function that sets the value of charge to ch, if ch<0 or ch>100, sets charge to 0
void hybridAutomobileType::setChargeLevel(double ch)
{
    if(ch>=0 && ch<=100)
    {
       charge = ch;
    }
    else
    {
       charge= 0;
    }

} 


//function that returns charge level
double hybridAutomobileType::getChargeLevel() const
{
   return charge;
}


//function that sets charge efficiency to eff
void hybridAutomobileType::setChargeEfficiency(double eff)
{
   if(eff>=0)
   {
      chargeEff = eff;
   }
   else
   {
     chargeEff = 0;
   }

}


//function that returns charge efficiency (chargeEff)
double hybridAutomobileType::getChargeEfficiency() const
{
   return chargeEff;
}

void hybridAutomobileType::drive(double m)
{
   if(m>=0)
   {
      while(charge>=15)
      {
         automobileType::updateOdometer(getOdometer()+1);
         charge= charge-(1/chargeEff);
         m--;         
      }
      charge+=m/20;
      automobileType::drive(m);
   }
   else
   {
      cerr << "Invalid Input, cannot drive a negative amount." << endl;
   }
}

//returns values in an annotated string
string hybridAutomobileType::createDash() const
{
   string str;

   str= automobileType::createDash();
   str= str+ "This hybrid automobile currently has "+ to_string(getChargeLevel()) + "% charge remaining.\n";
   str= str+ "This hybrid automobile gets "+ to_string(getChargeEfficiency()) + " miles per 1% charge.\n";

   return str;
}


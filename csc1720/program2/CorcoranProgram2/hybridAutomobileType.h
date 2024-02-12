/* Programmer: Ash Corcoran
   Date: 9/21/21
   Program Description: Header file for hybridautomobiletype class
   Assistance Received From: C++ Programming: Program Design Including Data Structures by D.S. Malik- Chapter 10
   How to compile: n/a
   How to run: n/a
*/
#ifndef hybridAutomobileType_H
#define hybridAutomobileType_H

#include "automobileType.h"

#include <string>

using namespace std;

class hybridAutomobileType : public automobileType
{
   public:
      void setChargeLevel(double ch);
      //Function that sets the value of charge to ch
  
      double getChargeLevel() const;
      //returns current charge level

      void setChargeEfficiency(double eff);
      //sets charge efficiency to eff

      double getChargeEfficiency() const;
      //returns charge effiency

      string createDash() const;
      //returns annotated string

      void drive(double m);
      //simulates the vehicle driving m miles and adjust all private variable accordingly
      //as a hybrid car, this method uses battery charge until the battery is at 15% and then switches to gas
      
      hybridAutomobileType();
      //default constructor

      hybridAutomobileType(double o, double f, double mpg, double tCap, double ch, double chEff);
      //parameterized constructor    

 
   private:
     double charge;
     double chargeEff;

};

#endif

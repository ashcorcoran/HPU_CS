/* Programmer: Ash Corcoran
   Date: 9/14/21
   Description: Program to test the automobileType class
   Assistance Received From: none
   How to Compile: g++ autoTest.cpp automobileTypeImp.o hybridAutomobileTypeImp.o
   How to Run: ./a.out
*/

#include "automobileType.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "hybridAutomobileType.h"


using namespace std;

int main()
{
   cout << showpoint << fixed << setprecision(2);
   cout << endl<< "Creating car1 with default constructors." << endl;
   automobileType car1;
   cout<< "Creating car2 with parameterized constructor." << endl;
   automobileType car2(1,2,3); 
   cout << "Creating hcar1 with default constructor." << endl;
   hybridAutomobileType hcar1;
   cout << "Creating hcar2 with parameterized constructor." << endl;
   hybridAutomobileType hcar2(1,2,3,4,5);


   cout << "Car 1 Dash: " << endl;
   cout << car1.createDash() << endl;
   cout << "Car 2 Dash: " << endl;
   cout << car2.createDash() << endl;
   cout << "Hybrid Car 1 Dash: " << endl;
   cout << hcar1.createDash() << endl;
   cout << "Hybrid Car 2 Dash: " << endl;
   cout << hcar2.createDash() << endl;


   cout << "Setting car1 Values to 1,1,2." << endl << endl;
   car1.setValues(1,1,2);
   cout << "Setting hcar1's charge to 1 and efficiency to 2" << endl;
   hcar1.setChargeLevel(1);
   hcar1.setChargeEfficiency(2);
   cout << "hcar1 now has a charge of: "<< hcar1.getChargeLevel() << endl;
   cout << "hcar1 now has a charge efficiency of: " << hcar1.getChargeEfficiency() << endl << endl;

   cout << "Car 1 Dash: " << endl;
   cout << car1.createDash() << endl;
   cout << "Hybrid Car 1 Dash: ";
   cout << hcar1.createDash() << endl;
   
   cout << "Attempting to drive car1 4 miles ";   
   car1.drive(4);
   cout << endl <<"Attempting to drive car2 5 miles" << endl;
   car2.drive(5);
   cout << endl <<"Attempting to drive hcar1 5 miles";
   hcar1.drive(5);
   cout << endl <<"Attempting to drive hcar2 5 miles" << endl << endl;
   hcar2.drive(5);

   cout << "Car 1 Dash: " << endl;
   cout << car1.createDash() << endl;
   cout << "Car 2 Dash: " << endl;
   cout << car2.createDash() << endl;
   cout << "Hybrid Car 1 Dash: ";
   cout << hcar1.createDash() << endl;
   cout << "Hybrid Car 2 Dash: " << endl;
   cout << hcar2.createDash() << endl;

return 0;
}

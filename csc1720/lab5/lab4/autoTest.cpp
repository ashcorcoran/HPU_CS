/* Programmer: Ash Corcoran
   Date: 9/14/21
   Description: Program to test the automobileType class
   Assistance Received From: none
   How to Compile: g++ autoTest.cpp automobileTypeImp.o
   How to Run: ./a.out
*/

#include "automobileType.h"
#include <iostream>
#include <string>
#include "hybridAutomobileType.h"


using namespace std;

int main()
{

   cout << endl<< "Creating car1 with defaul constructors." << endl;
   automobileType car1;
   cout<< "Creating car2 with parameterized constructor." << endl;
   automobileType car2(1,2,3); 
   cout << "Creating a hybrid car with default constructor." << endl;
   hybridAutomobileType hcar1;
   cout << "Creating a hybrid car with parameterized constructor." << endl;
   hybridAutomobileType hcar2(1,2,3,4,5);


   cout << "Car 1 Dash: " << endl;
   cout << car1.createDash() << endl;
   cout << "Car 2 Dash: " << endl;
   cout << car2.createDash();
   cout << "Hybrid Car 1 Dash: " << endl;
   cout << hcar1.createDash();
   cout << "Hybrid Car 2 Dash: " << endl;
   cout << hcar2.createDash();


   cout << "Setting car1 Values to 1,1,2." << endl;
   car1.setValues(1,1,2);
   cout << "Setting Hyrid car 1's charge to 1 and efficiency to 2" << endl;
   hcar1.setChargeLevel(1);
   hcar1.setChargeLevel(2);
   cout << "Charge: "<< hcar1.getChargeLevel() << endl;
   cout << "Charge Efficiency: " << hcar1.getChargeEfficiency() << endl;

   cout << "Car 1 Dash: " << endl;
   cout << car1.createDash() << endl;
   cout << "Car 2 Dash: " << endl;
   cout << car2.createDash() << endl;
   cout << "Hybrid Car 1 Dash: ";
   cout << hcar1.createDash() << endl;
   cout << "Hybrid Car 2 Dash: " << endl;
   cout << hcar2.createDash() << endl;
   
   cout << "Attempting to drive car1 4 miles " << endl;   
   car1.drive(4);
   cout << "Attempting to drive car2 5 miles" << endl;
   car2.drive(5);
   cout << "Attempting to drive Hybrid Car 1 5 miles" << endl;
   hcar1.drive(5);
   cout << "Attempting to drive Hybrid Car 2 5 miles" << endl;
   hcar2.drive(5);

   cout << "Car 1 Dash: " << endl;
   cout << car1.createDash() << endl;
   cout << "Car 2 Dash: " << endl;
   cout << car2.createDash();
   cout << "Hybrid Car 1 Dash: ";
   cout << hcar1.createDash() << endl;
   cout << "Hybrid Car 2 Dash: " << endl;
   cout << hcar2.createDash() << endl;

return 0;
}

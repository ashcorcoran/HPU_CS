/* Programmer: Ash Corcoran
   Date: 8/30/21
   Assistance receive from: N/A
   How to compile: g++ ch3pe1.cpp
   How to run: ./ch3pe1.cpp
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
int main()
{

   ifstream inFile;
   ofstream outFile;
   string firstname;
   string lastname;
   string dept;
   double salary;
   double bonus;
   double taxes;
   double paycheck;
   double distance;
   double time;
   double speed;
   double cups;
   double cost;
   double sales;
   
   inFile.open("inData.txt");
   outFile.open("outData.txt");

   outFile << fixed << setprecision(2);
   inFile >> firstname >> lastname >> dept >> salary >> bonus >> taxes >> distance >> time >> cups >> cost;

   paycheck = salary+(salary*(bonus/100))-(salary*(taxes/100));
   speed = distance/time;
   sales = cups*cost;

   outFile << "Name: " << firstname << " " <<  lastname << ", Department: " << dept << endl << "Monthly Gross Salary: $" << salary << " Monthly Bonus: " << bonus << "%, Taxes: " << taxes << "% Paycheck: $" << paycheck << endl << "Distance Travelled: " << distance << " miles, Travelling Time: " << time << " hours, Average Speed: " << speed << " miles per hour" << endl << "Number of coffee cups sold: " << cups << ", Cost: $" << cost << " per cup, Sales Amount: $" << sales << endl;

   


   inFile.close();
   outFile.close();
   return 0;
}

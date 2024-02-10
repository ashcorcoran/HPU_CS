/* Programmer: Ash Corcoran
   Date: 8/29/21
   Assistance Received: None
   Description: A program to calculate the area of a rectangle, the area of a circle, or the volume of a cylinder.
   How to compile:
   How to run: 
*/

#include <iostream>
#include <iomanip>
using namespace std;

const double PI = 3.1419;

double rectangle(double l, double w)
{
   return l * w;
}
double circle(double r)
{
   return PI * r * r;
}
double cylinder(double bR, double h)
{
   return PI * bR * bR * h;
}

int main()
{
   double radius;
   double height;
   int choice;
   double length, width;

   cout << fixed << showpoint << setprecision(2) << endl;
   cout << "This program can calculate the area of a rectangle, " << "the area of a circle, or the volume of a cylinder." << endl;
   cout << "To run the program enter: " << endl;
   cout << "1: To find the area of rectangle" << endl;
   cout << "2: To find the area of a circle" << endl;
   cout << "3: To find the volume of a cylinder" << endl;
   cout << "-1: To terminate the process" << endl;
   cin >> choice;
   cout << endl;

   
while (choice != -1)
{
   switch (choice)
   {
   case 3:
     cout << "Enter the radius of the base and the " << "height of the cylinder: ";
     cin >> radius >> height;
     cout << endl;
     cout << "Area = " << cylinder(radius,height) << endl;
     break;

   case 2:
     cout << "Enter the radius of the circle: ";
     cin >> radius;
     cout << endl;

     cout << "Area = " << circle(radius) << endl;
     break;

   case 1:
      cout << "Enter the length and the width " << "of the rectangle: ";
      cin >> length >> width;
      cout << endl;

      cout << "Volume = " << rectangle(length, width) << endl;
      break;

   default:
      cout << "Invalid choice!" << endl;
   }
   
}
return 0;
}


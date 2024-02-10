/* Programmer: Ash Corcoran
   Date: 9/2/21
   Description: A program that when given the center of a circle and a point on the circle will computer the distance between the points, the radius of the circle, the circumference of the circle, and the area of the circle.
   Assistance Received From: www.cplusplus.com/reference/cmath for what header to import to be able to use sqrt and pow
   How To Compile: g++ ch6pe11.cpp
   How To Run: ./a.out
*/


#include <iostream>
#include <fstream>
#include <iomanip>
//used reference to import this header
#include <cmath>

using namespace std;

double const PI = 3.1416;
//variables for center point
double centerX;
double centerY;
//variables for outer point
double pointX;
double pointY;
//variable for holding radius to be able to input into other functions
double radius;

//function prototypes
double findDistance(double, double, double, double);
double findRadius(double, double, double, double);
double findCircumference(double);
double findArea(double);

int main()
{

   cout << fixed << setprecision(2);
   cout << "Please enter the center point of the circle and a point on the circle" << endl;
   cin >> centerX >> centerY >> pointX >> pointY;
   radius = findRadius(centerX, centerY, pointX, pointY);
   cout << "The distance between the two points is: " << findDistance(centerX, centerY, pointX, pointY) << endl;
   cout << "The radius of the circle is: " << radius << endl;
   cout << "The circumference of the circle is: " << findCircumference(radius) << endl;
   cout << "The area of the circle is: " << findArea(radius) << endl;
   return 0;
}

//finds the distance between the two points
double findDistance(double x1, double y1, double x2, double y2)
{
   return sqrt(pow((x2-x1), 2)+pow((y2-y1), 2));
}

//finds the radius of the circle using the distance between the center and the outside point
double findRadius(double x1, double y1, double x2, double y2)
{
   return findDistance(x1, y1, x2, y2);
}

//finds the circumference of the circle based on the radius
double findCircumference(double r)
{
   return 2*PI*r;
}

//finds the area of the circle based on the radius
double findArea(double r)
{
   return PI*pow(r, 2);
}

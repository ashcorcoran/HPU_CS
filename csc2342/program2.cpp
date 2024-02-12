/* Names: Ash Corcoran and Owen Kelley
   Class: CSC-2342
   Date: 2/21/22
   
   A program that takes an input of 4 bits and outputs a message indicating if the 4-bits BCD coded represents a prime number

   Compile Instructions: g++ program2.cpp
   Execution Instructions: ./a.out
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{


   int w = 0;
   int x = 0;
   int y = 0;
   int z = 0;


   cout << "w: ";
   cin >> w;
   cout << "x: ";
   cin >> x;
   cout << "y: ";
   cin >> y;
   cout << "z: ";
   cin >> z;

   int f = ((~w)&x&z)+((~w)&(~x)&y);

   string raw = "";
   raw.append(to_string(w));
   raw.append(to_string(x));
   raw.append(to_string(y));
   raw.append(to_string(z));
  
   int num = stoi(raw, 0, 2);

   if(f==0)
   {
      cout << "BCD " << raw << " represents digit " << num << " and is not a prime number." << endl;
   }
   else
   {
      cout << "BCD " << raw << " represents digit " << num << " and is a prime number." << endl;
   }





return 0;
}

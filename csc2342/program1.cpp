/* Programmer: Ash Corcoran
   Date:2/1/22
   Description: A program to output a truth table for a Boolean expression
   Assistance Received From: N/A
   How To Compile: g++ program1.cpp
   How To Run: ./a.out
*/


#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int valueOfA(int);
int valueOfB(int);
int valueOfC(int);
int valueOfF(int, int, int);
int valueOfG(int, int, int);


int main()
{
   string buffer = "   ";

   //setting up title row
   cout << 'a' << buffer;   
   cout << 'b' << buffer;
   cout << 'c' << buffer;
   cout << 'F' << buffer;
   cout << 'G' << endl;
   //dividing line
   for(int j=0; j<17; j++)
   {
      cout << "-";
   }
   cout << endl;

   //main loop for values of variables
   for(int i=0; i<8; i++)
   {
      cout << valueOfA(i) << buffer;
      cout << valueOfB(i) << buffer;
      cout << valueOfC(i) << buffer;
      cout << valueOfF(valueOfA(i),valueOfB(i),valueOfC(i)) << buffer;
      cout << valueOfG(valueOfA(i),valueOfB(i),valueOfC(i)) << endl;
   }

   return 0;
}


int valueOfA(int counter)
{
   if(counter<4)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

int valueOfB(int counter)
{
   if(counter == 0 || counter == 1 || counter == 4 || counter == 5)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

int valueOfC(int counter)
{
   if(counter%2 == 0)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

int valueOfF(int a, int b, int c)
{
   if(b==1 && (a==0 || c==1))
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

int valueOfG(int a, int b, int c)
{
   if((a==1 && b==1 && c==1) || (a==0 && b==1 && c==1) || (a==0 && b==1 && c==0))  
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

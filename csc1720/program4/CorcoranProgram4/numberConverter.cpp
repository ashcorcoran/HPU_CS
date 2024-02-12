/* Programmer: Ash Corcoran
   Date: 11/23/21
   Description: A program that uses and array-based stack to convert binary    numbers to decimal and then uses a linked-list based stack to convert 
   decimal numbers to binary. 
   How to compile: g++ numberConverter.cpp
   How to Run: ./a.out
*/


#include "myStack.h"
#include "linkedStack.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

void decToBin(int decimal); //prints decimal number given in parameter to binary
int binToDec(int binary); //converts binary number given in parameter to deciaml

int main()
{
   string userChoice = " ";
   int userResponse;
  

      cout << "Would you like to convert to binary or decimal? (or enter 'quit' to quit)" << endl;
      cin >> userChoice;
 
   while(userChoice != "quit" && userChoice != "Quit" && userChoice != "QUIT")
   {
      cout << "Please enter number to convert." << endl;
      cin >> userResponse;

      //decimal to binary
      if(userChoice == "binary" || userChoice == "Binary")
      {
         cout << userResponse << " converted to binary is ";
         decToBin(userResponse);
         cout << endl;
      }

      //binary to decimal
      else if(userChoice == "decimal" || userChoice == "Decimal")
      {
         cout << userResponse << " converted to decimal is ";
         cout << binToDec(userResponse) << endl;
      }

      cout << "Would you like to convert to binary or decimal? (or enter 'quit' to quit)" << endl;
      cin >> userChoice;

   }


   return 0;
}

void decToBin(int decimal)
{
   int binary = 0;
   linkedStackType<int> stack;

   while(decimal>0)
   {
      stack.push(decimal%2);
      decimal = decimal/2;
   }
  
   //prints binary number 
   while(!stack.isEmptyStack())
   {
      cout << stack.top();
      stack.pop();
   }

}
//end decToBin



int binToDec(int binary)
{
   int decimal = 0;
   stackType<int> stack;
   stackType<int> orderedStack;
   int bit = 0;
   int weight = 0;
      
      //pushing onto stack
      while(binary>0)
      {
         bit = binary % 10;
         stack.push(bit);
         binary = binary/10;
      }

      //gets stack in correct order
      while(!stack.isEmptyStack())
      {
         //cout << endl << "STACK: ";
         //cout << stack.top();
         orderedStack.push(stack.top());
         stack.pop();
      }

      //cout << endl;

      while(!orderedStack.isEmptyStack())
      {
         bit = orderedStack.top();
         orderedStack.pop();
         decimal = decimal + bit * static_cast<int>(pow(2.0, weight));
         weight++;
      }

   return decimal;
}
//end binToDec

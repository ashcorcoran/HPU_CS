/* Programmer: Ash Corcoran
   Date: 9/7/21
   Description: This program inputs a string, removes the vowels, and then outputs the string
   Assistance Received From: C++ Programming with Advanced Data Structures by D.S. Malik
   How To Compile: g++ -Wall ch7pe4.cpp -o ch7pe4.out
   How To Run:./ch7pe4.out
*/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

bool disemVoweler(string&);

int main()
{
    //initializes variables
    string str;
    bool check;

    //outputs program description to monitor
   cout << "__________________" << endl << "Welsome to the DisemVOWEler!" << endl << "This program allows a user to input a string. Then the Disemvoweler removes the vowels and outputs the new vowel-less string." << endl << "_________________" << endl << endl;

   //prompts user for string
   cout << "Please enter a string: " << endl;

   //reads in string, using getline() instead of just cin << str allows the user to put in multiple words with spaces in between
   getline(cin, str);

   //attempts to remove vowels
   check = disemVoweler(str);

   //displays string if removal of vowels is succesful
   if(check == true)
   {
      cout << endl << "Disemvowelment successful! Here is your new string: " << endl << str << endl;
   }
   //displays an error message if vowel removal fails
   else
   {
      cout << endl << "Disemvowelment failed. No vowels to be found!" << endl;
   }
   
   return 0;
}


bool disemVoweler(string& str)
{
   
   //initializing variables
   int originalSize = str.length(); //holds original size of string
   
   //processing string
   for(int i = 0; i<str.size(); i++)
   {
      if(str[i] == 'a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
      {
         str = str.substr(0,i)+str.substr((i+1), str.length());
      }
   }

  if(originalSize == str.length())
  {
     return false;
  }
  else
  {
  return true;
  }
}

/* Programmer: Ash Corcoran
   Date: 9/14/21
   Description: A program for grading the answers to a true/false test
   Assistance Received From:
   How To Compile: g++ ch8pe6.cpp
   How To Run: ./a.out
*/


#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double grade(string,string);
char lettergrade(double);

int main()
{
   //importing file
   ifstream file;
   cout << "Please enter input file name, including extensions" << endl;
   string input;
   cin >> input;
   file.open(input);
   //initializing variables
   string answers;
   string studentID;
   string sAnswers;   

   //getting answers
   file >> answers;
   
   file >> studentID;


   //iterating through array
    while(!file.eof())
   {
      //getting student answers
      getline(file,sAnswers);
      
      //gets rid of the whitespace at the start of the string
      sAnswers.erase(sAnswers.begin()); 
      
      cout << "Student " << studentID << " Answered: " << sAnswers << endl;
      
      //sets it so two decimal places are shown
      cout << fixed << setprecision(2);
      
      cout << "This student got a score of " << grade(answers,sAnswers) << "%.";
      cout << endl << "Which is a(n): " << lettergrade(grade(answers,sAnswers)) << endl;
      
      //getting next student
      file >> studentID;
   }

   file.close();
   
   return 0;
}

//returns numerical score
double grade(string answers,string sAnswers)
{
   double score;

   for(int i=0; i<20; i++)
   {
      if(sAnswers.at(i) == ' ') //if they put no answer
      {
           score = score;
      }
      else if(answers.at(i) == sAnswers.at(i)) //if they put correct answer
      {
         score = score+2;
      }
      else //if they put wrong answer
      {
          score = score-1;
      }
   }

   return (score/40)*100.0; //returns score as a percentage
}


char lettergrade(double score) //returns letter grade
{
      if(score<60) //can't use a switch statement for doubles
         return 'F';
      else if(score>=60 && score<70)
         return 'D';
      else if(score>=70 && score<80)
         return 'C';
      else if(score>=80 && score<90)
         return 'B';
      else if(score>=90 && score<100.1)
         return 'A';
      else //error letter, if it fails to grade properly
         return 'X';
}

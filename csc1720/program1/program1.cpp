/* Programmer: Ash Corcoran
   Date:9/9/21
   Description: This program takes data from an input file and creates an array of structs to hold information about each player. Then the array is displayed as well as the player with the most touchdowns and the array sorted by player name
   Assistance Received From: C++ Programming with Advanced Data Structures by D.S. Malik, codespeedy.com/bubble-sort-in-cpp/ for Bubble Sort
   How To Compile: g++ -Wall program1.cpp
   How To Run: ./a.out
*/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//gloabal constants
const int NUMPLAYERS = 10; //number of players on the team

struct player
{
   string name;
   string position;
   int touchdowns;
   int catches;
   int passYards;
   int recYards;
   int rushYards;

};
//function prototypes
void loadArray(player[]);
void printArray(player[]);
void sortArray(player[]);
string mostTouchdowns(player[]);

int main()
{
   //variable declarations
   player team[NUMPLAYERS];

   loadArray(team);
   cout << endl << "Here is the team roster: " << endl << endl;
   printArray(team);
   cout << endl <<"The player with the most touchdowns is " << mostTouchdowns(team) << endl << endl;
   cout << "Here is the team roster sorted in alphabetical order:" << endl << endl;
   sortArray(team);
   printArray(team);

   return 0;
}

//loads the array with information from the input file
void loadArray(player team[])
{
   //import file
   ifstream roster;
   string file;
   cout << "\nPlease enter input data file name, including extension\n";
   cin >> file;
   roster.open(file);


   //for loop to go through array
   for(int i=0; i<NUMPLAYERS; i++)
   {
     roster >> team[i].name;
     roster >> team[i].position;
     roster >> team[i].touchdowns;
     roster >> team[i].catches;
     roster >> team[i].passYards;
     roster >> team[i].recYards;
     roster >> team[i].rushYards;

   }
}

//prints array
void printArray(player team[])
{

   cout << "Name      " << "Position     " << "Touch Downs " << "Catches  " << "Pass Yards  " << "Rec Yards " << "Rush Yards" << endl; 


   for(int i=0; i<NUMPLAYERS; i++)
   {
      //this bit here is specifically because Santiago has a long name and messed everything up. Now this will add the correct number of spaces depending on the length of the name
      if(team[i].name.length()<10)
      {
         cout << team[i].name;
         for(int e = team[i].name.length(); e<10; e++)
         {
            cout << " ";
         }
      }
      cout << team[i].position << "\t";
      //noticed in sample output that the numbers are right justified, and spaced weirdly
      cout.width(6);
      cout << right << team[i].touchdowns << "\t";
      cout.width(6);
      cout << right << team[i].catches << "\t    ";
      cout.width(6);
      cout << right << team[i].passYards << "    ";
      cout.width(6);
      cout << right << team[i].recYards << "\t  ";
      cout.width(6);
      cout << right << team[i].rushYards << endl;

   }

}

//sorts array alphabetically by player name
void sortArray(player team[])
{
   player storage;
   
   //bubble sort from codespeedy.com/bubble-sort-in-cpp/
   for(int j=0; j<(NUMPLAYERS-1); j++)
   {
      for(int i=0; i<(NUMPLAYERS-j-1); i++)
      {
         if(team[i].name.front() > team[i+1].name.front())
         {
            storage = team[i+1];
            team[i+1] = team[i];
            team[i] = storage;
         }

      }
   }

}

//returns player with the most touchdowns
string mostTouchdowns(player team[])
{
   //variables for storage
   int biggest=team[0].touchdowns;
   int biggestPos= 0;

   //iterate through array
   for(int i=0; i<NUMPLAYERS; i++)
   {
      //find most touchdowns
      if(team[i].touchdowns>biggest)
      {
         biggest = team[i].touchdowns;
         biggestPos = i;
      }
   }
   return team[biggestPos].name;
}

/*
 Programmer: Ash Corcoran
 Date:  8/24/21
 Program:  Hello Worlds part 3  
 Filename: HW3.cpp
 Description: This program prompts user for input and gives them the option to display to monitor or save to file and prompts the user for the name of the file to save to
 Assistance received from:C++ Programing pg 163 for taking input from file and writing to a file
 Name of input file: input.txt
 How to compile:  g++ -Wall HW3.cpp -o HW3 
 How to execute: ./HW3 < input.txt */
#include <iostream>
#include <fstream>
using namespace std;

int main(){
//initializing variables
ifstream file;
ofstream newfile;
string greeting;
string response;
string filename;

//importing input file
file.open("input.txt");
getline(file, greeting);

cout << "Input accessed. Would you like to display input or save it to file? (type 'display' for display or 'file' to save to a file\n";
//import user response
cin >> response;

if(response=="file")
{
cout << "Please enter a name for your new file\n";
//take input
cin >> filename;
filename = filename+".txt";
newfile.open(filename, ios::app);
newfile << greeting;
cout << "File saved\n";
}
else if(response=="display")
{
//getline(file, greeting);
cout << greeting;
}
else
{
cout << "Invalid input, please enter either file or display\n";
}

newfile.close();
file.close();

return 0;
}

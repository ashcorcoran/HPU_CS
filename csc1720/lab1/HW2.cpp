/*
 Programmer: Ash Corcoran
 Date: 8/24/21
 Program:  Hello Worlds part 2  
 Filename: HW2.cpp
 Description: This program reads the words "Hello World" from a text file and displays those words to the monitor.
 Assistance received from: "C++ Programming: Program Design Including Data Structures" by D.S. Malik, Chapter 3, Pg. 163 for importing a file in C++
 Name of input file: input.txt 
 How to compile:  g++ -o HW2 HW2.cpp
 How to execute: ./HW2
 */

#include <iostream>
#include <fstream>
using namespace std;

int main() {

string hello;
ifstream file;
//getting input from file
file.open ("input.txt");
getline(file,hello);
cout << hello << endl;

//remember to close file at the end
file.close();
//return 0 to end program
return 0;
}


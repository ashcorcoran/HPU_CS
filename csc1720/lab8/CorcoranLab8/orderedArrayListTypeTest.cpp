/* Programmer: Ash Corcoran
   Date: 10/16/21
   Description: A program to test the functionality of the orderedArrayListType Class
   Assistance Received from: none
   How to Compile: g++ orderedArrayListTypeTest.cpp orderedArrayListTypeImp.o arrayListTypeImp.o
   How to Run: ./a.out
*/

#include "arrayListType.h"
#include "orderedArrayListType.h"
#include <iostream>

using namespace std;

int main()
{
   orderedArrayListType list1;
   orderedArrayListType list2(3);
   orderedArrayListType list3;
   
   cout << "List 1: ";
   list1.print();
   cout << "List 2: ";
   list2.print();
   cout << "List 3: ";
   list3.print();
   cout << endl;

   cout << "Inserting 1 to list1." << endl;
   list1.insert(1);
   cout << "Result: ";
   list1.print();

   cout << "Inserting 1 to end of list2." << endl;
   list2.insertEnd(1);
   cout << "Result: ";
   list2.print();

   cout << "Inserting 1 at position 0 to list3." << endl;
   list3.insertAt(0,1);
   cout << "Result: ";
   list3.print();


   cout << "Inserting 2 to list1." << endl;
   list1.insert(2);
   cout << "Result: ";
   list1.print();

   cout << "Inserting 2 to end of list2." << endl;
   list2.insertEnd(2);
   cout << "Result: ";
   list2.print();

   cout << "Inserting 2 at position 0 to list3." << endl;
   list3.insertAt(0,2);
   cout << "Result: ";
   list3.print();


   cout << "Inserting -1 to list1." << endl;
   list1.insert(-1);
   cout << "Result: ";
   list1.print();

   cout << "Inserting - 1 to end of list2." << endl;
   list2.insertEnd(-1);
   cout << "Result: ";
   list2.print();

   cout << "Inserting -1 at position 0 to list3." << endl;
   list3.insertAt(0,-1);
   cout << "Result: ";
   list3.print();

   cout << "Attempting to insert 3 to list2." << endl;
   list2.insert(3);
   cout << "Result: ";
   list2.print();
   cout << "Attempting to insert 3 to end of list2." << endl;
   list2.insertEnd(3);
   cout << "Result: ";
   list2.print();
   cout << "Attempting to insert 3 at position 3 in list2." << endl;
   list2.insertAt(3,3);
   cout << "Result: ";
   list2.print();

   cout << "Searching for -1 in list 2." << endl;
   cout << "Position: " << list2.seqSearch(-1) << endl;

   cout << "Attempting to replace item in location 0 with 5 in list 2" << endl;
   list2.replaceAt(0,5);
   cout << "Result: ";
   list2.print();

   cout << "Searching for 5 in list 2" << endl;
   cout << "Position: " << list2.seqSearch(5) << endl;

   cout << "Attempting to remove item from location 0 in list1." << endl;
   cout << "Result: ";
   list1.print();


   return 0;
}

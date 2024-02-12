/* Programmer: Ash Corcoran
   Date: 10/5/21
   Description: a program to test arraylisttype and unorderedarraylisttype
   Assistance Received From: none
   How To Compile: g++ test.cpp unorderedArrayListType.o arrayListType.o
   How To Run:./a.out
*/


#include <iostream>
#include <fstream>
#include <iomanip>
#include "arrayListType.h"
#include "unorderedArrayListType.h"

using namespace std;

int main()
{
   unorderedArrayListType list1;
   unorderedArrayListType list2;

   cout << "List 1: ";
   list1.print();
   cout << "List 2: ";
   list2.print();
   cout << endl;

   cout << "Inserting 6 at position 0 in list 1." << endl;
   list1.insertAt(0,6);
   cout << "Inserting 3 at position 0 in list 2." << endl << endl;
   list2.insertAt(0,3);


   cout << "List 1: ";
   list1.print();
   cout << "List 2: ";
   list2.print();
   cout << endl;

   cout << "Inserting 2 first in list1." << endl;
   list1.insertFirst(2);
   cout << "Inserting 8 first in list2." << endl << endl;
   list2.insertFirst(8);

   cout << "List 1: ";
   list1.print();
   cout << "List 2: ";
   list2.print();
   cout << endl;
   
   cout << "Inserting 6 to end of list1." << endl;
   list1.insertEnd(6);
   cout << "Inserting 3 to end of list2." << endl << endl;;
   list2.insertEnd(3);

   cout << "List 1: ";
   list1.print();
   cout << "List 2: ";
   list2.print();
   cout << endl;

   cout << "Replacing position 0 with 7 in list1." << endl;
   list1.replaceAt(0,7);
   cout << "Replacing position 1 with 4 in list2." << endl << endl;
   list2.replaceAt(1,4);

   cout << "List 1: ";
   list1.print();
   cout << "List 2: ";
   list2.print();
   cout << endl;

   cout << "List 1 min: " << list1.findMin() << endl;
   cout << "List 2 min: " << list2.findMin() << endl << endl;

   cout << "Location of 7 in list 1: " <<  list1.seqSearch(7);
   cout << endl;
   cout << "Location of 4 in List 2: " <<  list2.seqSearch(4);
   cout << endl << endl;
   
   cout << "Removing 7 from list1." << endl;
   list1.remove(7);
   cout << "Removing 4 from list2." << endl << endl;
   list2.remove(4);

   cout << "List 1: ";
   list1.print();
   cout << "List 2: ";
   list2.print();
   cout << endl;

   cout << "Removing item at position 0 from list1" << endl;
   list1.removeAt(0);
   cout << "Removing item at position 0 from list2." << endl << endl;
   list2.removeAt(0);

   cout << "List 1: ";
   list1.print();
   cout << "List 2: ";
   list2.print();
   cout << endl;
   

   return 0;
}

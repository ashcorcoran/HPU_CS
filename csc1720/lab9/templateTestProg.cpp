//Data: 2.85 6.74 28.93 61.22 10.00 45.34 61.78 5.75

#include <iostream>
 
#include "unorderedArrayListType.h"

using namespace std; 

int main() 
{
   string result;
   int loc;
   cout << "What data type would you like to test? (int, double, or string)" << endl;
   cin >> result;

if(result == "double" || result == "Double")
{
   unorderedArrayListType<double> dblList(25); 

    double num;                                
    
    cout << "Enter 8 numbers: ";        

    for (int count = 0; count < 8; count++)     
    {
        cin >> num;                             
        dblList.insertEnd(num);                 
    }

    cout << endl;                               

    cout << "dblList: ";               
    dblList.print();                           
    cout << endl;                               

    cout << "Enter the number to be " 
         << "deleted: ";                        
    cin >> num;                                 
    cout << endl;                               

    dblList.remove(num);                        
    cout << "After removing " << num
         << " dblList: ";                       
    dblList.print();                            
    cout << endl;                              
 
    cout << "Enter the search item: "; 

    cin >> num;                                 
    cout << endl;                               

    if (dblList.seqSearch(num) != -1)           
        cout <<  num << " found in dblList at location: "<< dblList.seqSearch(num) << endl;
    else                                        
        cout <<  num << " is not in dblList." << endl;  

   cout << "Checking if dblList is empty... " << endl;
   cout << "Result: ";
   if(dblList.isEmpty())
      cout << "true" << endl << endl;
   else
      cout << "false" << endl << endl;

   cout << "Checking if bdlList is full... " << endl;
   cout << "Result: ";
   if(dblList.isFull())
      cout << "true" << endl << endl; 
   else
      cout << "false" << endl << endl;

   cout << "Size of numList is " << dblList.listSize() << endl;
   cout << "Max size of numList is " << dblList.maxListSize() << endl << endl;

   cout << "dblList: ";
   dblList.print();
   cout << endl;
   cout << "Please enter a location and number to see if the item in the list at that location is equal to. " << endl;
   cin >> loc >> num;
   cout << "Result: ";
   if(dblList.isItemAtEqual(loc, num))
      cout << "true";
   else
      cout << "false";
   cout << endl << endl;

   cout << "Please enter a location to insert at and an item to insert." << endl;
   cin >> loc >> num;
   dblList.insertAt(loc, num);
   cout << "dblList: ";
   dblList.print(); 
   cout << endl;

   cout << "Please enter an item to insert at the end of the list. " << endl;
   cin >> num;
   dblList.insertEnd(num);
   cout << "dblList: ";
   dblList.print();
   cout << endl;

   cout << "Please enter location to remove item at." << endl;
   cin >> loc;
   dblList.removeAt(loc);
   cout << "dblList: ";
   dblList.print();
   cout << endl;

   cout << "Please enter location to retrieve item from." << endl;
   cin >> loc;
   dblList.retrieveAt(loc, num);
   cout << "Number retrieved: " << num;
   cout << endl << endl;

   cout << "Please enter location to replace at and item to replace with." << endl;
   cin >> loc >> num;
   dblList.replaceAt(loc,num);
   cout << "dblList: ";
   dblList.print();
   cout << endl;

   cout << "Please enter location to remove item from." << endl;
   cin >> loc;
   dblList.removeAt(loc);
   cout << "dblList: ";
   dblList.print();
   cout << endl;

   cout << "Clearing dblList." << endl;
   dblList.clearList();
   cout << "dblList: ";
   dblList.print();
}
else if(result=="int" || result=="integer")
{
    unorderedArrayListType<int> numList(25); 
    int num;
   
    cout << "Enter 8 numbers: ";        

    for (int count = 0; count < 8; count++)     
    {
        cin >> num;                             
        numList.insertEnd(num);                 
    }

    cout << endl;                               

    cout << "numList: ";               
    numList.print();                           
    cout << endl;                               

    cout << "Enter the number to be " 
         << "deleted: ";                        
    cin >> num;                                 
    cout << endl;                               

    numList.remove(num);                        
    cout << "After removing " << num
         << " numList: ";                       
    numList.print();                            
    cout << endl;                              
 
    cout << "Enter the search item: "; 

    cin >> num;                                 
    cout << endl;                               

    if (numList.seqSearch(num) != -1)           
        cout <<  num << " found in numList at location: "<< numList.seqSearch(num) << endl;
    else                                        
        cout <<  num << " is not in numList." << endl;  

   cout << "Checking if numList is empty... " << endl;
   cout << "Result: ";
   if(numList.isEmpty())
      cout << "true" << endl << endl;
   else
      cout << "false" << endl << endl;

   cout << "Checking if numList is full... " << endl;
   cout << "Result: ";
   if(numList.isFull())
      cout << "true" << endl << endl; 
   else
      cout << "false" << endl << endl;

   cout << "Size of numList is " << numList.listSize() << endl;
   cout << "Max size of numList is " << numList.maxListSize() << endl << endl;

   cout << "numList: ";
   numList.print();
   cout << endl;
   cout << "Please enter a location and number to see if the item in the list at that location is equal to. " << endl;
   cin >> loc >> num;
   cout << "Result: ";
   if(numList.isItemAtEqual(loc, num))
      cout << "true";
   else
      cout << "false";
   cout << endl << endl;

   cout << "Please enter a location to insert at and an item to insert." << endl;
   cin >> loc >> num;
   numList.insertAt(loc, num);
   cout << "numList: ";
   numList.print(); 
   cout << endl;

   cout << "Please enter an item to insert at the end of the list. " << endl;
   cin >> num;
   numList.insertEnd(num);
   cout << "numList: ";
   numList.print();
   cout << endl;

   cout << "Please enter location to remove item at." << endl;
   cin >> loc;
   numList.removeAt(loc);
   cout << "numList: ";
   numList.print();
   cout << endl;

   cout << "Please enter location to retrieve item from." << endl;
   cin >> loc;
   numList.retrieveAt(loc, num);
   cout << "Number retrieved: " << num;
   cout << endl << endl;

   cout << "Please enter location to replace at and item to replace with." << endl;
   cin >> loc >> num;
   numList.replaceAt(loc,num);
   cout << "numList: ";
   numList.print();
   cout << endl;

   cout << "Please enter location to remove item from." << endl;
   cin >> loc;
   numList.removeAt(loc);
   cout << "numList: ";
   numList.print();
   cout << endl;

   cout << "Clearing numList." << endl;
   numList.clearList();
   cout << "numList: ";
   numList.print();
}
else if(result=="string" || result=="String")
{
    string str;
    unorderedArrayListType<string> strList(25); 

    cout << "Enter 8 strings: ";        

    for (int count = 0; count < 8; count++)     
    {
        cin >> str;                             
        strList.insertEnd(str);                 
    }

    cout << endl;                               

    cout << "strList: ";               
    strList.print();                           
    cout << endl;                               

    cout << "Enter the string to be " 
         << "deleted: ";                        
    cin >> str;                                 
    cout << endl;                               

    strList.remove(str);                        
    cout << "After removing " << str
         << " strList: ";                       
    strList.print();                            
    cout << endl;                              
 
    cout << "Enter the search item: "; 

    cin >> str;                                 
    cout << endl;                               

    if (strList.seqSearch(str) != -1)           
        cout <<  str << " found in strList at location: "<< strList.seqSearch(str) << endl;
    else                                        
        cout <<  str << " is not in strList." << endl;  

   cout << "Checking if strList is empty... " << endl;
   cout << "Result: ";
   if(strList.isEmpty())
      cout << "true" << endl << endl;
   else
      cout << "false" << endl << endl;

   cout << "Checking if strList is full... " << endl;
   cout << "Result: ";
   if(strList.isFull())
      cout << "true" << endl << endl; 
   else
      cout << "false" << endl << endl;

   cout << "Size of strList is " << strList.listSize() << endl;
   cout << "Max size of strList is " << strList.maxListSize() << endl << endl;

   cout << "strList: ";
   strList.print();
   cout << endl;
   cout << "Please enter a location and string to see if the item in the list at that location is equal to. " << endl;
   cin >> loc >> str;
   cout << "Result: ";
   if(strList.isItemAtEqual(loc, str))
      cout << "true";
   else
      cout << "false";
   cout << endl << endl;

   cout << "Please enter a location to insert at and an item to insert." << endl;
   cin >> loc >> str;
   strList.insertAt(loc, str);
   cout << "strList: ";
   strList.print(); 
   cout << endl;

   cout << "Please enter an item to insert at the end of the list. " << endl;
   cin >> str;
   strList.insertEnd(str);
   cout << "strList: ";
   strList.print();
   cout << endl;

   cout << "Please enter location to remove item at." << endl;
   cin >> loc;
   strList.removeAt(loc);
   cout << "strList: ";
   strList.print();
   cout << endl;

   cout << "Please enter location to retrieve item from." << endl;
   cin >> loc;
   strList.retrieveAt(loc, str);
   cout << "Item retrieved: " << str;
   cout << endl << endl;

   cout << "Please enter location to replace at and item to replace with." << endl;
   cin >> loc >> str;
   strList.replaceAt(loc,str);
   cout << "strList: ";
   strList.print();
   cout << endl;

   cout << "Please enter location to remove item from." << endl;
   cin >> loc;
   strList.removeAt(loc);
   cout << "strList: ";
   strList.print();
   cout << endl;

   cout << "Clearing strList." << endl;
   strList.clearList();
   cout << "strList: ";
   strList.print();
}
else
{
   cout << "Invalid input";
}
    return 0;                                   
}

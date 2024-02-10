//CSC-1720
//This program tests various operations of an unordered linked list
 
#include <iostream>
#include "unorderedLinkedList.h"

using namespace std; 

template<class Type>
double findAverage(unorderedLinkedList<Type> &list);

int main()
{
    unorderedLinkedList<int> listA, listB, listC;          
    int num;                                        

    cout << "Creating list with input 22 7 48 93 14 2 " << endl ;

        listA.insertLast(22);                      
        listA.insertLast(7);
        listA.insertLast(48);
        listA.insertLast(93);        
        listA.insertLast(14);
        listA.insertLast(2);
        
    cout << endl;                                   

    cout << "listA: ";                      
    listA.print();                                  
    cout << endl;                                   
    cout << "Length of listA: " 
         << listA.length() << endl;                 

    listB = listA;	   //test the assignment operator 

    cout << endl << "listB: ";                     
    listB.print();                                  
    cout << endl;                                   
    cout << "Length of listB: " 
         << listB.length() << endl;                 

    cout << endl << "Enter the number to be "
         << "deleted: ";                           
    cin >> num;                                     
    cout << endl;                                   

    listB.deleteNode(num);                          
	
    cout << "After deleting " << num 
         << endl << "listB: " ;                     
    listB.print();                                  
    cout << endl;                                

    cout << "Length of listB: " 
         << listB.length() << endl;              

    cout << endl << "Output listA " 
         << "using an iterator:" << endl;            

    linkedListIterator<int> it;                  

    for (it = listA.begin(); it != listA.end(); 
                             ++it)                  
        cout << *it << " ";                        
    cout << endl;                                   

    cout << "Deleting smallest from list b" << endl;
    listB.deleteSmallest();
    listB.print();
    cout << endl << endl;

    cout << "Average of listA is: " << findAverage(listA) << endl;
    cout << "Average of listB is: " << findAverage(listB) << endl;
    cout << endl;

    cout << "Initializing listC with 0,0,0" << endl;
    listC.insertLast(0);
    listC.insertLast(0);
    listC.insertLast(0);
    cout << "Average of listC is: " << findAverage(listC) << endl;
    cout << endl;    

    cout << "Creating listD of doubles 1.5, 6.7, and 9.2" << endl;
    unorderedLinkedList<double> listD;
    listD.insertLast(1.5);
    listD.insertLast(6.7);
    listD.insertLast(9.2);
    listD.print();
    cout << endl;

    cout << "Average of listD is: " << findAverage(listD) << endl;
    cout << "Deleting 6.7 from listD" << endl;
    listD.deleteNode(6.7);
    listD.print();
    cout << endl;

    cout << "Deleting smallest from listD" << endl;
    listD.deleteSmallest();
    listD.print();
    cout << endl;



    return 0;					
}
template<class Type>
double findAverage(unorderedLinkedList<Type> &list)
{
   double sum = 0;
   int count = 0;
   linkedListIterator<Type> current = list.begin();
   
   while(current != NULL)
   {
      sum+= *current;
      count++;
      ++current;
   }
   if(sum/count >= 0)
   {
      return sum/count;
   }
   else
   {
      return 0;
   }
}

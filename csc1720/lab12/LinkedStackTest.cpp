//This program tests various operations of a linked stack
 
#include <iostream>
#include "linkedStack.h"
   
using namespace std; 

void testCopy(linkedStackType<int> OStack);
 
int main()
{
    linkedStackType<int> stack;
    linkedStackType<int> otherStack;
    linkedStackType<int> newStack;

        //Add elements into stack
    stack.push(28);
    stack.push(94);
    stack.push(37);

        //Use the assignment operator to copy the elements
        //of stack into newStack
    newStack = stack;

    cout << "After the assignment operator, newStack: " 
         << endl; 

        //Output the elements of newStack
    while (!newStack.isEmptyStack())
    {
        cout << newStack.top() << endl;	
        newStack.pop();
    }

        //Use the assignment operator to copy the elements
        //of stack into otherStack
    otherStack = stack;

    cout << "Testing the copy constructor." << endl;

    testCopy(otherStack);

    cout << "After the copy constructor, otherStack: " << endl;

    while (!otherStack.isEmptyStack())
    {
        cout << otherStack.top() << endl;	
        otherStack.pop();
    }

    cout << "Testing reverseStack" << endl;
    linkedStackType<int> stack1;
    linkedStackType<int> stack2;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack2.push(4);
    stack2.push(5);
    stack2.push(6);

    cout << endl << "printing stack1" << endl;
    while(!stack1.isEmptyStack())
    {
       cout << stack1.top() << " ";
       stack1.pop();
    }
    cout << endl << "printing stack2" << endl;
    while(!stack2.isEmptyStack())
    {
       cout << stack2.top() << " ";
       stack2.pop();
    }


    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack2.push(4);
    stack2.push(5);
    stack2.push(6);


    cout << endl <<  "stack1.reverseStack(stack2);" << endl;
    stack1.reverseStack(stack2);
    cout << endl <<"printing stack1" << endl;
    while(!stack1.isEmptyStack())
    {
       cout << stack1.top() << " ";
       stack1.pop();
    }
    cout << endl << "printing stack2" << endl;
    while(!stack2.isEmptyStack())
    {
       cout << stack2.top() << " ";
       stack2.pop();
    }
    cout << endl;
    return 0;
}
  
     //Function to test the copy constructor
void testCopy(linkedStackType<int> OStack) 
{
    cout << "Stack in the function testCopy:" << endl;

    while (!OStack.isEmptyStack())
    {
        cout << OStack.top() << endl;	
        OStack.pop();
    }
}

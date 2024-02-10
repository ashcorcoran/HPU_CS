//Program to test the various operations of a stack
 
#include <iostream>
#include "myStack.h"
  
using namespace std;
 
void testCopyConstructor(stackType<int> otherStack);
 
int main()
{
    stackType<int> stack(50);
    stackType<int> copyStack(50);
    stackType<int> dummyStack(100); 

    stack.initializeStack();
    stack.push(85);
    stack.push(28);
    stack.push(56);
    copyStack = stack;  //copy stack into copyStack

    cout << "The elements of copyStack: ";
    while (!copyStack.isEmptyStack())  //print copyStack
    {
        cout << copyStack.top() << " ";
        copyStack.pop();
    }
    cout << endl;

    copyStack = stack;
    testCopyConstructor(stack);  //test the copy constructor

    if (!stack.isEmptyStack())
        cout << "The original stack is not empty." << endl
             << "The top element of the original stack: "
             << copyStack.top() << endl;

    dummyStack = stack;  //copy stack into dummyStack

    cout << "The elements of dummyStack: ";
    while (!dummyStack.isEmptyStack())  //print dummyStack
    {
        cout << dummyStack.top() << " ";
        dummyStack.pop();
    }
    cout << endl;
    
    cout << "Testing reverseStack" << endl;
    stackType<int> stack1;
    stackType<int> stack2;
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

void testCopyConstructor(stackType<int> otherStack)
{
    if (!otherStack.isEmptyStack())
        cout << "otherStack is not empty." << endl
             << "The top element of otherStack: "
             << otherStack.top() << endl;
}

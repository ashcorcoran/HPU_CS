/* Programmer: Ash Corcoran
   Date: 10/16/21
   Description: Implementation file for the orderedArrayListType class
   How to compile: g++ -c orderedArrayListTypeImp.cpp
   How to run: N/A
   Assistance received from: C++ Programming: Program Design Including Data Structures by D.S Malik, Chapter 12
*/ 

#include <iostream>
#include "orderedArrayListType.h"
#include "arrayListType.h"

using namespace std;

orderedArrayListType::orderedArrayListType(int size) : arrayListType(size)
{
}

void orderedArrayListType::insert(int item)
{
   if(length == 0)
   {
      list[length++] = item;
   }
   else if(length == maxSize)
   {
      cerr << "Cannot insert in a full list" << endl;
   }
   else
   {
      int loc;
      bool found = false;

      for(loc = 0; loc < length; loc++)
      {
         if(list[loc] >= item)
         {
             found = true;
             break;
         }
      }

      for(int i = length; i>loc; i--)
      {
         list[i] = list[i-1];
      }

      list[loc] = item;
      length++;

   }
}


void orderedArrayListType::remove(int item)
{
   int loc;

   if(length == 0)
   {
      cerr << "Cannot delete from empty list." << endl;
   }
   else
   {
      loc = seqSearch(item);

      if(loc != -1)
      {
         removeAt(loc);
      }
      else
      {
         cerr << "The item to be deleted is not in the list." << endl;
      }

   }

}

void orderedArrayListType::insertAt(int loc, int item)
{
   if(loc < 0 || loc >= maxSize)
   {
      cerr << "The position of the item to be inserted is out of range." << endl;
   }
   else if ((list[loc-1] <= item && list[loc] >= item) || (loc == 0 && list[loc+1] >= item))
   { 
      for(int i = length; i>=loc; i--)
      {
         list[i] = list[i-1];
      }

      list[loc] = item;
      length++;
   }
   else
   {
      cerr << "Invalid location, inserting item in correct location." << endl;
      insert(item);
   }

}


void orderedArrayListType::insertEnd(int item)
{
   if(length > 0 && list[length-1] <= item)
   {
      list[length] = item;
      length++;
   }
   else if (length == 0)
   {
      insert(item);
   }
   else
   {
      cerr << "Invalid location, inserting item into correct position." << endl;
      insert(item);
   } 
}

void orderedArrayListType::replaceAt(int loc, int item)
{
   if(loc>=length || loc<0)
   {
      cerr << "Location out of bounds." << endl;
   }
   else if((length>=loc+1 && list[loc-1]<= item && list[loc+1]>=item) || (loc==0 && list[loc+1] >= item) || (loc==length-1 && list[loc-1] <= item))
   {
      removeAt(loc);
      insertAt(loc,item);
   }
   else
   {
      cerr << "Invalid location for replacement." << endl;
   }

}

int orderedArrayListType::seqSearch(int item) const
{
   int loc = -1;
   
   for(int i=0; i<length; i++)
   {
      if(list[i]>item)
      {
         break;
      }
      if(list[i]==item)
      {
         loc = i;
         break;
      }
   }
   return loc;
}


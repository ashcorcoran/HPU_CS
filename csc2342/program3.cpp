/*   Programmers: Ash Corcoran and Owen Kelley
     Date: 4/13/22
     Class: Discrete Structures
     Description: A program that sorts a list of words using one of 3 different algorithms and outputs time taken, conditional frequency, and elements moved
*/

#include <iostream>
#include <fstream>
#define MAX 100000
using namespace std;

int sortnum;
long m_cnt=0;
long c_cnt=0;

int main()
{

   string file;
   int sortType;
   
   cout << "Enter the name of the file containing the words: " << endl;
   cin >> file;
   cout << "Enter the number of words to process (sort) <= 100,000: " << endl;
   cin >> sortnum;
   cout >> "Type of sort to analyze: " << endl;
   cin >> sortType;

   struct timeval startTime, stopTime;
   double start, stop, diff;

   if(sortnum==1)
   {
      gettimeofday(&startTime,NULL);
      BubbleSort1(words);
      gettimeofday(&stopTime,NULL);
   }
   else if(sortnum==2)
   {
      gettimeofday(&startTime,NULL);
      BubbleSort2(words);
      gettimeofday(&stopTime,NULL);
   }
   else if(sortnum==3)
   {
      gettimeofday(&startTime,NULL);
      InsertionSort(words);
      gettimeofday(&stopTime,NULL);
   }

   start= startTime.tv_sec+(startTime.tv_usec/1000000.0);
   stop = stopTime.tv_sec +(stopTime.tv_usec/1000000.0);

   diff = stop-start;


   cout << "Results: " << endl << "n = " << sortnum << ", sort technique = " << sortType << ", conditional frequency = " << c_cnt << ", elements moved = " << m_cnt << endl;
   cout << "Time: " << fixed << setprecision(10) << diff << "seconds" << endl;


   string output;
   cout << "Output sorted list (yes/no)? ";
   cin >> output;
   if(output == "yes")
   {
      for(int i = 0; i<=sortnum; i++)
      {
         cout << words[i] << endl;
      }
   } 




return 0;

}

void BubbleSort1(string words[sortnum])
{
   string temp;
 
   for(i=0; i<(words.length-1); i++)
   {
      for(j=0; j<(words.length-1); j++)
      {
         if(words[j] < words[j+1])
         {
            c_cnt++;
            temp = words[j];
            words[j] = words[j+1];
            words[j+1] = temp;
            m_cnt+=2;
         }
      }

   }

}
void BubbleSort2(string words[sortnum])
{
   string temp;
 
   for(i=0; i<(words.length-1); i++)
   {
      for(j=0; j<(words.length-i); j++)
      {
         if(words[j] < words[j+1])
         {
            c_cnt++;
            temp = words[j];
            words[j] = words[j+1];
            words[j+1] = temp;
            m_cnt+=2;
         }
      }

   }
}
void InsertionSort(string words[sortnum])
{
   int i=0;
   string m;

   for(j=1; j<words.length; j++)
   {
      i=1;
      while(words[j] > words[i])
      {
         c_cnt++;
         i++;
      }
      m = words[j];
      for(k=-1;k<j-i-1;k++)
      {
         words[j-k] = words[j-k-1];
      }
      words[i] = m;
      m_cnt++;
   }

}

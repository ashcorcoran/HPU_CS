
#include "NewDataGenerator.h"
#include "AshProgram2.h"
#include "OwenProgram2.h"
#include "SamProgram2.h"
#include "ChaseProgram2b.h"



using namespace std;

int main()
{
   int max = 999999999;
   int size = 1000;
   int Array[size]; 
   randomSorted(Array, max, size);

   auto start2 = high_resolution_clock::now();
   auto stop2 = high_resolution_clock::now();
   auto duration2 = duration_cast<milliseconds>(stop2-start2);

   cout << "Exchange Sort" << endl;
   start2 = high_resolution_clock::now(); //clock2 starts
   exchangeSort(size, Array);
   stop2 = high_resolution_clock::now(); //clock2 stops
   duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
   cout << duration2.count() << " Milliseconds" << endl;

   randomSorted(Array, max, size);

   int compares = 0;

   cout << "Bubble Sort" << endl;
   start2 = high_resolution_clock::now(); //clock2 starts
   compares = bubblesort(Array, size);
   stop2 = high_resolution_clock::now(); //clock2 stops
   duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
   cout << duration2.count() << " Milliseconds" << endl;
   cout << compares << " Compares" << endl;
   compares = 0;
   randomSorted(Array, max, size);

   cout << "Insertion Sort" << endl;
   start2 = high_resolution_clock::now(); //clock2 starts
   compares = insertionsort(Array, size);
   stop2 = high_resolution_clock::now(); //clock2 stops
   duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
   cout << duration2.count() << " Milliseconds" << endl;
   cout << compares << " Compares" << endl;
   compares = 0;

   randomSorted(Array, max, size);

   cout << "Selection Sort" << endl;
   start2 = high_resolution_clock::now(); //clock2 starts
   selectionSort(Array, size);
   stop2 = high_resolution_clock::now(); //clock2 stops
   duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
   cout << duration2.count() << " Milliseconds" << endl;

   randomSorted(Array, max, size);

   cout << "Merge Sort" << endl;
   start2 = high_resolution_clock::now(); //clock2 starts
   mergesort(Array, size, compares);
   stop2 = high_resolution_clock::now(); //clock2 stops
   duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
   cout << duration2.count() << " Milliseconds" << endl;
   cout << compares << " Compares" << endl;
   compares = 0;

   randomSorted(Array, max, size);

   cout << "Quick Sort" << endl;
   start2 = high_resolution_clock::now(); //clock2 starts
   quicksort(0,size,Array,compares);
   stop2 = high_resolution_clock::now(); //clock2 stops
   duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
   cout << duration2.count() << " Milliseconds" << endl;
   cout << compares << " Compares" << endl;
   compares = 0;

   randomSorted(Array, max, size);

   cout << "Heap Sort" << endl;
   start2 = high_resolution_clock::now(); //clock2 starts
   heapSort(Array, size, compares);
   stop2 = high_resolution_clock::now(); //clock2 stops
   duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
   cout << duration2.count() << " Milliseconds" << endl;
   cout << compares << " Compares" << endl;
   compares = 0;

return 0;
}

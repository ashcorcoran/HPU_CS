//  Final Test for Program 2
//  Group: Ash, Owen, Aidan, Chase, Sam

#include "NewDataGenerator.h"
#include "AshProgram2.h"
#include "OwenProgram2.h"
#include "SamProgram2.h"
#include "ChaseProgram2b.h"

using namespace std;

int main()
{

   
   ///setting up arrays for testing
   int max, size;
   size = 1000;
   int RandomArray[size]; 
   randomSorted(RandomArray, max, size);
   int AlmostSortedArray[size];
   almostSorted(AlmostSortedArray, max, size);
   int ReverseSortedArray[size];
   reverseSorted(ReverseSortedArray, max, size);
   int ManyDuplicatesArray[size];
   manyDuplicates(ManyDuplicatesArray, max, size);

   //prompting for sort type
   int choice = 0;
   cout << "What Sort would you like to run? Please input the number of your choice." << endl;
   cout << "1) Exchange Sort" << endl;
   cout << "2) Selection Sort" << endl;
   cout << "3) Bubble Sort" << endl;
   cout << "4) Insertion Sort" << endl;
   cout << "5) Merge Sort" << endl;
   cout << "6) Quick Sort" << endl;
   cout << "7) Heap Sort" << endl;
   cin >> choice;

   auto start2 = high_resolution_clock::now();
   auto stop2 = high_resolution_clock::now();
   auto duration2 = duration_cast<milliseconds>(stop2-start2);
   
   //exchange sort
   if(choice == 1)
   {
      cout << "Exchange Sort, Random:" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      exchangeSort(size, RandomArray);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;


      cout << "Exchange Sort, Almost Sorted:" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      exchangeSort(size, AlmostSortedArray);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;


      cout << "Exchange Sort, Reverse Sorted:" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      exchangeSort(size, ReverseSortedArray);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;


      cout << "Exchange Sort, Many Duplicates:" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      exchangeSort(size, ManyDuplicatesArray);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;
   }


  //Selection Sort
   else if (choice == 2)
   {

      cout << endl;
      cout << "Selection Sort, Random:" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      selectionSort(RandomArray, size);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;

      cout << "Selection Sort, Almost Sorted:" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      selectionSort(AlmostSortedArray, size);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;

      cout << "Selection Sort, Reverse Sorted:" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      selectionSort(ReverseSortedArray, size);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;

      cout << "Selection Sort, Many Duplicates:" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      selectionSort(ManyDuplicatesArray, size);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;
   }

   //Bubble Sort
   else if(choice == 3)
   {
      int compares = 0;

      cout << endl;
      cout << "Bubble Sort, Random:" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      compares = bubblesort(RandomArray, size);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;
      cout << compares << " Compares" << endl;

      cout << endl;
      cout << "Bubble Sort, AlmostSorted:" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      compares =  bubblesort(AlmostSortedArray, size);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;
      cout << compares << " Compares" << endl;

      cout << endl;
      cout << "Bubble Sort, Reverse Sorted:" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      compares = bubblesort(ReverseSortedArray, size);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;
      cout << compares << " Compares" << endl;

      cout << endl;
      cout << "Bubble Sort, Many Duplicates:" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      compares = bubblesort(ManyDuplicatesArray, size);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;
      cout << compares << " Compares" << endl;
   }

   //Insertion Sort
   if(choice == 4)
   {
      int compares = 0;

      cout << endl;
      cout << "Insertion Sort, Random:" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      compares = insertionsort(RandomArray, size);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;
      cout << compares << " Compares" << endl;

      cout << endl;
      cout << "Insertion Sort, Almost Sorted:" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      compares = insertionsort(AlmostSortedArray, size);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;
      cout << compares << " Compares" << endl;

      cout << endl;
      cout << "Insertion Sort, Reverse Sorted:" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      compares = insertionsort(ReverseSortedArray, size);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;
      cout << compares << " Compares" << endl;

      cout << endl;
      cout << "Insertion Sort, Many Duplicates:" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      compares = insertionsort(ManyDuplicatesArray, size);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;
      cout << compares << " Compares" << endl;

   }

   //Merge Sort
   else if (choice == 5)
   {
      int compares = 0;

      cout << endl;
      cout << "Merge Sort, Random:" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      mergesort(RandomArray, size, compares);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;
      cout << compares << " Compares" << endl;

      cout << endl;
      cout << "Merge Sort, Almost Sorted:" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      mergesort(AlmostSortedArray, size, compares);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;
      cout << compares << " Compares" << endl;

      cout << endl;
      cout << "Merge Sort, Reverse Sorted:" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      mergesort(ReverseSortedArray, size, compares);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;
      cout << compares << " Compares" << endl;

      cout << endl;
      cout << "Merge Sort, Many Duplicates:" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      mergesort(ManyDuplicatesArray, size, compares);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;
      cout << compares << " Compares" << endl;
   }

   else if (choice == 6)
   {
     int compares = 0;

      cout << endl;
      cout << "Quick Sort, Random" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      quicksort(0,size,RandomArray,compares);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;
      cout << compares << " Compares" << endl;
     
      cout << endl;
      cout << "Quick Sort, Almost Sorted" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      quicksort(0,size,AlmostSortedArray,compares);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;
      cout << compares << " Compares" << endl;

      cout << endl;
      cout << "Quick Sort, Reverse Sorted" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      quicksort(0,size,ReverseSortedArray,compares);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;
      cout << compares << " Compares" << endl;

      cout << endl;
      cout << "Quick Sort, Many Duplicates" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      quicksort(0,size,ManyDuplicatesArray,compares);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;
      cout << compares << " Compares" << endl;
  }

else if (choice == 7)
{
   int compares = 0;

      cout << endl;
      cout << "Heap Sort, Random:" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      heapSort(RandomArray, size, compares);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;
      cout << compares << " Compares" << endl;

      cout << endl;
      cout << "Heap Sort, Almost Sorted:" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      heapSort(AlmostSortedArray, size, compares);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;
      cout << compares << " Compares" << endl;
      
      cout << endl;
      cout << "Heap Sort, Reverse Sorted:" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      heapSort(ReverseSortedArray, size, compares);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;
      cout << compares << " Compares" << endl;

      cout << endl;
      cout << "Heap Sort, Many Duplicates:" << endl;
      start2 = high_resolution_clock::now(); //clock2 starts
      heapSort(ManyDuplicatesArray, size, compares);
      stop2 = high_resolution_clock::now(); //clock2 stops
      duration2 = duration_cast<milliseconds>(stop2 - start2); //calcs duration the sort ran
      cout << duration2.count() << " Milliseconds" << endl;
      cout << compares << " Compares" << endl;







}

return 0;
}


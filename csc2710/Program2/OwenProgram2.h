
  #include <iostream>
  #include <fstream>
  #include <string>
  #include <iomanip>
  #include <chrono>
  using namespace std;
//////////////////////////////////////////////////////////////////////  
  void heapify(int ary[], int n, int i, int& compare) 
  {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

//  IF Statements find the largest between left and right and **LARGEST IS CHANGED TO THE LOCATION**  
    compare++;
    if (left < n && ary[left] > ary[largest])
    {
      largest = left;
    }
    compare++;
    if (right < n && ary[right] > ary[largest])
    {
      largest = right;
    }
    // Swap and continue heapifying if root is not largest
    compare++;
    if (largest != i) 
    {
      swap(ary[i], ary[largest]);
      heapify(ary, n, largest, compare);
    }
  }
//////////////////////////////////////////////////////////////////////  
// PRIMARY CALL for heapSort
  void heapSort(int ary[], int n, int& compare) 
  {
   // Build max heap
   for (int i = n / 2 - 1; i >= 0; i--)
   {
    heapify(ary, n, i, compare);
   }
 // Heap sort
   for (int i = n - 1; i >= 0; i--) 
   {
    swap(ary[0], ary[i]);
 // Heapify root element to get highest element at root again
    heapify(ary, i, 0, compare);
   }
  }
//////////////////////////////////////////////////////////////////////  









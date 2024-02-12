/*
* Samuel Zito
* 
Sorting is fundamental to implementing solutions in a wide range of problem spaces. 
I would like for youto work in teams of four and implement seven sorting algorithms: selection sort, exchange sort, bubblesort, insertion sort, merge sort, quicksort and heapsort. 
In cases where including a Boolean issortedvariable will improve performance, please do so. I would like for you to generate large datasets to testyour algorithms. 
You can use a random number function to create a dataset or there are many samplesets available online. 
I would like for you to test with four types of datasets: almost sorted, randomlydistributed, reverse sorted and sets with many duplicates. 
For exchange and selection sort, pleasemeasure how many swaps each algorithm performs. 
For all algorithms, I would like for you to measurethe time and number of basic operations (compares) each algorithm takes to sort each dataset.

Selection sort and Insertion sort
*/

#include <iostream>
#include <chrono>

using namespace std::chrono;


void exchangeSort(int size, int array[]) // n is the size of the array, keyType[] is the array 
{
	int count = 0;
	int compCount = 0;
	bool notSorted = true;
	
	while (notSorted) {
		for (int i = 0; i < size; i++) //finds the first spot in array
		{
			notSorted = false;
			for (int j = i + 1; j < size; j++) // finds the second spot in the array
			{
				 //counter to see how many swaps there are
				if (array[i] > array[j]) //compares the first to the second, if the keyType 'i' is less than the keyType 'j' 
				{
					notSorted = true;
					//swaps the variables					 
					swap(array[j], array[i]);
					++count;
				}
				if(notSorted == true)
					++compCount;
			}
		}
		std::cout << "Swap Counter: " << count << std::endl;
		std::cout << "Compare Counter: " << compCount << std::endl;
	}
}


void selectionSort(int array[], int size)
{
	int count = 0;
	int compCount = 0;
	bool notSorted = true;

	while (notSorted) {
		for (int s = 0; s < size - 1; s++)
		{
			notSorted = false;
			int smll = s;
			for (int t = s + 1; t < size; t++)
			{

				// To sort in descending order, change > to < in this line.
				// Select the minimum element in each loop.
				if (array[t] < array[smll])
				{
					notSorted = true;
					smll = t;
				}
				if (notSorted == true)
					++compCount;
			}
			if (notSorted == true)
			{
				// put min at the correct position
				swap(array[smll], array[s]);
				++count;
			}
		}
	}
	std::cout << "Swap Counter: " << count << std::endl;
	std::cout << "Compare Counter: " << compCount << std::endl;
}


//swaps 
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

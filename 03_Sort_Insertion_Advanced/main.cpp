#include <iostream>
#include <string>
#include "Student.h"
#include "SortTestHelper.h"

template<typename T>
void selectionSort(T& arr, int n)
{
	for(int i = 0; i < n; i++)
	{
		int minIndex = i;
		// find the minimal value in the rest array.
		for(int j = i + 1; j < n; j++)
		{
			if(arr[j] < arr[minIndex])
				minIndex = j;
		}
		std::swap(arr[i], arr[minIndex]);
	}
}

template<typename T>
void insertionSort(T& arr, int n)
{
	for (int i = 1; i < n; i++)		
	{	
		// // search forward for a suitable position to insert arr[i]
		// for (int j = i; j < 0; j--)
		// {
		// 	if (arr[j] < arr[j-1])
		// 	{
		// 		std::swap( arr[j], arr[j-1]);
		// 	}
		// 	else
		// 		break;
			
		// }
		
		// put the if condition into the for loop.
		int e = arr[i];
		int j; // j saves the position that the element e should be put.
		for (j = i; j > 0 && arr[j-1] >e; j--)
		{
			arr[j] = arr[j-1];
		}
		arr[j] = e;
	}
	
}


int main()
{	
	int n = 10000;
	int* arr = SortTestHelper::generateRandomArray(n, 0, n);
	int* arr2 = SortTestHelper::copyIntArray(arr, n);

	SortTestHelper::testSort("selectionSort", selectionSort, arr2, n);
	SortTestHelper::testSort("insertionSort", insertionSort, arr, n);
	
	delete[] arr;
	delete[] arr2;
	return 0;
}
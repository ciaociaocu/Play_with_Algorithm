#include <iostream>
#include <string>
#include "Student.h"
#include "SortTestHelper.h"

template<typename T>
void insertionSort(T arr[], int n)
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

// merge both array with range [l, mid] and [mid+1, r].
template<typename T>
void __merge(T arr[], int l, int mid, int r)
{
	T aux[r-l+1];
	for(int i = l; i <= r; i++)
		aux[i-l] = arr[i];

	int i = l, j = mid + 1;
	for(int k = l; k <= r; k++)
	{
		if(i > mid)
		{
			arr[k] = aux[j-l];
			j++;
		}
		else if (j > r)
		{
			arr[k] = aux[i-l];
			i++;
		}
		

		else if(aux[i-l] < aux[j-l])
		{
			arr[k] = aux[i-l];
			i++;
		}
		else
		{
			arr[k] = aux[j-l];
			j++;
		}
	}		
}

// Recursively use __mergeSort to sort the array with the range [l, r]
template<typename T>
void __mergeSort(T arr[], int l, int r)
{
	if(l >= r)
		return;
	
	int mid = (l + r) / 2;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid+1, r);
	__merge(arr, l, mid, r);

}

template<typename T>
void mergeSort(T arr[], int n)
{
	__mergeSort(arr, 0, n-1);
}

int main()
{	
	int n = 10000;
	int swapTimes = 100;

	int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int* arr2 = SortTestHelper::copyIntArray(arr1, n);
	
	std::cout << " random array sort comparision: " << std::endl;
	SortTestHelper::testSort("insertionSort", insertionSort, arr1, n);
	SortTestHelper::testSort("mergeSort", mergeSort, arr2, n);

	delete[] arr1;
	delete[] arr2;

	int* arr3 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	int* arr4 = SortTestHelper::copyIntArray(arr3, n);

	std::cout << " nearly ordered array sort comparision: " << std::endl;
	SortTestHelper::testSort("insertionSort", insertionSort, arr1, n);
	SortTestHelper::testSort("mergeSort", mergeSort, arr2, n);

	delete[] arr3;
	delete[] arr4;
	return 0;
}
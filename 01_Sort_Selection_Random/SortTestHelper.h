#ifndef _SORTTESTHELPER_
#define _SORTTESTHELPER_

#include<iostream>
#include<ctime>
#include<cassert>
#include<string>

namespace SortTestHelper
{
    int* generateRandomArray(int n, int rangeL, int rangeR)
    {
        assert(rangeL <= rangeR);

        int* arr = new int[n];
        srand(time(NULL));
        for(int i = 0; i < n; i ++)
            arr[i] = rand() % (rangeR -rangeL + 1) + rangeL;
        return arr;
    }

    template<typename T>
    void printArray(T& arr, int n)
    {
        for(int i = 0; i < n; i++)
		    std::cout << arr[i] << ' ';
	    std::cout << std::endl;
    }

    template<typename T>
    bool isSorted(T& arr, int n)
    {
        for(int i = 0; i < n - 1; i ++)
        {
            if(arr[i] > arr[i + 1])
                return false;
        }
        return true;
    }

    template<typename T>
    void testSort(std::string sortName, void(*sort)(T&, int), T& arr, int n)
    {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();

        assert(isSorted(arr, n));
        std::cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << std::endl;
    }
} // namespace SortTestHelper


#endif
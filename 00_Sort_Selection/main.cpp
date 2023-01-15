#include <iostream>
#include <string>
#include "Student.h"

template<typename T>
void selectionSort(T arr[], int n)
{
	for(int i = 0; i < n; i++)
	{
		int minIndex = i;
		for(int j = i + 1; j < n; j++)
		{
			if(arr[j] < arr[minIndex])
				minIndex = j;
		}
		std::swap(arr[i], arr[minIndex]);
	}
}
int main()
{	
	int arrayTest[10] = {10,9,8,7,6,5,4,3,2,1};
	selectionSort(arrayTest, 10);
	for(int i = 0; i < 10; i++)
		std::cout << arrayTest[i] << ' ';
	std::cout << std::endl;

	float arrayTest1[10] = {10.1,9.1,8.1,7.1,6.1,5.1,4.1,3.1,2.1,1.1};
	selectionSort(arrayTest1, 10);
	for(int i = 0; i < 10; i++)
		std::cout << arrayTest1[i] << ' ';
	std::cout << std::endl;
	
	std::string stringTest[4] = {"D","C","B","A"};
	selectionSort(stringTest, 4);
	for(int i = 0; i < 4; i++)
		std::cout << stringTest[i] << ' ';
	std::cout << std::endl;
	
	Student student[4] = {{"D",90},{"C",100},{"B",95},{"A",95}};
	selectionSort(student, 4);
	for(int i = 0; i < 4; i++)
		std::cout << student[i];
	std::cout << std::endl;

	std::cout << "Hello!" << std::endl;
}
/* Assignment: 5
Author: Maor Atar, ID: 318301231
*/

#pragma once
#include <iostream>
using namespace std;

template <typename T>
T* Difference(const T arr1[], const T arr2[], const int size1, const int size2) // Function to return the Set of arr1 Difference arr2 (arr1-arr2)
{
	int arr3Size = 0, m = 0;
	bool flag = false;

	for (int i = 0; i < size1; i++) // Outter loop to run all over the arr1 elements
	{
		for (int j = 0; j < size2; j++) // Inner loop to run all over the arr2 elements
		{
			if (arr1[i] == arr2[j]) // Condition to check if 1 pair of the arrays is equal
			{
				flag = true; // If executes flag=true, means that we need to Difference the element
			}
		}
		if (flag == false)
		{
			arr3Size++; // If executes, means that none of the elements in arr2 equal to the ("i") element in the arr1, so we increment the size of the new array
		}
		flag = false; // Initializing 'flag' to false
	}

	T* arr3 = new T[arr3Size]; // Allocates memory to 'arr3' - the Set after the Difference between arr1 and arr2

	for (int i = 0; i < size1; i++) // Outter loop to run all over the arr1 elements
	{
		for (int j = 0; j < size2; j++) // Inner loop to run all over the arr2 elements
		{
			if (arr1[i] == arr2[j]) // Condition to check if 1 pair of the arrays is equal
			{
				flag = true; // If executes flag=true, means that we need to Difference the element
			}
		}
		if (flag == false)
		{
			arr3[m] = arr1[i]; // If executes, means that none of the elements in arr2 equal to the 'arr1' element in the 'i' index, so we store in 'arr3' in the 'm' index the element from 'arr1'
			m++; // Increments 'm' to the next index in 'arr3' array
		}
		flag = false; // Initializing 'flag' to false 
	}

	cout << "*********************************************" << endl;
	cout << "The Array After The Difference: {"; // Loop to print the array after the Difference
	for (int i = 0; i < arr3Size - 1; i++)
	{
		cout << arr3[i] << ",";
	}
	cout << arr3[arr3Size - 1] << "}" << endl;
	cout << "*********************************************" << endl;

	return arr3; // Returns 'arr3' the Set after the Difference between arr1 and arr2
}

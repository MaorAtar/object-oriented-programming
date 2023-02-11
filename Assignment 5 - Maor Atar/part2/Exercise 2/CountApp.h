/* Assignment: 5
Author: Maor Atar, ID: 318301231
*/

#pragma once
#include <iostream>
using namespace std;

template <typename T>
int CountApp(const T arr[], const int size, const T value)
{
	int counter = 0; // Initializing 'counter'

	for (int i = 0; i < size; i++) // Loops thorugh 'arr'
	{
		if (arr[i] == value) // Condition to check if the element from the array is equal to the value
		{
			counter++; // If executes increments 'counter'
		}
	}
	return counter; // Returns 'counter' - the amount of time 'value' appears in 'arr'
}

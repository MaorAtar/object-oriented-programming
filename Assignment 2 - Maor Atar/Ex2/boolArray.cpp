/* Assignment: 2
Author: Maor Atar, ID: 318301231
*/

#include "boolArray.h"
// Customized c'tor:
boolArray::boolArray(int _arrayLength)
{
	initializeArray(_arrayLength); // Uses the assistance function to initialize the array
}
// Assistance function to initialize the array:
void boolArray::initializeArray(int _arrayLength)
{
	if (_arrayLength < 0) // Condition to check for a vaild length
	{
		cout << endl << "---Error---" << endl << "The array length cannot be less than 0" << endl;
	}
	else if (_arrayLength == 0) // Condition to check if the size is 0 and then initilize the array with 0 values
	{
		this->array = NULL;
		this->arrayLength = 0;
	}
	else
	{
		this->array = new bool[_arrayLength]; // Allocates dynamic array memory 

		for (int i = 0; i < _arrayLength; i++) // Loop to initialize the array with "false" values
		{
			array[i] = false;
		}
		this->arrayLength = _arrayLength; // Stores in "arrayLength" the new length
	}
}
// D'tor:
boolArray::~boolArray()
{
	if (this->array) // Condition to check if there are any values in the array to delete
	{
		delete[] this->array; // Deletes the remaining memory allocated in the program
		cout << "boolArray D'tor" << endl; // Message to illustrate the d'tor is working
	}
}
// Function to update the length of the array:
void boolArray::updateArray(int newArrayLength)
{
	if (this->array) // Condition to check if there are any values in the array to delete
	{
		delete[] this->array; // Deletes the previous memory allocated

		initializeArray(newArrayLength);
	}

	initializeArray(newArrayLength); // Uses the assistance function to initialize the new array
}
// Function to get the array values from the user:
void boolArray::getArrayValues() 
{
	int value;

	if (this->array == NULL) // Conditon to check for a vaild array memory
	{
		cout << endl << "---ERROR---" << endl << "The array is empty, cannot store values" << endl;
	}
	else
	{
		cout << "Please enter values to the array: (0 - false, 1 - true)" << endl;

		for (int i = 0; i < this->arrayLength; i++) // Loop to get from the user all the values into the array
		{
			do
			{
				cout << "Enter the #" << i << " value:" << endl;
				cin >> value;
				if (value != 0 && value != 1)
				{
					cout << "---ERROR---" << endl << "Wrong input please try again" << endl;
				}
			} while (value != 0 && value != 1);
			changeArrayValue(value, i); // Uses the "changeArrayValue" to update the values in the array
		}
	}
}
// Assistance function to check for a vaild index:
bool boolArray::indexCheck(int _index) const
{
	if (_index < 0 || _index >= this->arrayLength)
	{
		cout << endl << "---Error---" << endl << "Wrong index input" << endl;
		return false;
	}
	return true;
}
// Function to change value in a specific place in the array: 
void boolArray::changeArrayValue(bool newValue, int _index)
{
	if (indexCheck(_index) == true) // Uses the assistance function to check for a vaild index
	{
		this->array[_index] = newValue; // Updates the array with the new value	
	}
}
// Function to return a value in a specific place in the array:
bool boolArray::returnValue(int _index) const
{
	if (indexCheck(_index) == true) // Uses the assistance function to check for a vaild index
	{
		return this->array[_index]; // return the requested value
	}
}
// Function to print the array:
void boolArray::printArray() const
{
	if (this->array == NULL)
	{
		cout << endl << "---ERROR---" << endl << "The array is empty, cannot print" << endl;
	}
	else
	{
		for (int i = 0; i < this->arrayLength; i++)
		{
			if (this->array[i] == true)
			{
				cout << "T\t";
			}
			else
			{
				cout << "F\t";
			}
		}
		cout << endl;
	}
}
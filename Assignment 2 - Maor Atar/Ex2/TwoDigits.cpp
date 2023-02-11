/* Assignment: 2
Author: Maor Atar, ID: 318301231
*/

#include "TwoDigits.h"
// Customized c'tor:
TwoDigits::TwoDigits(int num)
{
	inputNum(num); // Using the assistance function to update the number in the class
}
// Assistance function:
void TwoDigits::inputNum(int num)
{
	int tempTens, tempUnits;
	
	if (!((num > 9 && num < 100) || (num > -10 && num < -99))) // Condition to check for a vaild number value (2 digits)
	{
		cout << "---ERROR---" << endl << "Not a 2 digits number" << endl;
	}

	tempUnits = num % 10; // Stores in "tempUnits" the units part of the number
	tempTens = num / 10; // Stores in "tempTens" the tens part of the number

	for (int i = 0; i < 10; i++) // Loop to update the the units and tens values in the 2 digit number as required
	{
		if (tempUnits == i) // Condition to check the value of the units (from 1-9)
		{
			this->numUnits = '0' + i; // Updates the units
		}
		if (tempTens == i) // Condition to check the value of the tens (from 1-9)
		{
			this->numTens = '0' + i; // Updates the tens
		}
	}
}
// Customized c'tor:
TwoDigits::TwoDigits(char _numTens, char _numUnits)
{
	this->numUnits = _numUnits; // Updates the units
	this->numTens = _numTens; // Updates the tens
}
// A function to convert the number from char to integer:
int TwoDigits::integerConversion() const
{
	int twoDigitsNum = 0; // initialize "twoDigitsNum" with 0

	for (int i = 0; i < 10; i++) // Loop to update the the units and tens values in the 2 digit number (integer)
	{
		if (i + '0' == this->numUnits) // Condition to check the value of the units (from 1-9)
		{
			twoDigitsNum += i; // Updates the units
		}
		if (i + '0' == this->numTens) // Condition to check the value of the tens (from 1-9)
		{
			twoDigitsNum += i * 10; // Updates the tens
		}
	}
	return twoDigitsNum; // Returns the number after the conversion
}
// Function to change the value of the number:
void TwoDigits::valueChange(int newNum)
{
	inputNum(newNum); // Using the assistance function to update the new number in the class
}
// Function to print the number:
void TwoDigits::printNum() const
{
	cout << numTens << numUnits << endl; // Prints the number in the right order (at the left tens, at the rigth units)
}
// Set function:
void TwoDigits::setNumValues(char _numTens, char _numUnits)
{
	this->numUnits = _numUnits; // Updates the units
	this->numTens = _numTens; // Updates the tens
}

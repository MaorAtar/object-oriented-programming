/* Assignment: 1
Author: Maor Atar, ID: 318301231
*/

#include "CustomString.h"
	// Customized c'tor
CustomString::CustomString(string _str)
{
	int i, counter = 0;
	
	for (i = 0; _str[i] != '\0'; i++)
	{
		counter++;
	}
	this->amountOfChars = counter;
	this->str = new char[amountOfChars];

	for (i = 0; i < amountOfChars; i++)
	{
		str[i] = _str[i];
	}
}
	// Copy c'tor
CustomString::CustomString(const CustomString& otherStr) : amountOfChars(otherStr.amountOfChars)
{
	int i;

	str = new char[amountOfChars];

	for (i = 0; i < otherStr.amountOfChars; i++)
	{
		this->str[i] = otherStr.str[i];
	}
}
	// D'tor
CustomString::~CustomString()
{
	if (str)
	{
		delete[] str;
		cout << endl << "Object deleted!" << endl;
	}
}
	// "Get" functions:
int CustomString::getamountOfChars() const
{
	return this->amountOfChars;
}

char* CustomString::getstr() const
{
	return this->str;
}
	// Mission functions:
void CustomString::changeStr(char* _str, int _amountOfChars)
{
	int i;

	this->amountOfChars = _amountOfChars;
	this->str = new char[amountOfChars];

	for (i = 0; i < amountOfChars; i++)
	{
		str[i] = _str[i];
	}
}
	// Funtcion to print a string:
void CustomString::printStr() const
{
	int i = 0;

	for (i = 0; i < amountOfChars; i++)
	{
		cout << this->str[i];
	}
	cout << endl << "The size of the string: " << amountOfChars;
}
	// Funtcion to calculate the sum of ascii char in the string: 
int CustomString::asciiSum() const
{
	int i, sum = 0;

	for (i = 0; i < amountOfChars; i++)
	{
		sum += str[i];
	}
	return sum;
}
	// Function to convert char array to a string:
string CustomString::convertCharToStr(char* _str) const
{
	int i;
	string newString;

	for (i = 0; str[i] != '\0'; i++)
	{
		newString += str[i];
	}
	return newString;
}
	// Assistance Function (used in "checkPalindrome" function): 
string CustomString::reverseStr(string _str) const
{
	int i;
	string revStr;

	for (i = amountOfChars - 1; i >= 0; i--)
	{
		revStr += _str[i];
	}
	return revStr;
}
	// Funtcion to check if the string is palindrome:
bool CustomString::checkPalindrome() const
{
	int i;
	string _str, temp;
	_str = str;
	temp = reverseStr(_str); // Stores in temp the string in reverse order
	for (i = 0; i < amountOfChars; i++)
	{
		if (_str[i] != temp[i]) // Condition to check if the strings are not equal
		{
			return false;
		}
	}
	return true; // If the condition didn't execute than the string equal to the reversed string (Palindrome)
}
	// Funtcion to check 2 strings are equal:
bool CustomString::checkEqual(CustomString _str) const
{
	int i;

	for (i = 0; i < amountOfChars; i++)
	{
		if (_str.str[i] != this->str[i]) // Condition to check if the strings are not equal
		{
			return false;
		}
	}
	return true; // If the condition didn't execute than the strings equal
}
	// Funtcion to return the char in the index entered:
char CustomString::charPlacement(int index) const
{
	if ((index < 0) || (index > amountOfChars)) // Condition for a wrong input
	{
		cout << "Index out of bounds" << endl;
		return this->str[0]; // If the condition executes than return the first char of the string
	}
	return  this->str[index]; // Returns the required char
}
	// Funtcion to "double" the string:
void CustomString::doubleString()
{
	int i, newAmountOfChars = 2 * amountOfChars;
	string temp;

	for (i = 0; str[i] != '\0'; i++)
	{
		temp += this->str[i]; // Stores in temp the original string
	}

	delete[] str; // Deletes the previous string memorey allocated

	this->str = new char[newAmountOfChars]; // Allocates memorey for the "new" string

	for (i = 0; i < amountOfChars; i++)
	{
		this->str[i] = temp[i]; // Stores in the new string the original string
	}

	for (i = 0; i < amountOfChars; i++)
	{
		str[i + amountOfChars] = str[i]; // Stores the original string again in the new string
	}

	this->amountOfChars = newAmountOfChars; // Stores the new amount of chars in amountOfChars
}
	// Funtcion to remove a specific char from the string:
void CustomString::sub(char ch)
{
	int i, newAmountOfChars = 0;
	string temp;

	for (i = 0; i < amountOfChars; i++)
	{
		if (str[i] != ch)
		{
			temp += str[i]; // Stores in temp the string without the required char
			newAmountOfChars++; // Counts the new amount of chars of the string
		}
	}

	delete[] str; // Deletes the previous string memorey allocated

	this->str = new char[newAmountOfChars]; // Allocates memorey for the "new" string

	for (i = 0; i < newAmountOfChars; i++)
	{
		if (temp[i] != ch)
		{
			str[i] = temp[i]; // Stores in str the string without the required char
		}
	}
	this->amountOfChars = newAmountOfChars; // Updates "amountOfChars" with the new value
}
	// Funtcion to concate 2 strings: 
void CustomString::concatentStr(CustomString _str)
{
	int i, newAmountOfChars;
	string tempStr1, tempStr2, tempConcate;

	newAmountOfChars = amountOfChars + _str.amountOfChars; // Stores the new amount of chars in amountOfChars 

	for (i = 0; i < amountOfChars; i++)
	{
		tempStr1 += str[i]; // Stores in a temporary variable the first string
	}

	for (i = 0; i < _str.amountOfChars; i++)
	{
		tempStr2 += _str.str[i]; // Stores in a temporary variable the second string
	}

	tempConcate = tempStr1 + tempStr2; // Concates the 2 strings and stores it in tempConcate

	this->amountOfChars = newAmountOfChars; // Updates "amountOfChars" with the new value

	delete[] str; // Deletes the previous string memorey allocated

	str = new char[amountOfChars]; // Allocates memorey for the "new" string

	for (i = 0; i < amountOfChars; i++)
	{
		str[i] = tempConcate[i]; // Stores in str the string the concated string
	}
}
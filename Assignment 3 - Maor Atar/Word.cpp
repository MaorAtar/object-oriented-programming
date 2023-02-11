/* Assignment: 3
Author: Maor Atar, ID: 318301231
*/

#include "Word.h"

// -------------------Customized c'tor---------------------
Word::Word(string _word, const int _wordSize)
{
	if (_wordSize < 0) // Condition to check for a vaild word length
	{
		cout << "---ERROR---" << endl << "Invalid word length" << endl;
		exit(1);
	}
	else
	{
		this->wordSize = _wordSize; // Updated "wordSize" with the new size

		word = new char[wordSize]; // Allocates memorey for the word

		for (int i = 0; i < wordSize; i++)
		{
			word[i] = _word[i]; // Updates "word" with the new word
		}
	}
}
// ----------------------Copy c'tor------------------------
Word::Word(const Word& copy) : wordSize(copy.wordSize) // Using inline to update "wordSize"
{
	if (this != &copy) // Condition to check if the objects are not equal
	{
		word = new char[wordSize]; // Allocates memorey for the word

		for (int i = 0; i < wordSize; i++)
		{
			word[i] = copy.word[i]; // Updates "word" with "copy"
		}
	}
	else
	{
		cout << "Same objects" << endl; // Executes if the objects are equal
	}
}
// -------------------------D'tor--------------------------
Word::~Word()
{
	if (word) // Condition to check if the "word" array is not empty (word != NULL)
	{
		delete[] word; // Deletes the allocated memory
	}
}
// -----------------Overloading Functions------------------
// --------------------------------------------------------
Word& Word::operator ! () // Operator to change characters
{
	for (int i = 0; i < wordSize; i++) // Loop to go over all the chars in the "word" array
	{
		if (word[i] >= '0' && word[i] <= '9') // If the char is a number
		{
			word[i] = '9' - word[i] + '0'; // Updates the number with 9's complement
		}
		else if (word[i] >= 'a' && word[i] <= 'z') // If the char is a lower case letter
		{
			word[i] -= 32; // Updates the lower case letter to a capital letter
			word[i] = 'Z' - word[i] + 'A'; // Updates the letter to a "Z" complement
		}
		else if (word[i] >= 'A' && word[i] <= 'Z') // If the char is a capital letter
		{
			word[i] += 32; // Updates the capital letter to a lower case letter
			word[i] = 'z' - word[i] + 'a'; //  Updates the letter to a "z" complement
		}
	}
	return *this; // Returns the object that executed the operator after the change
}
// --------------------------------------------------------
Word& Word::operator & () // Operator to reverse "word"
{
	char* tempWord = new char[wordSize]; // Creates a "tempWord" array

	for (int i = 0; i < wordSize; i++)
	{
		tempWord[i] = word[i]; // Stores in "tempWord" the old word
	}

	for (int j = 0, k = wordSize - 1; j < wordSize; j++, k--) // Loop to reverse the word
	{
		word[j] = tempWord[k]; // Stores in "word" the chars from "tempWord" in a reversed order
	}
	delete[] tempWord; // Deletes the allocated memory for "tempWord"

	return *this; // Returns the object that executed the operator after the change
}
// --------------------------------------------------------
Word& Word::operator << (const int n) // Operator to move chars "n" times to the left
{
	char temp; // Temporary varibale

	for (int i = 0; i < n; i++) // Loop to run "n" times
	{
		temp = word[0]; // Stores in "temp" the first char from "word"
		for (int j = 0; j < wordSize; j++) // Loop to move the chars to the left
		{
			word[j] = word[j + 1]; // Moves chars to the left
		}
		word[wordSize - 1] = temp; // Stores the first char (stored in "temp") in the last char place
	}
	return *this; // Returns the object that executed the operator after the change
}
// --------------------------------------------------------
Word& Word::operator >> (const int n) // Operator to move chars "n" times to the right
{
	char temp; // Temporary varibale

	for (int i = 0; i < n; i++) // Loop to run "n" times
	{
		temp = word[wordSize - 1]; // Stores in "temp" the last char from "word"
		for (int j = wordSize - 1; j >= 0; j--) // Loop to move the chars to the right
		{
			word[j] = word[j - 1]; // Moves chars to the right
		}
		word[0] = temp; // Stores the last char (stored in "temp") in the first char place
	}
	return *this; // Returns the object that executed the operator after the change
}
// --------------------------------------------------------
Word& Word::operator += (const int n) // Operator to add a random char in the "n" index
{
	if (n >= 0 && n <= wordSize) // Condition for a valid index
	{
		this->wordSize++; // Updates "wordSize" +1
		char* tempWord = new char[wordSize]; // Creates a temporary varibale, and allocates memory

		for (int i = 0; i < n; i++) // Loop to stores all the chars from "word" until the "n" index
		{
			tempWord[i] = word[i];
		}

		tempWord[n] = randomChar(); // Stores in "tempWord" at the "n" index a random char using "randomChar" assistance function

		for (int j = n + 1; j < wordSize - 1; j++) // Loop to stores all the remaining chars in "tempWord"
		{
			tempWord[j] = word[j];
		}

		delete[] word; // Deletes the old memory allocated for "word"
		word = new char[wordSize]; // Allocates new memory for "word" with the updated size

		for (int k = 0; k < wordSize - 1; k++) // Loop to update "word" with the new word, using "tempWord"
		{
			word[k] = tempWord[k];
		}
		word[wordSize - 1] = '\0';

		delete[] tempWord; // Deletes the allocated memory for "tempWord"

		return *this; // Returns the object that executed the operator after the change
	}
	else
	{
		cout << "Invalid index entered" << endl; // Executes for invalid index entered
	}
}
// --------------------------------------------------------
Word& Word::operator -= (const int n) // Operator to remove a char from "word" at index "n"
{
	if (n >= 0 && n <= wordSize) // Condition for a valid index
	{
		this->wordSize--; // Updates "wordSize" -1
		char* tempWord = new char[wordSize]; // Creates a temporary varibale, and allocates memory

		for (int i = 0; i < n; i++) // Loop to stores all the chars from "word" until the "n" index
		{
			tempWord[i] = word[i];
		}
		for (int j = n; j < wordSize; j++) // Loop to stores all the remaining chars in "tempWord"
		{
			tempWord[j] = word[j + 1];
		}

		delete[] word; // Deletes the old memory allocated for "word"
		word = new char[wordSize]; // Allocates new memory for "word" with the updated size

		for (int k = 0; k < wordSize; k++) // Loop to update "word" without the word, using "tempWord"
		{
			word[k] = tempWord[k];
		}
		delete[] tempWord; // Deletes the allocated memory for "tempWord"

		return *this; // Returns the object that executed the operator after the change
	}
	else
	{
		cout << "Invalid index entered" << endl; // Executes for invalid index entered
	}
}
// --------------------------------------------------------
char& Word::operator [] (const int index) // Operator that returns a char from a required index, and also gives the ability to change a char in a specific placement 
{
	if (index >= 0 && index <= wordSize) // Condition for a valid index
	{
		return word[index]; // Returns the char in the required placement
	}
	else
	{
		cout << "Out of boundary of the array" << endl; // Executes for invalid index entered
		return word[0]; // Reutrns the first char from "word"
	}
}
// --------------------------------------------------------
ostream& operator << (ostream& output, const Word& _word) // Operator to print "word"
{
	for (int i = 0; i < _word.wordSize; i++)
	{
		output << _word.word[i];
	}
	return output; // Returns the output to print
}
// ------------------Assistance Function--------------------
// --------------------------------------------------------
char Word::randomChar() const // Function to draw a random capital letter
{
	char randomChar = (char)(rand() % 26 + 65); // Range 'A' - 'Z'

	return randomChar; // Returns the random char
}
// --------------------------------------------------------

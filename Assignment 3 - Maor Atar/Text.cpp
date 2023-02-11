/* Assignment: 3
Author: Maor Atar, ID: 318301231
*/

#include "Text.h"

// -------------------Default c'tor---------------------
Text::Text() : amountOfWords(5)
{
	text = new Word * [amountOfWords];
	text[0] = new Word("one", 3);
	text[1] = new Word("two", 3);
	text[2] = new Word("three", 5);
	text[3] = new Word("four", 4);
	text[4] = new Word("five", 4);
}
// -------------------Customized c'tor---------------------
Text::Text(string _text)
{
	int tempWordSize, index = 0, j;
	string tempStr; // Temporary varible to store each word

	this->amountOfWords = wordsCounter(_text); // Using the "wordsCounter" assistance funcion to store in "amountOfWords" the amount of words in the sentence

	text = new Word * [amountOfWords]; // Allocates memorey for the sentence

	for (int i = 0; i < amountOfWords; i++) // Loop through all the words in the sentence
	{
		tempWordSize = 0; // Initializing "tempWordSize" with each inner loop
		j = index; // Initializing "j" with the updated index with each inner loop
		while (_text[j] != ' ' && _text[j] != '\n' && _text[j] != '\0') // Inner loop through each word separately
		{
			tempWordSize++; // Updates "tempWordSize" +1
			tempStr += _text[j]; // Stores in "tempStr" each word separately
			index++; // Increments "index"
			j++; // Increment "j"
		}
		index++; // Increments "index"
		text[i] = new Word(tempStr, tempWordSize); // Updates "text" with each word separately
		tempStr.clear(); // Clears the temporary varible "tempStr" that used to store each word
	}
}
// ----------------------Copy c'tor------------------------
Text::Text(const Text& copy) : amountOfWords(copy.amountOfWords) // Using inline to update "amountOfWords"
{
	if (this != &copy) // Condition to check if the objects are not equal
	{
		this->text = new Word * [amountOfWords]; // Allocates memorey for the sentence
		for (int i = 0; i < amountOfWords; i++)
		{
			text[i] = copy.text[i]; // Updates "text" with "copy"
		}
	}
	else
	{
		cout << "Same objects" << endl; // Executes if the objects are equal
	}
}
// -------------------------D'tor--------------------------
Text::~Text()
{
	if (text) // Condition to check if the "text" array is not empty (text != NULL)
	{
		delete[] text; // Deletes the allocated memory
	}
}
// ----------------------Get Function----------------------
// --------------------------------------------------------
Word& Text::getText(const int index)
{
	return *text[index]; // Returns the word in the required index
}
// -----------------Overloading Functions------------------
// --------------------------------------------------------
Text& Text::operator ! () // Operator to change characters in the text
{
	for (int i = 0; i < amountOfWords; i++) // Loop goes all over the words in the text separately
	{
		!(*text[i]); // Changes characters for each word in the text separately
	}
	return *this; // Returns the object that executed the operator after the change
}
// --------------------------------------------------------
Text& Text::operator & () // Operator to reverse "text"
{
	Word* temp; // Temporary varible to store each word of "text"
	int lastWordIndex = amountOfWords - 1;

	for (int i = 0; i <= lastWordIndex / 2; i++) // Loop to go to the "middle" of the sentence and switches the "end" words of the sentence with "start" words of the sentence
	{
		temp = text[i]; // Stores in "temp" the "start" words
		text[i] = text[lastWordIndex - i]; // Switches the words
		text[lastWordIndex - i] = temp; // Switches the words
	}

	return *this; // Returns the object that executed the operator after the change
}
// --------------------------------------------------------
Text& Text::operator << (const int n) // Operator to move words "n" times to the left
{
	if (n >= 0 && n <= amountOfWords) // Condition for a valid index
	{
		Word* temp; // Temporary varible

		for (int i = 0; i < n; i++) // Loop to run "n" times
		{
			temp = text[0]; // Stores in "temp" the first word from "text"
			for (int j = 0; j < amountOfWords; j++) // Loop to move the words to the left
			{
				text[j] = text[j + 1]; // Moves words to the left
			}
			text[amountOfWords - 1] = temp; // Stores the first word (stored in "temp") in the last word place
		}
	}
	else
	{
		cout << "Invalid index entered" << endl; // Executes for invalid index entered
	}
	return *this;  // Returns the object that executed the operator after the change
}
// --------------------------------------------------------
Text& Text::operator >> (const int n) // Operator to move words "n" times to the right
{
	if (n >= 0 && n <= amountOfWords) // Condition for a valid index
	{
		Word* temp; // Temporary varibale

		for (int i = 0; i < n; i++) // Loop to run "n" times
		{
			temp = text[amountOfWords - 1]; // Stores in "temp" the last word from "text"
			for (int j = amountOfWords - 1; j >= 0; j--) // Loop to move the words to the right
			{
				text[j] = text[j - 1]; // Moves words to the right
			}
			text[0] = temp; // Stores the last word (stored in "temp") in the first word place
		}
	}
	else
	{
		cout << "Invalid index entered" << endl; // Executes for invalid index entered
	}

	return *this; // Returns the object that executed the operator after the change
}
// --------------------------------------------------------
Text& Text::operator += (const int n) // Operator to add a random word in the "n" index
{
	if (n >= 0 && n <= amountOfWords) // Condition for a valid index
	{
		this->amountOfWords++; // Updates "amountOfWords" +1
		Word** tempText = new Word * [amountOfWords]; // Creates a temporary varibale, and allocates memory
		int randomSize = (int)(rand() % 5 + 3); // Creates a random size (Range 3 - 7)

		for (int i = 0; i < n; i++) // Loop to stores all the words from "text" until the "n" index
		{
			tempText[i] = text[i];
		}

		tempText[n] = new Word(randomWord(randomSize), randomSize); // Stores in "tempText" at the "n" index a random word using "randomWord" assistance function

		for (int j = n; j < amountOfWords; j++) // Loop to stores all the remaining words in "tempText"
		{
			tempText[j + 1] = text[j];
		}

		delete[] text; // Deletes the old memory allocated for "text"
		text = new Word * [amountOfWords]; // Allocates new memory for "text" with the updated size

		for (int k = 0; k < amountOfWords; k++) // Loop to update "text" with the new word, using "tempText"
		{
			text[k] = tempText[k];
		}

		delete[] tempText; // Deletes the allocated memory for "tempText"

		return *this; // Returns the object that executed the operator after the change
	}
	else
	{
		cout << "Invalid index entered" << endl; // Executes for invalid index entered
	}
}
// --------------------------------------------------------
Text& Text::operator -= (const int n) // Operator to remove a word from "text" at index "n"
{
	if (n >= 0 && n <= amountOfWords) // Condition for a valid index
	{
		this->amountOfWords--; // Updates "amountOfWords" -1
		Word** tempText = new Word * [amountOfWords]; // Creates a temporary varibale, and allocates memory

		for (int i = 0; i < n; i++) // Loop to stores all the words from "text" until the "n" index
		{
			tempText[i] = text[i];
		}

		for (int j = n; j < amountOfWords; j++) // Loop to stores all the remaining words in "tempText"
		{
			tempText[j] = text[j + 1];
		}

		delete[] text; // Deletes the old memory allocated for "text"
		text = new Word * [amountOfWords]; // Allocates new memory for "text" with the updated size

		for (int k = 0; k < amountOfWords; k++) // Loop to update "text" without the word, using "tempText"
		{
			text[k] = tempText[k];
		}

		delete[] tempText; // Deletes the allocated memory for "tempText"

		return *this; // Returns the object that executed the operator after the change
	}
	else
	{
		cout << "Invalid index entered" << endl; // Executes for invalid index entered
	}
}
// --------------------------------------------------------
Word& Text::operator [] (const int index) const // Operator that returns a word from a required index, and also gives the ability to change a char in a specific placement in the word
{
	if (index >= 0 && index <= amountOfWords) // Condition for a valid index
	{
		return *text[index]; // Returns the word in the required placement
	}
	else
	{
		cout << "Out of boundary of the array" << endl; // Executes for invalid index entered
		return *text[0]; // Reutrns the first word from "text"
	}
}
// --------------------------------------------------------
ostream& operator << (ostream& output, const Text& _text) // Operator to print "text"
{
	for (int i = 0; i < _text.amountOfWords; i++)
	{
		output << *_text.text[i] << ' ';
	}
	return output; // Returns the output to print
}
// ------------------Assistance Functions--------------------
// --------------------------------------------------------
char* Text::randomWord(const int randomSize) const // Function to draw a random word
{
	char* randomWord = new char[randomSize]; // Allocates memory for "randomWord"

	for (int i = 0; i < randomSize; i++) // Loop to create the random word
	{
		randomWord[i] = (char)(rand() % 26 + 65); // Range 'A' - 'Z'
	}
	return randomWord; // Returns the random word
}
// --------------------------------------------------------
int Text::wordsCounter(string str) const // Function to count the amount of words in a sentence
{
	int amountOfWords = 0, flag = 0, i = 0;

	while (str[i]) // Loops until '\0'
	{
		if (str[i] == ' ' || str[i] == '\n') // Condition to cout word
		{
			flag = 0; // Means that word need to be counted
		}
		else if (flag == 0) // If flag has changed before to zero
		{
			flag = 1; // Changes flag to '1' means that no word need to be counted
			amountOfWords++; // Counts word
		}
		i++; // Increments i
	}
	return amountOfWords; // Returns the amount of words in the sentence
}
// --------------------------------------------------------
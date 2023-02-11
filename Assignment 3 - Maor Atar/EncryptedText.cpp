/* Assignment: 3
Author: Maor Atar, ID: 318301231
*/

#include "EncryptedText.h"

// -------------------Default c'tor---------------------
EncryptedText::EncryptedText() : encryptedText(NULL), key(NULL), status(0), keySize(0)
{
	encryptedText = new Text("one two three four five");
}
// -------------------Customized c'tor---------------------
EncryptedText::EncryptedText(string _encryptedText, int _status) : status(_status), key(NULL), keySize(0) // Using inline to update "status", and initializing "key" and "keySize"
{
	encryptedText = new Text(_encryptedText); // Updates "encryptedText" with the text required
}
// -------------------------D'tor--------------------------
EncryptedText::~EncryptedText()
{
	if (encryptedText) // Condition to check if the "encryptedText" array is not empty (text != NULL)
	{
		delete encryptedText; // Deletes the allocated memory
	}
	if (key) // Condition to check if the "key" array is not empty (text != NULL)
	{
		delete[] key; // Deletes the allocated memory
	}
}
// -----------------Overloading Functions------------------
// --------------------------------------------------------
EncryptedText& EncryptedText::operator += (int* _key) // Operator to update "key"
{
	this->keySize = 0; // Initializing "keySize"

	for (int i = 0; _key[i] != -2; i++) // Loop to go until reachs "-2" (end of the key)
	{
		keySize++; // Updates "keySize" +1
	}

	this->key = new int[keySize]; // Allocates memory for key with the updated "keySize"

	for (int j = 0; j < keySize; j++) // Loop to store in "key" the operations from "_key"
	{
		key[j] = _key[j];
	}
	return *this; // Returns the object that executed the operator after the change
}
// --------------------------------------------------------
EncryptedText& EncryptedText::operator ! () // Operator to encrypt a text
{
	for (int i = 0; i < keySize; i += 3) // Loops throgh the key
	{
		int operationCode = this->key[i]; // Stores in "operationCode" the code from "key[i]"
		if (key[i + 1] == -1) // Condition if the user want to encrypt the whole sentence
		{
			for (int j = 0; j < encryptedText->getamountOfWords(); j++) // Loops throgh the whole text
			{
				switch (operationCode) // Using "switch-case" technique to encrypt
				{
				case 1:
					*encryptedText << key[i + 2]; // Moves the whole text to the left
					break;
				case 2:
					*encryptedText >> key[i + 2]; // Moves the whole text to the right
					break;
				case 3:
					*encryptedText += key[i + 2]; // Adds a random word in the requested index
					break;
				case 4:
					!(encryptedText->getText(j)); // Changes the words in the whole text
					continue;
				case 5:
					&(*encryptedText); // Reverses the whole text
					break;
				default:
					break;
				}
				break;
			}
		}
		else // Condition if the user want to encrypt a word
		{
			switch (operationCode) // Using "switch-case" technique to encrypt
			{
			case 1:
				encryptedText->getText(key[i + 1]) << key[i + 2]; // Moves the word to the left
				break;
			case 2:
				encryptedText->getText(key[i + 1]) >> key[i + 2]; // Moves the word to the right
				break;
			case 3:
				*encryptedText += key[i + 2]; // Adds a random word in the requested index
				break;
			case 4:
				!(encryptedText->getText(key[i + 1])); // Changes the word in the requested index
				continue;
			case 5:
				&(encryptedText->getText(key[i + 1])); // Reverses the word in the requested index
				break;
			default:
				break;
			}
		}
	}
	return *this; // Returns the object that executed the operator after the change
}
// --------------------------------------------------------
EncryptedText& EncryptedText::operator & () // Operator to decrypt a text
{
	for (int i = keySize - 1; i >= 0; i -= 3) // Loops throgh the key
	{
		int operationCode = this->key[i - 2]; // Stores in "operationCode" the code from "key[i - 2]"
		if (key[i - 1] == -1)  // Condition if the user want to decrypt the whole sentence
		{
			for (int j = 0; j < encryptedText->getamountOfWords(); j++) // Loops throgh the whole text
			{
				switch (operationCode) // Using "switch-case" technique to decrypt
				{
				case 1:
					*encryptedText >> key[i]; // Moves the whole text to the right
					break;
				case 2:
					*encryptedText << key[i]; // Moves the whole text to the left
					break;
				case 3:
					*encryptedText -= key[i]; // Removes a word in a requested index
					break;
				case 4:
					!(encryptedText->getText(j)); // Changes the words in the whole text 
					continue;
				case 5:
					&(*encryptedText); // Reverses the whole text
					break;
				default:
					break;
				}
				break;
			}
		}
		else // Condition if the user want to decrypt a word
		{
			switch (operationCode) // Using "switch-case" technique to decrypt
			{
			case 1:
				encryptedText->getText(key[i - 1]) >> key[i]; // Moves the word to the right
				continue;
			case 2:
				encryptedText->getText(key[i - 1]) << key[i]; // Moves the word to the left
				continue;
			case 3:
				*encryptedText -= key[i]; // Removes a word in a requested index
				continue;
			case 4:
				!(encryptedText->getText(key[i - 1])); // Changes the word in the requested index
				continue;
			case 5:
				&(encryptedText->getText(key[i - 1])); // Reverses the word in the requested index
				continue;
			default:
				break;
			}
		}
	}
	return *this; // Returns the object that executed the operator after the change
}
// --------------------------------------------------------
ostream& operator << (ostream& output, const EncryptedText& _encryptedText) // Operator to print the encrypted\decrypted text
{
	if (_encryptedText.status == 0 && _encryptedText.key == NULL) // First condition decrypted text
	{
		output << "The decrypted text: " << *_encryptedText.encryptedText << endl;
		output << "The key: empty" << endl;
	}
	else if (_encryptedText.status == 1 && _encryptedText.key == NULL) // Second condition decrypted text
	{
		output << "The decrypted text: " << *_encryptedText.encryptedText << endl;
		output << "The key: empty" << endl;
	}
	else // Executes for encrypted text
	{
		output << "The encrypted text: " << *_encryptedText.encryptedText << endl;
		output << "The key: " << endl;
		for (int i = 0; i < _encryptedText.keySize; i += 3)
		{
			output << _encryptedText.key[i] << " " << _encryptedText.key[i + 1] << " " << _encryptedText.key[i + 2] << endl;
		}
	}
	output << endl;
	return output; // Returns the output to print
}
// --------------------------------------------------------
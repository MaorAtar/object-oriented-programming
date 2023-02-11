/* Assignment: 3
Author: Maor Atar, ID: 318301231
*/

#include "EncryptedText.h"

int main() {
	srand(time(NULL));

	cout << "-----------------'Word' class check------------------" << endl;
	// --------------------------------------------------------
	Word w1("abcdef", 6), w2("ABCDEF", 6), w3(w1); // Varibales to check the functions from the "Word" class
	cout << "***Prints the objects***" << endl; // Check for the customized c'tor and the print function
	cout << "First object: " << w1 << endl;
	cout << "Second object: " << w2 << endl;
	cout << "Third object: " << w3 << endl; // Check for the copy c'tor

	// -----------------Overloading Functions Check------------------
	cout << "***Operator !***" << endl;
	!w1;
	!w2;
	cout << "First object: " << w1 << endl;
	cout << "Second object: " << w2 << endl;

	cout << "***Operator &***" << endl;
	&w1;
	&w2;
	cout << "First object: " << w1 << endl;
	cout << "Second object: " << w2 << endl;

	cout << "***Operator -=***" << endl;
	w1 -= 1;
	w2 -= 2;
	cout << "First object: " << w1 << endl;
	cout << "Second object: " << w2 << endl;

	cout << "***Operator +=***" << endl;
	w1 += 0;
	w2 += 3;
	cout << "First object: " << w1 << endl;
	cout << "Second object: " << w2 << endl;

	cout << "***Operator >>***" << endl;
	w1 >> 2;
	w2 >> 1;
	cout << "First object: " << w1 << endl;
	cout << "Second object: " << w2 << endl;

	cout << "***Operator <<***" << endl;
	w1 << 4;
	w2 << 3;
	cout << "First object: " << w1 << endl;
	cout << "Second object: " << w2 << endl;

	cout << "***Operator []***" << endl;
	w1[0] = 'x';
	w2[7] = 'A'; // Check for invalid length
	cout << "First object: " << w1 << endl;
	cout << "Second object: " << w2 << endl;
	// --------------------------------------------------------
	cout << "-----------------'Text' class check------------------" << endl;
	Text text1("one two three four five"), text2, text3(text1);  // Varibales to check the functions from the "Text" class
	cout << "***Prints the objects***" << endl; // Check for the customized c'tor and the print function
	cout << "First object: " << text1 << endl;
	cout << "Second object: " << text2 << endl;
	cout << "Third object: " << text3 << endl; // Check for the copy c'tor
	// -----------------Overloading Functions Check------------------
	cout << "***Operator !***" << endl;
	!text1;
	cout << "First object: " << text1 << endl;

	cout << "***Operator &***" << endl;
	&text1;
	&text2;
	cout << "First object: " << text1 << endl;
	cout << "Second object: " << text2 << endl;

	cout << "***Operator <<***" << endl;
	text1 << 3;
	text2 << 2;
	cout << "First object: " << text1 << endl;
	cout << "Second object: " << text2 << endl;

	cout << "***Operator >>***" << endl;
	text1 >> 2;
	text2 >> 3;
	cout << "First object: " << text1 << endl;
	cout << "Second object: " << text2 << endl;

	cout << "***Operator +=***" << endl;
	text1 += 2;
	text2 += 1;
	cout << "First object: " << text1 << endl;
	cout << "Second object: " << text2 << endl;

	cout << "***Operator -=***" << endl;
	text1 -= 1;
	text2 -= 3;
	cout << "First object: " << text1 << endl;
	cout << "Second object: " << text2 << endl;

	cout << "***Operator []***" << endl;
	text2[2][3] = 'A';
	cout << "First object: " << text1[0] << endl;
	cout << "Second object: " << text2 << endl;
	// --------------------------------------------------------
	cout << "-----------------'EncryptedText' class check------------------" << endl;
	EncryptedText etext1("The London is capital of Great Britian.", 0), etext2("RH oLMWLM gSV yIRGRZM. tIVZG LU 3eCQ GZOXZKR", 1), etext3; // Varibales to check the functions from the "EncryptedText" class
	int key1[] = { 3, -1, 4, 1, -1, 3, 1, 0, 4, 4, -1, 0, 5, -1, 0, -2 }; // Varible "key" from the assignment example
	cout << "***Prints the objects***" << endl; // Check for the customized c'tor and the print function
	cout << "First object: " << etext1 << endl;
	cout << "Second object: " << etext2 << endl;
	cout << "Third object: " << etext3 << endl; // Check for the default c'tor
	// -----------------Overloading Functions Check------------------
	cout << "***Operator +=***" << endl;
	etext1 += key1;
	cout << etext1;
	etext2 += key1;
	cout << etext2;
	cout << "***Operator !***" << endl;
	cout << "First object: " << !etext1;
	cout << "----------------------------------------------------------" << endl;
	cout << "***Operator &***" << endl;
	&etext2;
	cout << "Second object: " << etext2;

	return 0;
}
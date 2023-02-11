/* Assignment: 3
Author: Maor Atar, ID: 318301231
*/

#include "Word.h"

class Text {
private:
	Word** text;
	unsigned int amountOfWords;
	char* randomWord(const int) const; // Assistance function
	int wordsCounter(string) const; // Assistance function

public:
	Text(); // Default c'tor
	Text(const string); // Customized c'tor
	Text(const Text&); // Copy c'tor
	~Text(); // D'tor
	// Get Functions:
	int getamountOfWords() { return amountOfWords; }; // Returns the "amountOfWords"
	Word& getText(const int);
	// Overloading Functions:
	Text& operator ! ();
	Text& operator & ();
	Text& operator << (const int);
	Text& operator >> (const int);
	Text& operator += (const int);
	Text& operator -= (const int);
	Word& operator [] (const int) const;
	friend ostream& operator << (ostream&, const Text&);
};
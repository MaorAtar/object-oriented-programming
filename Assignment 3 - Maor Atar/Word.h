/* Assignment: 3
Author: Maor Atar, ID: 318301231
*/

#include <iostream>
#include <time.h>

using namespace std;

class Word {
private:
	char* word;
	unsigned int wordSize;
	char randomChar() const; // Assistance function

public:
	Word() : word(NULL), wordSize(0) {}; // Default c'tor initializing word and size
	Word(const string, const int); // Customized c'tor
	Word(const Word&); // Copy c'tor
	~Word(); // D'tor
	// Overloading Functions:
	Word& operator ! ();
	Word& operator & ();
	Word& operator << (const int);
	Word& operator >> (const int);
	Word& operator += (const int);
	Word& operator -= (const int);
	char& operator [] (const int);
	friend ostream& operator << (ostream&, const Word&);
};
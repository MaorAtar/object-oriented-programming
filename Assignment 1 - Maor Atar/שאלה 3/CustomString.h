/* Assignment: 1
Author: Maor Atar, ID: 318301231
*/

#include <iostream>

using namespace std;

class CustomString
{
private:
	int amountOfChars;
	char* str;
	string reverseStr(string _str) const;  // Assistance  Function (used in "checkPalindrome" function)

public:
	CustomString() : amountOfChars(0), str(NULL) {};  // Default c'tor
	CustomString(string _str); // Customized c'tor
	CustomString(const CustomString& otherStr); // Copy c'tor
	~CustomString(); // D'tor
	// "Get" functions:
	int getamountOfChars() const;
	char* getstr() const;
	// Mission functions:
	void changeStr(char* _str, int _amountOfChars); // Section 6
	void printStr() const; // Section 7
	int asciiSum() const; // Section 8
	string convertCharToStr(char* _str) const; // Section 9
	bool checkPalindrome() const;  // Section 10
	bool checkEqual(CustomString _str) const; // Section 11
	char charPlacement(int index) const; // Section 12
	void doubleString(); // Section 13
	void sub(char ch); // Section 14
	void concatentStr(CustomString _str); // Section 15
};

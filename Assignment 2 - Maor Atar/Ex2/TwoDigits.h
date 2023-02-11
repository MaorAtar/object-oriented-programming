/* Assignment: 2
Author: Maor Atar, ID: 318301231
*/

#include <iostream>

using namespace std;

class TwoDigits
{
private:
	char numUnits;
	char numTens;
	void inputNum(int); // Assistance function

public:
	TwoDigits() : numUnits('0'), numTens('0') {}; // Default c'tor initialized with "00"
	TwoDigits(int); // Customized c'tor
	TwoDigits(char, char); // Customized c'tor
	~TwoDigits() { cout << "TwoDigits D'tor" << endl; }; // D'tor, message to illustrate the d'tor is working
	// Methods:
	int integerConversion() const;
	void valueChange(int);
	void printNum() const;
	void setNumValues(char, char);
};

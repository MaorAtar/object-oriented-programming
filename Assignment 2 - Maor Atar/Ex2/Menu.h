/* Assignment: 2
Author: Maor Atar, ID: 318301231
*/

#include "TwoDigits.h"
#include "boolArray.h"

class Menu
{
private:
	TwoDigits num1;
	TwoDigits num2;
	boolArray arr;

public:
	Menu() {}; // Default c'tor
	// Methods:
	void mainMenu();
	void TwoDigitsMethod();
	void BoolArrayMethod();
	~Menu() { cout << "Menu D'tor" << endl; }; // D'tor, message to illustrate the d'tor is working
};

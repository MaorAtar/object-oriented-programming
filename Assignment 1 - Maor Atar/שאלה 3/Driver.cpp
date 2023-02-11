/* Assignment: 1
Author: Maor Atar, ID: 318301231
*/

#include "CustomString.h"

int main() {
	string _str1, _str2, _str3;
	int index;
	char tempChar;

	cout << "Enter a string: " << endl;
	cin >> _str1;

	CustomString str1(_str1); // "Creates" first string

	// Check for all the class functions as required:
	cout << "Ascii value: " << str1.asciiSum() << endl;

	cout << "Is palindrome?";
	if (str1.checkPalindrome() == true)
	{
		cout << " Yes" << endl;
	}
	else
	{
		cout << " No" << endl;
	}

	cout << "Enter a string to check equalty: " << endl;
	cin >> _str2;
	cout << "Is equal to " << "'" << _str2 << "'?";
	if (str1.checkEqual(_str2) == true)
	{
		cout << " Yes" << endl;
	}
	else
	{
		cout << " No" << endl;
	}

	cout << "Double string: ";
	str1.doubleString();
	str1.printStr();
	cout << endl;

	cout << "Enter an index number to check: " << endl;
	cin >> index;
	tempChar = str1.charPlacement(index);
	cout << "Char at index " << index << ": " << tempChar << endl;
	cout << "The string without " << "'" << tempChar << "': " << endl;
	str1.sub(tempChar);
	str1.printStr();
	cout << endl;

	cout << "Enter a string to concatenate: " << endl;
	cin >> _str3;

	CustomString str2(_str3); // "Creates" second string

	cout << "Concatenated string ('" << _str3 << "'): ";
	str1.concatentStr(str2);
	str1.printStr();
	cout << endl;

	return 0;
}
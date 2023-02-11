/* Assignment: 5
Author: Maor Atar, ID: 318301231
*/

#include "Difference.h"

int main() {
	float arr1[6] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 }, arr2[5] = { 1.1, 7.7, 9.9, 2.2, 3.3 };
	int size1 = 6, size2 = 5;

	cout << "---------------------------------------------" << endl; // Prints the first array
	cout << "The First Array: {";
	for (int i = 0; i < 5; i++)
	{
		cout << arr1[i] << ",";
	}
	cout << arr1[5] << "}" << endl;
	cout << "---------------------------------------------" << endl; // Prints the second array
	cout << "The Second Array: {";
	for (int i = 0; i < 4; i++)
	{
		cout << arr2[i] << ",";
	}
	cout << arr2[4] << "}" << endl;
	cout << "---------------------------------------------" << endl;

	Difference(arr1, arr2, size1, size2); // Executes the Template Function - 'Difference'

	return 0;
}
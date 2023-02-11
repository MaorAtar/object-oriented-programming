/* Assignment: 5
Author: Maor Atar, ID: 318301231
*/

#include "CountApp.h"

int main() {
	long arr[5] = { 157,237,10,40,10 }, value = 10;
	int amountOfApp;

	cout << "--------------------------------" << endl; // Prints the array
	cout << "The array: { ";
	for (int i = 0; i < 4; i++)
	{
		cout << arr[i] << ",";
	}
	cout << arr[4] << " }" << endl;

	amountOfApp = CountApp(arr, 5, value); // Executes the Template Function - 'CountApp'

	cout << "--------------------------------" << endl;
	cout << value << " Appears in the array: " << amountOfApp << " times" << endl; // Prints the amount of times 'value' appears in 'arr'
	cout << "--------------------------------" << endl;

	return 0;
}
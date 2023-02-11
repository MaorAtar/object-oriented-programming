/* Assignment: 2
Author: Maor Atar, ID: 318301231
*/

#include "Menu.h"
// Function for the main menu:
void Menu::mainMenu()
{
	int choice;

	do
	{
		// Prints the main menu options:
		cout << "Menu:" << endl;
		cout << "1.TwoDigits menu" << endl;
		cout << "2.boolArray menu" << endl;
		cout << "3.Exit" << endl;
		cout << "Please enter your choice from the menu:" << endl;
		cin >> choice;
		if (choice == 1) // If executes goes to the "TwoDigit" menu
		{
			TwoDigitsMethod();
		}
		if (choice == 2) // If executes goes to the "BoolArray" menu
		{
			BoolArrayMethod();
		}
		if (choice != 1 && choice != 2 && choice != 3) // Condition for a wrong input (not between 1-3)
		{
			cout << "---ERROR---" << endl << "Wrong input please try again" << endl;
		}
	} while (choice != 3); // Condition to loop until the user enters exit value

	cout << "Goodbye" << endl;
}
// Function for the "TwoDigits" menu:
void Menu::TwoDigitsMethod()
{
	char num1Units, num1Tens;
	int num2Value, choice, tempNum1Units, tempNum1Tens;

	do
	{
		cout << "Please enter the unitsDigit char (number between 0-9):" << endl;
		cin >> tempNum1Units;
		num1Units = tempNum1Units;
	} while (tempNum1Units > 9 || tempNum1Units < -9); // Condition to keep asking from the user (in a case a wrong input entered)
	
	do
	{
		cout << "Please enter the tensDigit char (number between 1-9):" << endl;
		cin >> tempNum1Tens;
		num1Tens = tempNum1Tens;
	} while (tempNum1Tens == 0 || tempNum1Tens > 9 || tempNum1Tens < -9); // Condition to keep asking from the user (in a case a wrong input entered)

	this->num1.setNumValues(num1Tens, num1Units); // Sets the num1 variable (from the private field) using the "setNumValues" function

	do
	{
		cout << "Enter integer number: " << endl;
		cin >> num2Value;
	} while (!((num2Value > 9 && num2Value < 100) || (num2Value > -10 && num2Value < -99))); // Condition to keep asking from the user (in a case a wrong input entered)

	this->num2.valueChange(num2Value); // Sets the num2 variable (from the private field) using the "valueChange" function
	
	do
	{
		// Prints the "TwoDigits" menu options:
		cout << "Menu:" << endl;
		cout << "1.Updating Object by int" << endl;
		cout << "2.Sum Objects" << endl;
		cout << "3.Prints the Object" << endl;
		cout << "4.Exit" << endl;
		cout << "Please enter your choice from the menu:" << endl;
		cin >> choice;
		if (choice == 1) // If executes updates the Object with integer value
		{
			int newNum;

			cout << "Please enter the new value: " << endl;
			cin >> newNum;
			this->num1.valueChange(newNum);
		}
		if (choice == 2) // If executes sums the 2 numbers
		{
			int sum = 0, tempNum1, tempNum2;

			tempNum1 = this->num1.integerConversion();
			tempNum2 = this->num2.integerConversion();
			sum = tempNum1 + tempNum2;

			cout << "The sum of " << tempNum1 << "+" << tempNum2 << " is: " << sum << endl;
		}
		if (choice == 3) // If executes prints the 2 numbers
		{
			cout << "First two digit number: ";
			this->num1.printNum();
			cout << "Second two digit number: ";
			this->num2.printNum();
		}
		if (choice != 1 && choice != 2 && choice != 3 && choice != 4) // Condition for a wrong input (not between 1-4)
		{
			cout << "---ERROR---" << endl << "Wrong input please try again" << endl;
		}
	} while (choice != 4); // Condition to loop until the user enters exit value
}

void Menu::BoolArrayMethod()
{
	int choice;

	do
	{
		// Prints the "BoolArray" menu options:
		cout << "Menu:" << endl;
		cout << "1.Update the size of the array" << endl;
		cout << "2.Update the values of the array" << endl;
		cout << "3.Change the value in the array" << endl;
		cout << "4.Get value from the array" << endl;
		cout << "5.Print the array" << endl;
		cout << "6.Exit" << endl;
		cout << "Please enter your choice from the menu:" << endl;
		cin >> choice;
		if (choice == 1) // If executes updates the array size
		{
			int newSize;

			cout << "Please enter the new size of the array: " << endl;
			cin >> newSize;

			this->arr.updateArray(newSize);
		}
		if (choice == 2) // If executes gets array values
		{
			this->arr.getArrayValues();
		}
		if (choice == 3) // If executes changes value in a required location
		{
			int index;
			bool value;

			cout << "Enter the location (integer) of the value you want to cheange: " << endl;
			cin >> index;
			cout << "Please enter 1 for true or 0 for false: " << endl;
			cin >> value;

			this->arr.changeArrayValue(value, index);
		}
		if (choice == 4) // If executes gets the value in the required location
		{
			int index, value;

			cout << "Please enter the location of the value: " << endl;
			cin >> index;
			value = this->arr.returnValue(index);
			cout << "The value in index " << index << " is: ";
			if (this->arr.returnValue(index) == 1)
			{
				cout << "True" << endl;
			}
			else
			{
				cout << "False" << endl;
			}
		}
		if (choice == 5) // If executes prints the array elements
		{
			this->arr.printArray();
		}
		if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6) // Condition for a wrong input (not between 1-6)
		{
			cout << "---ERROR---" << endl << "Wrong input please try again" << endl;
		}
	} while (choice != 6); // Condition to loop until the user enters exit value
}

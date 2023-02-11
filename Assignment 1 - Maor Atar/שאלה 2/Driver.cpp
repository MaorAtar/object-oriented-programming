/* Assignment: 1
Author: Maor Atar, ID: 318301231
*/

#include "Student.h"

int main() {
	char firstStudName[MAX_WORD_LENGTH], secondStudName[MAX_WORD_LENGTH], firstStudID[MAX_ID_LENGTH], secondStudID[MAX_ID_LENGTH], scholarshipChoice;
	int numofyears, numofcourses, i, k;
	bool scholarship;
	Student firstStud, secondStud; // "Creates 2 students"

	// Gets all the details of the first student:
	cout << "****Input - First Student Details****" << endl;
	cout << "Enter Name: ";
	cin.getline(firstStudName, MAX_WORD_LENGTH);
	cout << endl << "Enter ID: ";
	cin >> firstStudID;
	cout << endl << "Years of study: ";
	cin >> numofyears;
	do
	{
		cout << endl << "Scholarship (Y/N): ";
		cin >> scholarshipChoice;
	} while (scholarshipChoice != 'Y' && scholarshipChoice != 'N');
	if (scholarshipChoice == 'Y')
	{
		scholarship = true;
	}
	else
	{
		scholarship = false;
	}
	cout << endl << "Number of courses studied: ";
	cin >> numofcourses;
	cout << endl;

	if (numofcourses < 1 || numofyears < 1) // Condition for a wrong input/the student don't have any completed courses
	{
		// Builds the first student class:
		firstStud.setfullName(firstStudName);
		firstStud.setidNumber(firstStudID);
		firstStud.setnumOfYears(numofyears);
		firstStud.setnumOfCourses(numofcourses);
		firstStud.setscholarship(scholarship);

		cout << "****Output - First Student Details****" << endl;
		firstStud.showDetails(); // Prints all the student details (using the "showDetails" function from Student class)
	}
	else
	{
		char** coursesNames1 = NULL;
		int* grades1 = NULL;

		coursesNames1 = new char* [numofcourses];
		for (i = 0; i < numofcourses; i++)
		{
			coursesNames1[i] = new char[MAX_WORD_LENGTH];
		}

		grades1 = new int[numofcourses];

		k = 0;

		for (i = 0; i < numofcourses; i++)
		{
			cout << "Enter #" << i + 1 << " course name: " << endl;
			if (i == k) // Condition to cin a string with spaces
			{
				cin.ignore();
				k++;
			}
			cin.getline(coursesNames1[i], MAX_WORD_LENGTH);
			cout << "Enter #" << i + 1 << " course grade: " << endl;
			cin >> grades1[i];
		}
		// Builds the first student class:
		firstStud.setfullName(firstStudName);
		firstStud.setidNumber(firstStudID);
		firstStud.setnumOfYears(numofyears);
		firstStud.setnumOfCourses(numofcourses);
		firstStud.setCourses(numofcourses, grades1, coursesNames1);
		firstStud.setscholarship(scholarship);

		cout << "****Output - First Student Details****" << endl;
		firstStud.showDetails(); // Prints all the first student details (using the "showDetails" function from Student class)
		cout << endl;
	}



	// Gets all the details of the second student:
	cout << "****Input - Second Student Details****" << endl;
	cout << "Enter Name: ";
	cin.ignore();
	cin.getline(secondStudName, MAX_WORD_LENGTH);
	cout << endl << "Enter ID: ";
	cin >> secondStudID;
	cout << endl << "Years of study: ";
	cin >> numofyears;
	do
	{
		cout << endl << "Scholarship (Y/N): ";
		cin >> scholarshipChoice;
	} while (scholarshipChoice != 'Y' && scholarshipChoice != 'N');
	if (scholarshipChoice == 'Y')
	{
		scholarship = true;
	}
	else
	{
		scholarship = false;
	}
	cout << endl << "Number of courses studied: ";
	cin >> numofcourses;
	cout << endl;

	if (numofcourses < 1 || numofyears < 1) // Condition for a wrong input/the student don't have any completed courses
	{
		// Builds the second student class:
		secondStud.setfullName(secondStudName);
		secondStud.setidNumber(secondStudID);
		secondStud.setnumOfYears(numofyears);
		secondStud.setnumOfCourses(numofcourses);
		secondStud.setscholarship(scholarship);

		cout << "****Output - Second Student Details****" << endl;
		secondStud.showDetails(); // Prints all the student details (using the "showDetails" function from Student class)
	}
	else
	{
		char** coursesNames2 = NULL;
		int* grades2 = NULL;

		coursesNames2 = new char* [numofcourses];
		for (i = 0; i < numofcourses; i++)
		{
			coursesNames2[i] = new char[MAX_WORD_LENGTH];
		}

		grades2 = new int[numofcourses];

		k = 0;

		for (i = 0; i < numofcourses; i++)
		{
			cout << "Enter #" << i + 1 << " course name: " << endl;
			if (i == k) // Condition to cin a string with spaces
			{
				cin.ignore();
				k++;
			}
			cin.getline(coursesNames2[i], MAX_WORD_LENGTH);
			cout << "Enter #" << i + 1 << " course grade: " << endl;
			cin >> grades2[i];
		}
		// Builds the second student class:
		secondStud.setfullName(secondStudName);
		secondStud.setidNumber(secondStudID);
		secondStud.setnumOfYears(numofyears);
		secondStud.setnumOfCourses(numofcourses);
		secondStud.setCourses(numofcourses, grades2, coursesNames2);
		secondStud.setscholarship(scholarship);

		cout << "****Output - Second Student Details****" << endl;
		secondStud.showDetails(); // Prints all the first student details (using the "showDetails" function from Student class)
		cout << endl;
	}

	return 0;
}
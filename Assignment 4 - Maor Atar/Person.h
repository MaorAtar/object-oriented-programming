/* Assignment: 4
Author: Maor Atar, ID: 318301231
*/

#pragma once
#include <iostream>

using namespace std;

class Person
{
protected:
	string firstName;
	string lastName;

public:
	Person() : firstName("None"), lastName("None") {}; // Default c'tor
	Person(const string, const string); // Customized c'tor
	Person(const Person&); // Copy c'tor
	virtual ~Person() { cout << "Deleting Person: " << firstName << " " << lastName << endl; }; // D'tor

	// Class Methods:
	virtual void printPerson() const; // Virtual function to print the Person (Used in the in inheritors)
	string getFirstName() const; // Function to get the Persons first name
	string getLastName() const; // Function to get the Persons last name
};


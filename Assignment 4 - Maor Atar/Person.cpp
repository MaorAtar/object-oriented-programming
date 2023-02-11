/* Assignment: 4
Author: Maor Atar, ID: 318301231
*/

#include "Person.h"

// -------------------Customized c'tor---------------------
Person::Person(const string _firstName, const string _lastName) : firstName(_firstName), lastName(_lastName) {}
// ----------------------Copy c'tor------------------------
Person::Person(const Person& copy)
{
	if (this != &copy)
	{
		this->firstName = copy.firstName;
		this->lastName = copy.lastName;
	}
	else
	{
		cout << "Same objects" << endl; // Executes if the objects are equal
	}
}
// ---------------------Class Methods----------------------
// --------------------------------------------------------
void Person::printPerson() const
{
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
}
// --------------------------------------------------------
string Person::getFirstName() const
{
	return this->firstName;
}
// --------------------------------------------------------
string Person::getLastName() const
{
	return this->lastName;
}
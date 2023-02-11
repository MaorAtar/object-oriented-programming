/* Assignment: 4
Author: Maor Atar, ID: 318301231
*/

#pragma once
#include "Person.h"
#include "Client.h"
#include "Project.h"

class Seller : public Person
{
private:
	Project* projectsArr;
	Client** clientsArr;
	int amountOfClients;

public:
	Seller() : Person(), projectsArr(NULL), clientsArr(NULL), amountOfClients(0) {}; // Default c'tor
	Seller(const string, const string, Project*, Client**, const int); // Customized c'tor
	Seller(const Seller&); // Copy c'tor
	~Seller(); // D'tor

	// Class Methods:
	int sellerSalary() const; // Function to return the Seller salary
	void printPerson() const; // Function to print the Seller (inheritor from Person)
	int getAmountApartSold(int) const; // Function to return the amount of Apartments sold by the Seller
	void addClient(Client*); // Function to add a Client to the Seller Clients
};


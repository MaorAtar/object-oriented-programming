/* Assignment: 4
Author: Maor Atar, ID: 318301231
*/

#pragma once
#include <typeinfo>
#include "Person.h"
#include "Date.h"
#include "StandardApartment.h"
#include "GardenApartment.h"
#include "PenthouseApartment.h"

class Client : public Person
{
private:
	static int clientNumber;
	int budget;
	Apartment** apartmentArr;
	Date** purchaseDateArr;
	int amountOfApartPurc;

public:
	Client(); // Default c'tor
	Client(const string, const string, int, Apartment**, Date**, int); // Customized c'tor
	Client(const Client&); // Copy c'tor
	~Client(); // D'tor

	// Class Methods:
	int* propertyTax(); // Function to calculate the Property Tax for every Apartment the Client bought
	void printPerson() const; // Function from 'Person' to print the Client details
	int getPurchaseMonth(int) const; // Function to return the purchase date the Apartment bought
	Apartment* getApartment(int) const; // Function to return Apartment in a specific index
	int getAmountOfApartPurc() const; // Function to get the amount of Apartments bought by the Client
	int getClientNumber() const; // Function to get the Client Number
	int getBudget() const; // Function to get the Client budget
	void addApartment(Apartment*); // Function to add Apartment
	void addDate(Date*); // Function to add Date
};


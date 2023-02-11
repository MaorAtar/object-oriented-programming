/* Assignment: 4
Author: Maor Atar, ID: 318301231
*/

#pragma once
#include <typeinfo>
#include "Seller.h"

class HomeMarket
{
private:
	Person** personArr;
	Apartment** apartmentArr;
	Project** projectArr;
	int amountOfPersons;
	int amountOfApartments;
	int amountOfProjects;

public:
	HomeMarket(); // Default c'tor
	virtual ~HomeMarket(); // D'tor

	// Class Methods:
	bool Menu(); // Function to manage the 'Home Market' - Menu
	void printStandardBuyers() const; // Function to print the buyers that bought Standard Apartments
	bool addBuilding(); // Function to add a Building
	bool addProject(); // Function to add a Project
	bool addSeller(); // Function to add a Seller
	bool addClient(); // Function to add a Client
	bool printApartment() const; // Function to print Apartment using an Apartment Number, and Building address
	bool printStandardApartBalconys() const; // Function to print available Standard Apartements that has 2 balconys
	bool printSellerSalary() const; // Function to print Seller salary using first and last name
	bool printSuitedClientApart() const; // Function to print available Apartments, that are suited for the Clients requirements 
	bool printPenthouseApart() const; // Function to print Penhouse Apartments deatils in a specific Project
	bool apartmentSell() const; // Function to Sell Apartment
	bool lowestPropertyTax(); // Function to print the Client deatils with the lowest Property Tax 
};


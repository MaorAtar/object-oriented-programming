/* Assignment: 4
Author: Maor Atar, ID: 318301231
*/

#pragma once
#include <iostream>
#include <typeinfo> // Using RTTI
#include "Apartment.h"
#include "StandardApartment.h"
#include "GardenApartment.h"
#include "PenthouseApartment.h"

using namespace std;

class Building
{
private:
	string address;
	int amountOfFloors;
	Apartment** apartmentArr;

public:
	Building() : address("None"), amountOfFloors(0), apartmentArr(NULL) {}; // Default c'tor
	Building(string, const int, Apartment**); // Customized c'tor
	Building(const Building&); // Copy c'tor
	virtual ~Building(); // D'tor

	// Class Methods:
	int getAmountOfApartments() const; // Function to get the amount of Apartments in the Building
	bool printBulidingAprt(); // Function to print all the Apartments deatils in the Building
	string getAddress() const; // Function to get the Building address
	bool printPenthouseApart(); // Function to print Penthouse Apartments in the Building
};


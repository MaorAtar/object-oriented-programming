/* Assignment: 4
Author: Maor Atar, ID: 318301231
*/

#pragma once
#include "Apartment.h"

class PenthouseApartment : public Apartment
{
private:
	int balconySize;

public:
	PenthouseApartment() : Apartment(), balconySize(0) {}; // Default c'tor
	PenthouseApartment(const int, const int, const int, const bool, const int); // Customized c'tor
	PenthouseApartment(const PenthouseApartment&); // Copy c'tor
	~PenthouseApartment() { cout << "Deleting Penthouse Apartment #" << apartmentNum << endl; }; // D'tor

	// Class Methods:
	int getApartmentPrice(); // Function to calculate the Apartment price
	void printApartment(); // Function to print the Penthouse Apartment
};


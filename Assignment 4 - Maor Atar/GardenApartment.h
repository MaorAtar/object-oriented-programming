/* Assignment: 4
Author: Maor Atar, ID: 318301231
*/

#pragma once
#include "Apartment.h"

class GardenApartment : public Apartment
{
private:
	int gardenArea;
	bool poolStatus;

public:
	GardenApartment() : Apartment(), gardenArea(0), poolStatus(false) {}; // Default c'tor
	GardenApartment(const int, const int, const int, const bool, const int, const bool); // Customized c'tor
	GardenApartment(const GardenApartment&); // Copy c'tor
	~GardenApartment() { cout << "Deleting Garden Apartment #" << apartmentNum << endl; }; // D'tor

	// Class Methods:
	int getApartmentPrice(); // Function to calculate the Apartment price
	void printApartment(); // Function to print the Garden Apartment
};


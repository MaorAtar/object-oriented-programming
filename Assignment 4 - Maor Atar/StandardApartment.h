/* Assignment: 4
Author: Maor Atar, ID: 318301231
*/

#pragma once
#include "Apartment.h"

class StandardApartment : public Apartment
{
private:
	int amountOfBalconys;
	int* balconysSizeArr;

public:
	StandardApartment() : Apartment(), amountOfBalconys(0), balconysSizeArr(NULL) {}; // Default c'tor
	StandardApartment(const int, const int, const int, const bool, const int, int*); // Customized c'tor
	StandardApartment(const StandardApartment&); // Copy c'tor
	~StandardApartment(); // D'tor

	// Class Methods:
	int getApartmentPrice(); // Function to calculate the Apartment price
	void printApartment(); // Function to print the Garden Apartment
	int getAmountOfBalconys() const; // Function to get the amount of balconys the Standard Apartment have
};


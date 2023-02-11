/* Assignment: 4
Author: Maor Atar, ID: 318301231
*/

#pragma once
#include <iostream>

using namespace std;

class Apartment
{
protected:
	int apartmentNum;
	int floor;
	int apartmentArea;
	bool apartmentStatus;

public:
	Apartment() : apartmentNum(0), floor(0), apartmentArea(0), apartmentStatus(0) {}; // Default c'tor
	Apartment(const int, const int, const int, const bool); // Customized c'tor
	Apartment(const Apartment&); // Copy c'tor
	virtual ~Apartment() { cout << "Deleting Apartment #" << apartmentNum << endl; }; // D'tor

	// Class Methods:
	virtual int getApartmentPrice() = 0; // Pure Virtual function (Used in the in inheritors)
	virtual void printApartment(); // Virtual function to print the Apartment (Used in the in inheritors)
	int getApartmentArea() const; // Function to return the Apartment area
	int getApartmentNum() const; // Function to return the Apartment number
	bool getApartmentStatus() const; // Function to get the Apartment status (sold\for sale)
	void setApartmentStatus(const bool); // Function to set the Apartment status
};


/* Assignment: 4
Author: Maor Atar, ID: 318301231
*/

#include "Building.h"

// -------------------Customized c'tor---------------------
Building::Building(string _address, const int _amountOfFloors, Apartment** _apartmentArr) :address(_address), amountOfFloors(_amountOfFloors)
{
	int size = getAmountOfApartments();
	apartmentArr = new Apartment * [size];
	for (int i = 0; i < size; i++)
	{
		apartmentArr[i] = _apartmentArr[i];
	}
}
// ----------------------Copy c'tor------------------------
Building::Building(const Building& copy)
{
	if (this != &copy)
	{
		this->address = copy.address;
		this->amountOfFloors = copy.amountOfFloors;

		int getAmountOfApartments = (amountOfFloors * 2) - 2;
		apartmentArr = new Apartment * [getAmountOfApartments];
		for (int i = 0; i < getAmountOfApartments; i++)
		{
			apartmentArr[i] = copy.apartmentArr[i];
		}
	}
	else
	{
		cout << "Same objects" << endl; // Executes if the objects are equal
	}
}
// ------------------------D'tor---------------------------
Building::~Building()
{
	if (apartmentArr)
	{
		delete apartmentArr;
	}
	cout << "Deleting Building" << endl;
}
// ---------------------Class Methods----------------------
// --------------------------------------------------------
int Building::getAmountOfApartments() const
{
	return (amountOfFloors * 2) - 2;
}
// --------------------------------------------------------
bool Building::printBulidingAprt()
{
	int size = getAmountOfApartments();

	cout << "-----Building Details-----" << endl;
	if (apartmentArr == NULL)
	{
		cout << "No Apartments in the building" << endl;
		return false;
	}

	for (int i = 0; i < size; i++)
	{
		GardenApartment* tempGardenApart = dynamic_cast<GardenApartment*>(apartmentArr[i]); // Using RTTI to check for a Garden Apartment
		if (tempGardenApart)
		{
			tempGardenApart->printApartment(); // Using the Garden Apartment - 'printApartment' function
		}

		StandardApartment* tempStanardApart = dynamic_cast<StandardApartment*>(apartmentArr[i]); // Using RTTI to check for a Standard Apartment
		if (tempStanardApart)
		{
			tempStanardApart->printApartment(); // Using the Standard Apartment - 'printApartment' function
		}

		PenthouseApartment* tempPenthouseApart = dynamic_cast<PenthouseApartment*>(apartmentArr[i]); // Using RTTI to check for a Penthouse Apartment
		if (tempPenthouseApart)
		{
			tempPenthouseApart->printApartment(); // Using the Penthouse Apartment - 'printApartment' function
		}
	}
	return true;
}
// --------------------------------------------------------
string Building::getAddress() const
{
	return this->address;
}
// --------------------------------------------------------
bool Building::printPenthouseApart()
{
	int size = getAmountOfApartments(); // Stores in 'size' the amount of Apartments in the Building

	cout << "-----Building Details-----" << endl;
	if (apartmentArr == NULL)
	{
		cout << "No Apartments in the building" << endl;
		return false;
	}

	for (int i = 0; i < size; i++)
	{
		PenthouseApartment* tempPenthouseApart = dynamic_cast<PenthouseApartment*>(apartmentArr[i]); // Using RTTI to check for a Penthouse Apartment
		if (tempPenthouseApart)
		{
			tempPenthouseApart->printApartment(); // Using the Penthouse Apartment - 'printApartment' function
		}
	}
	return true;
}
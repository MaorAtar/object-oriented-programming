/* Assignment: 4
Author: Maor Atar, ID: 318301231
*/

#include "GardenApartment.h"

// -------------------Customized c'tor---------------------
GardenApartment::GardenApartment(const int _apartmentNum, const int _floor, const int _apartmentArea, const bool _apartmentStatus, const int _gardenArea, const bool _poolStatus) : Apartment(_apartmentNum, _floor, _apartmentArea, _apartmentStatus), gardenArea(_gardenArea), poolStatus(_poolStatus) {}
// ----------------------Copy c'tor------------------------
GardenApartment::GardenApartment(const GardenApartment& copy) : Apartment(copy)
{
	if (this != &copy)
	{
		this->gardenArea = copy.gardenArea;
		this->poolStatus = copy.poolStatus;
	}
	else
	{
		cout << "Same objects" << endl; // Executes if the objects are equal
	}
}
// ---------------------Class Methods----------------------
// --------------------------------------------------------
int GardenApartment::getApartmentPrice()
{
	if (poolStatus == true) // Returns the Garden Apartment price if the Apartment has a pool
	{
		return 600000 + (apartmentArea * 600) + 100000;
	}
	else // Returns the Garden Apartment price if the Apartment dosen't have a pool
	{
		return 600000 + (apartmentArea * 600);
	}
}
// --------------------------------------------------------
void GardenApartment::printApartment()
{
	cout << "-----Garden Apartment Details-----" << endl;
	Apartment::printApartment();
	cout << "Garden Area: " << gardenArea << endl;
	if (poolStatus == true)
	{
		cout << "Pool: Yes" << endl;
	}
	else
	{
		cout << "Pool: No" << endl;
	}
	cout << "Apartment Price: " << getApartmentPrice() << endl;
}
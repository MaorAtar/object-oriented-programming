/* Assignment: 4
Author: Maor Atar, ID: 318301231
*/

#include "Apartment.h"

// -------------------Customized c'tor---------------------
Apartment::Apartment(const int _apartmentNum, const int _floor, const int _apartmentArea, const bool _apartmentStatus) : apartmentNum(_apartmentNum), floor(_floor), apartmentArea(_apartmentArea), apartmentStatus(_apartmentStatus) {}
// ----------------------Copy c'tor------------------------
Apartment::Apartment(const Apartment& copy)
{
	if (this != &copy)
	{
		this->apartmentNum = copy.apartmentNum;
		this->floor = copy.floor;
		this->apartmentArea = copy.apartmentArea;
		this->apartmentStatus = copy.apartmentStatus;
	}
	else
	{
		cout << "Same objects" << endl; // Executes if the objects are equal
	}
}
// ---------------------Class Methods----------------------
// --------------------------------------------------------
void Apartment::printApartment()
{
	cout << "Apartment Number: " << apartmentNum << endl;
	cout << "Apartment Floor: " << floor << endl;
	cout << "Apartment Area: " << apartmentArea << endl;
	if (apartmentStatus == true)
	{
		cout << "Apartment Status: Sold!" << endl;
	}
	else
	{
		cout << "Apartment Status: For Sale!" << endl;
	}
}
// --------------------------------------------------------
int Apartment::getApartmentArea() const
{
	return this->apartmentArea;
}
// --------------------------------------------------------
int Apartment::getApartmentNum() const
{
	return this->apartmentNum;
}
// --------------------------------------------------------
bool Apartment::getApartmentStatus() const
{
	return this->apartmentStatus;
}
// --------------------------------------------------------
void Apartment::setApartmentStatus(const bool status)
{
	this->apartmentStatus = status;
}
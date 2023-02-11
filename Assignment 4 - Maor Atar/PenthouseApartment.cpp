/* Assignment: 4
Author: Maor Atar, ID: 318301231
*/

#include "PenthouseApartment.h"

// -------------------Customized c'tor---------------------
PenthouseApartment::PenthouseApartment(const int _apartmentNum, const int _floor, const int _apartmentArea, const bool _apartmentStatus, const int _balconySize) : Apartment(_apartmentNum, _floor, _apartmentArea, _apartmentStatus), balconySize(_balconySize) {}
// ----------------------Copy c'tor------------------------
PenthouseApartment::PenthouseApartment(const PenthouseApartment& copy) : Apartment(copy)
{
	if (this != &copy)
	{
		this->balconySize = copy.balconySize;
	}
	else
	{
		cout << "Same objects" << endl; // Executes if the objects are equal
	}
}
// ---------------------Class Methods----------------------
// --------------------------------------------------------
int PenthouseApartment::getApartmentPrice()
{
	return 700000 + (apartmentArea * 600) + (balconySize * 200);
}
// --------------------------------------------------------
void PenthouseApartment::printApartment()
{
	cout << "-----Penthouse Apartment Details-----" << endl;
	Apartment::printApartment();
	cout << "Balcony Size: " << balconySize << endl;
	cout << "Apartment Price: " << getApartmentPrice() << endl;
}

/* Assignment: 4
Author: Maor Atar, ID: 318301231
*/

#include "StandardApartment.h"

// -------------------Customized c'tor---------------------
StandardApartment::StandardApartment(const int _apartmentNum, const int _floor, const int _apartmentArea, const bool _apartmentStatus, const int _amountOfBalconys, int* _balconysSizeArr) : Apartment(_apartmentNum, _floor, _apartmentArea, _apartmentStatus), amountOfBalconys(_amountOfBalconys)
{
	if (amountOfBalconys > 2)
	{
		cout << "Error - Maximum 2 balconys" << endl;
		this->amountOfBalconys = 0;
		this->balconysSizeArr = NULL;
	}
	else
	{
		this->balconysSizeArr = new int[amountOfBalconys];
		for (int i = 0; i < amountOfBalconys; i++)
		{
			balconysSizeArr[i] = _balconysSizeArr[i];
		}
	}
}
// ----------------------Copy c'tor------------------------
StandardApartment::StandardApartment(const StandardApartment& copy) : Apartment(copy)
{
	if (this != &copy)
	{
		this->amountOfBalconys = copy.amountOfBalconys;
		this->balconysSizeArr = new int[amountOfBalconys];
		for (int i = 0; i < amountOfBalconys; i++)
		{
			balconysSizeArr[i] = copy.balconysSizeArr[i];
		}
	}
	else
	{
		cout << "Same objects" << endl; // Executes if the objects are equal
	}
}
// ------------------------D'tor---------------------------
StandardApartment::~StandardApartment()
{
	if (balconysSizeArr)
	{
		delete[] balconysSizeArr;
	}
	cout << "Deleting Standard Apartment #" << apartmentNum << endl;
}
// ---------------------Class Methods----------------------
// --------------------------------------------------------
int StandardApartment::getApartmentPrice()
{
	return 300000 + (amountOfBalconys * 12000) + (floor * 300) + (apartmentArea * 500);
}
// --------------------------------------------------------
void StandardApartment::printApartment()
{
	cout << "-----Standard Apartment Details-----" << endl;
	Apartment::printApartment();
	cout << "Amount Of Balconys: " << amountOfBalconys << endl;
	for (int i = 0; i < amountOfBalconys; i++)
	{
		cout << "#" << i + 1 << " Balcony Size: " << balconysSizeArr[i] << endl;
	}
	cout << "Apartment Price: " << getApartmentPrice() << endl;
}
// --------------------------------------------------------
int StandardApartment::getAmountOfBalconys() const
{
	return this->amountOfBalconys;
}
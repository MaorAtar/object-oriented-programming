/* Assignment: 4
Author: Maor Atar, ID: 318301231
*/

#include "Client.h"

int Client::clientNumber = 0; // Static counter
// -------------------Default c'tor---------------------
Client::Client() : Person(), budget(0), apartmentArr(NULL), purchaseDateArr(NULL), amountOfApartPurc(0)
{
	this->clientNumber++;
}
// -------------------Customized c'tor---------------------
Client::Client(const string _firstName, const string _lastName, int _budget, Apartment** _apartmentArr, Date** _purchaseDateArr, int _amountOfApartPurc) : Person(_firstName, _lastName), budget(_budget), amountOfApartPurc(_amountOfApartPurc)
{
	this->clientNumber++;
	this->apartmentArr = new Apartment * [amountOfApartPurc];
	for (int i = 0; i < amountOfApartPurc; i++)
	{
		apartmentArr[i] = _apartmentArr[i];
	}

	this->purchaseDateArr = new Date * [amountOfApartPurc];
	for (int i = 0; i < amountOfApartPurc; i++)
	{
		purchaseDateArr[i] = _purchaseDateArr[i];
	}
}
// ----------------------Copy c'tor------------------------
Client::Client(const Client& copy) : Person(copy)
{
	if (this != &copy)
	{
		this->budget = copy.budget;
		this->amountOfApartPurc = copy.amountOfApartPurc;
		this->clientNumber++;

		this->apartmentArr = new Apartment * [amountOfApartPurc];
		for (int i = 0; i < amountOfApartPurc; i++)
		{
			apartmentArr[i] = copy.apartmentArr[i];
		}

		this->purchaseDateArr = new Date * [amountOfApartPurc];
		for (int i = 0; i < amountOfApartPurc; i++)
		{
			purchaseDateArr[i] = copy.purchaseDateArr[i];
		}
	}
	else
	{
		cout << "Same objects" << endl; // Executes if the objects are equal
	}
}
// ---------------------------D'tor------------------------
Client::~Client()
{
	if (apartmentArr)
	{
		for (int i = 0; i < amountOfApartPurc; i++)
		{
			delete apartmentArr[i];
		}
		delete[] apartmentArr;
	}

	if (purchaseDateArr)
	{
		for (int i = 0; i < amountOfApartPurc; i++)
		{
			delete purchaseDateArr[i];
		}
		delete[] purchaseDateArr;
	}

	cout << "Deleting Client" << endl;
}
// ---------------------Class Methods----------------------
// --------------------------------------------------------
int* Client::propertyTax()
{
	int* propertyTaxArr = new int[amountOfApartPurc];
	int x, y, z;

	if (amountOfApartPurc == 0) // Condition for a Client that didn't buy Apartments
	{
		propertyTaxArr = NULL;
		return propertyTaxArr; // Return the Property Tax array
	}
	else
	{
		for (int i = 0; i < amountOfApartPurc; i++) // Loops through the Apartments bought by the Client array
		{
			// Using RTTI to find the required Apartment type
			StandardApartment* tempStanardApart = dynamic_cast<StandardApartment*>(apartmentArr[i]);
			if (tempStanardApart)
			{
				if (tempStanardApart->getAmountOfBalconys() == 2) // First condition for Standard Apartment
				{
					x = 0, y = 1, z = tempStanardApart->getApartmentArea();
					propertyTaxArr[i] = (x * 120) + (y * 300) + (z * 25);
				}
				else // Second condition for Standard Apartment
				{
					x = 0, y = 0, z = tempStanardApart->getApartmentArea();
					propertyTaxArr[i] = (x * 120) + (y * 300) + (z * 25);
				}
			}

			GardenApartment* tempGardenApart = dynamic_cast<GardenApartment*>(apartmentArr[i]);
			if (tempGardenApart)
			{
				x = 2, y = 0, z = tempGardenApart->getApartmentArea();
				propertyTaxArr[i] = (x * 120) + (y * 300) + (z * 25);
			}

			PenthouseApartment* tempPenthouseApart = dynamic_cast<PenthouseApartment*>(apartmentArr[i]);
			if (tempPenthouseApart)
			{
				x = 1, y = 0, z = tempPenthouseApart->getApartmentArea();
				propertyTaxArr[i] = (x * 120) + (y * 300) + (z * 25);
			}
		}
		return propertyTaxArr; // Return the Property Tax array
	}
}
// --------------------------------------------------------
void Client::printPerson() const
{
	cout << "-----Client Details-----" << endl;
	Person::printPerson();
	cout << "Client Number: " << clientNumber << endl;
	cout << "Client Budget: " << budget << endl;
	cout << "Amount of apartments purchased: " << amountOfApartPurc << endl;
	for (int i = 0; i < amountOfApartPurc; i++)
	{
		cout << "Apartment #" << i + 1 << endl;
		apartmentArr[i]->printApartment();
		purchaseDateArr[i]->printDate();
	}
}
// --------------------------------------------------------
int Client::getPurchaseMonth(int index) const
{
	return this->purchaseDateArr[index]->getMonth();
}
// --------------------------------------------------------
Apartment* Client::getApartment(int index) const
{
	return apartmentArr[index];
}
// --------------------------------------------------------
int Client::getAmountOfApartPurc() const
{
	return this->amountOfApartPurc;
}
// --------------------------------------------------------
int Client::getClientNumber() const
{
	return this->clientNumber;
}
// --------------------------------------------------------
int Client::getBudget() const
{
	return this->budget;
}
// --------------------------------------------------------
void Client::addApartment(Apartment* objectApartment)
{
	this->amountOfApartPurc++; // Incremants the 'amountOfApartPurc' by 1

	Apartment** tempApartmentArr = new Apartment * [amountOfApartPurc]; // Using a temp Apartment array
	for (int i = 0; i < amountOfApartPurc - 1; i++)
	{
		tempApartmentArr[i] = apartmentArr[i]; // Stores in the temp array the previous data from the original array
	}
	tempApartmentArr[amountOfApartPurc - 1] = objectApartment; // Stores in the last place in the temp array the new Apartment

	delete apartmentArr; // Deletes the previous 'apartmentArr' data

	apartmentArr = tempApartmentArr; // 'apartmentArr' points to the temp array address
}
// --------------------------------------------------------
void Client::addDate(Date* object)
{
	Date** tempDateArr = new Date * [amountOfApartPurc]; // Using a temp Date array
	for (int i = 0; i < amountOfApartPurc; i++)
	{
		tempDateArr[i] = purchaseDateArr[i]; // Stores in the temp array the previous data from the original array
	}
	tempDateArr[amountOfApartPurc - 1] = object; // Stores in the last place in the temp array the new Date

	delete purchaseDateArr; // Deletes the previous 'purchaseDateArr' data

	purchaseDateArr = tempDateArr; // 'purchaseDateArr' points to the temp array address
}
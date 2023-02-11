/* Assignment: 4
Author: Maor Atar, ID: 318301231
*/

#include "Seller.h"

// -------------------Customized c'tor---------------------
Seller::Seller(const string _firstName, const string _lastName, Project* _projectsArr, Client** _clientsArr, const int _amountOfClients) : Person(_firstName, _lastName), amountOfClients(_amountOfClients)
{
	this->clientsArr = new Client * [amountOfClients];
	for (int i = 0; i < amountOfClients; i++)
	{
		clientsArr[i] = _clientsArr[i];
	}
	this->projectsArr = new Project[1];
	this->projectsArr = _projectsArr;
}
// ----------------------Copy c'tor------------------------
Seller::Seller(const Seller& copy) : Person(copy)
{
	if (this != &copy)
	{
		this->amountOfClients = copy.amountOfClients;
		this->projectsArr = new Project[1];
		this->projectsArr = copy.projectsArr;
		this->clientsArr = new Client * [amountOfClients];
		for (int i = 0; i < amountOfClients; i++)
		{
			clientsArr[i] = copy.clientsArr[i];
		}
	}
	else
	{
		cout << "Same objects" << endl; // Executes if the objects are equal
	}
}
// ------------------------D'tor---------------------------
Seller::~Seller()
{
	if (clientsArr)
	{
		for (int i = 0; i < amountOfClients; i++)
		{
			delete clientsArr[i];
		}
		delete[] clientsArr;
	}

	if (projectsArr)
	{
		delete projectsArr;
	}
	cout << "Deleting Seller" << endl;
}
// ---------------------Class Methods----------------------
// --------------------------------------------------------
int Seller::sellerSalary() const
{
	int month, amountStandard = 0, amountGarden = 0, amountPenthouse = 0; // Initializing the Apartment types counters

	do // Gets the required month from the user
	{
		cout << "Please enter the required month: (1-12)" << endl;
		cin >> month;
	} while (month < 1 || month > 12);

	for (int i = 0; i < amountOfClients; i++) // Loops through the Client array
	{
		for (int j = 0; j < clientsArr[i]->getAmountOfApartPurc(); j++) // Loops through the amount of Apartments each Client bought 
		{
			StandardApartment* tempStanardApart = dynamic_cast<StandardApartment*>(clientsArr[i]->getApartment(j)); // Using RTTI to check for a Standard Apartment
			if (tempStanardApart)
			{
				if (month == clientsArr[i]->getPurchaseMonth(j)) // Condition for the required month
				{
					amountStandard++; // Counts the amount of Standard Apartments
				}
			}

			GardenApartment* tempGardenApart = dynamic_cast<GardenApartment*>(clientsArr[i]->getApartment(j)); // Using RTTI to check for a Garden Apartment
			if (tempGardenApart)
			{
				if (month == clientsArr[i]->getPurchaseMonth(j)) // Condition for the required month
				{
					amountGarden++; // Counts the amount of Garden Apartments
				}
			}

			PenthouseApartment* tempPenthouseApart = dynamic_cast<PenthouseApartment*>(clientsArr[i]->getApartment(j)); // Using RTTI to check for a Penthouse Apartment
			if (tempPenthouseApart)
			{
				if (month == clientsArr[i]->getPurchaseMonth(j)) // Condition for the required month
				{
					amountPenthouse++; // Counts the amount of Penthouse Apartments
				}
			}
		}
	}
	return (amountStandard * 1000) + (amountPenthouse * 1500) + (amountGarden * 2000); // Returns the Seller salary after the calculation
}
// --------------------------------------------------------
void Seller::printPerson() const
{
	int amountStandard = 0, amountGarden = 0, amountPenthouse = 0; // Initializing the Apartment types counters

	for (int i = 0; i < amountOfClients; i++) // Loops through the Client array
	{
		for (int j = 0; j < clientsArr[i]->getAmountOfApartPurc(); j++) // Loops through the amount of Apartments each Client bought 
		{
			StandardApartment* tempStanardApart = dynamic_cast<StandardApartment*>(clientsArr[i]->getApartment(j)); // Using RTTI to check for a Standard Apartment
			if (tempStanardApart)
			{
				amountStandard++; // Counts the amount of Standard Apartments
			}

			GardenApartment* tempGardenApart = dynamic_cast<GardenApartment*>(clientsArr[i]->getApartment(j)); // Using RTTI to check for a Garden Apartment
			if (tempGardenApart)
			{
				amountGarden++; // Counts the amount of Garden Apartments
			}

			PenthouseApartment* tempPenthouseApart = dynamic_cast<PenthouseApartment*>(clientsArr[i]->getApartment(j)); // Using RTTI to check for a Penthouse Apartment
			if (tempPenthouseApart)
			{
				amountPenthouse++; // Counts the amount of Penthouse Apartments
			}
		}
	}

	cout << "-----Seller Details-----" << endl;
	Person::printPerson();
	cout << "The seller has " << amountOfClients << " clients." << endl;
	cout << "The amount of apartments sold, sorted by type: " << endl;
	cout << "Standard Apartments: " << amountStandard << endl;
	cout << "Garden Apartments: " << amountGarden << endl;
	cout << "Penthouse Apartments: " << amountPenthouse << endl;
}
// --------------------------------------------------------
int Seller::getAmountApartSold(int month) const
{
	int total = 0;

	for (int i = 0; i < amountOfClients; i++) // Loops through the Client array
	{
		for (int j = 0; j < clientsArr[i]->getAmountOfApartPurc(); j++) // Loops through the amount of Apartments each Client bought 
		{
			if (month == clientsArr[i]->getPurchaseMonth(j)) // Condition for the required month
			{
				total++; // Increments total by 1 
			}
		}
	}
	return total; // Returns the amount of Apartments sold in the  required month
}
// --------------------------------------------------------
void Seller::addClient(Client* object)
{
	this->amountOfClients++; // Incremants the 'amountOfClients' by 1

	Client** tempClientsArr = new Client * [amountOfClients]; // Creating a temp Client array with the new size
	for (int i = 0; i < amountOfClients - 1; i++)
	{
		tempClientsArr[i] = clientsArr[i]; // Stores in the temp array the previous data from the original array
	}
	tempClientsArr[amountOfClients - 1] = object; // Stores in the last place in the temp array the new Apartmen

	delete[] clientsArr; // Deletes the previous 'clientsArr' data

	clientsArr = tempClientsArr; // 'clientsArr' points to the temp array address
}
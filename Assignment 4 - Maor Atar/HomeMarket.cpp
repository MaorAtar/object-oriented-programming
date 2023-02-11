/* Assignment: 4
Author: Maor Atar, ID: 318301231
*/

#include "HomeMarket.h"

// -------------------Default c'tor-----------------------
HomeMarket::HomeMarket() : amountOfApartments(4), amountOfProjects(1), amountOfPersons(1)
{ // Puts default data in the Class arrays
	apartmentArr = new Apartment * [amountOfApartments];
	apartmentArr[0] = new GardenApartment();
	apartmentArr[1] = new StandardApartment();
	apartmentArr[2] = new StandardApartment();
	apartmentArr[3] = new PenthouseApartment();

	Building** defaultBuilding = new Building * [1];
	defaultBuilding[0] = new Building("Default Address", 4, apartmentArr);
	projectArr = new Project * [amountOfProjects];
	projectArr[0] = new Project("Default Project", 1, defaultBuilding);

	personArr = new Person * [amountOfPersons];
	personArr[0] = new Seller();
}
// ------------------------D'tor---------------------------
HomeMarket::~HomeMarket()
{
	if (apartmentArr) // If 'apartmentArr' has data, deletes the data
	{
		for (int i = 0; i < amountOfApartments; i++)
		{
			delete apartmentArr[i];
		}
		delete apartmentArr;
	}

	if (personArr) // If 'personArr' has data, deletes the data
	{
		for (int i = 0; i < amountOfPersons; i++)
		{
			delete personArr[i];
		}
		delete personArr;
	}

	if (projectArr) // If 'projectArr' has data, deletes the data
	{
		delete projectArr;
	}
}
// ---------------------Class Methods----------------------
// --------------------------------------------------------
bool HomeMarket::Menu()
{
	int choice;
	bool flag = false;

	cout << "**************************************************************************" << endl;
	cout << "**************************************************************************" << endl;
	cout << "***********************Welcome To Home-Market Menu!***********************" << endl;
	cout << "**************************************************************************" << endl;
	cout << "**************************************************************************" << endl;
	do
	{
		cout << "--------------------------------------------------------------------------" << endl;
		cout << "Please pick the required option from: (1-13)" << endl;
		cout << "1.Print the details of the Clients that bought Standard Apartments" << endl;
		cout << "2.Add a Building" << endl;
		cout << "3.Add a Project" << endl;
		cout << "4.Add a Seller" << endl;
		cout << "5.Add a Client" << endl;
		cout << "6.Print Apartment details using 'Apartment Number' and 'Building Address'" << endl;
		cout << "7.Print Standard Apartments details with 2 balconys that are for sale" << endl;
		cout << "8.Print Seller salarys using 'First Name' and 'Last Name'" << endl;
		cout << "9.Print Apartment details that are suited for the Client requirements" << endl;
		cout << "10.Print Penthouse Apartments details in the existing Project" << endl;
		cout << "11.Buy Apartment" << endl;
		cout << "12.Print Clients details with the lowest Property Tax" << endl;
		cout << "13.Exit" << endl;
		cout << "Your Choice: " << endl;
		cin >> choice;
		
		switch (choice) // Gets the choice from the user, and executing the required function
		{
		case 1:
			printStandardBuyers();
			break;
		case 2:
			addBuilding();
			break;
		case 3:
			addProject();
			break;
		case 4:
			addSeller();
			break;
		case 5:
			addClient();
			break;
		case 6:
			printApartment();
			break;
		case 7:
			printStandardApartBalconys();
			break;
		case 8:
			printSellerSalary();
			break;
		case 9:
			printSuitedClientApart();
			break;
		case 10:
			printPenthouseApart();
			break;
		case 11:
			apartmentSell();
			break;
		case 12:
			lowestPropertyTax();
			break;
		case 13: // Case to exit
			cout << "--------------------------" << endl;
			cout << "EXITING - Have A Good Day!" << endl;
			cout << "--------------------------" << endl;
			flag = true;
			return true;
		default: // Case for incorrect choice
			cout << "-------------------------" << endl;
			cout << "ERROR - Incorrect Choice!" << endl;
			cout << "-------------------------" << endl;
			break;
		}
	} while (flag != true); // Prints the menu while the choice entered is invalid
	return true;
}
// --------------------------------------------------------
void HomeMarket::printStandardBuyers() const
{
	bool flag = false;

	for (int i = 0; i < amountOfPersons; i++)
	{
		Client* tempClient = dynamic_cast<Client*>(personArr[i]); // Using RTTI, to look for Clients in the Persons array
		if (tempClient)
		{
			for (int j = 0; j < tempClient->getAmountOfApartPurc(); j++)
			{
				StandardApartment* tempStanardApart = dynamic_cast<StandardApartment*>(tempClient->getApartment(j)); // Using RTTI, to look for Standard Apartments in the Client - Apartment array
				if (tempStanardApart)
				{
					tempClient->printPerson(); // Prints the Client details
					flag = true;
				}
			}
		}
	}
	if (flag == false)
	{
		cout << "------------------------------------------" << endl;
		cout << "ERROR - No Standard Apartments bought yet!" << endl;
		cout << "------------------------------------------" << endl;
	}
}
// --------------------------------------------------------
bool HomeMarket::addBuilding()
{
	string projectName, buildingAddress;
	bool flag = false, apartmentStatus;
	int projectIndex, buildingFloors, numOfApartments, apartmentNum, floor, apartmentArea, gardenArea, poolStatus, balconySize, amountOfBalconys, index = 1;
	int* balconySizeArr = NULL;

	cout << "Enter Project name: " << endl;
	cin >> projectName;

	for (int i = 0; i < amountOfProjects; i++)
	{
		if (projectName == projectArr[i]->getProjectName())
		{
			projectIndex = i; // Stores the Project placement in the Projects array
			flag = true;

			cout << "---Building Details---" << endl;
			cout << "Enter Building address: " << endl;
			cin >> buildingAddress;
			cout << "Enter amount of floors: " << endl;
			cin >> buildingFloors;
			if (buildingFloors < 3)
			{
				cout << "-------------------------------------------" << endl;
				cout << "ERROR - building must have a least 3 floors" << endl;
				cout << "-------------------------------------------" << endl;
				return false;
			}
			numOfApartments = (buildingFloors * 2) - 2;
			Apartment** tempApartmentArr = new Apartment * [numOfApartments]; // Using a temp Apartments array

			for (int j = 0; j < buildingFloors; j++) // Loops through all the Building floors
			{
				if (j == 0) // Garden Apartment floor
				{
					cout << "---Garden Apartment Details---" << endl;
					cout << "Apartment #1" << endl;
					apartmentNum = 1;
					cout << "Apartment floor: 0" << endl;
					floor = 0;
					cout << "Enter the apartment area: " << endl;
					cin >> apartmentArea;
					cout << "Enter 1 if the apartment sold, 0 if not sold: " << endl;
					cin >> apartmentStatus;
					cout << "Enter the garden area: " << endl;
					cin >> gardenArea;
					cout << "Enter 1 if the Garden Apartment has pool, 0 if not: " << endl;
					cin >> poolStatus;

					GardenApartment* tempGardenApartment = new GardenApartment(apartmentNum, floor, apartmentArea, apartmentStatus, gardenArea, poolStatus); // Creates temp Garden Apartment using the user details
					tempApartmentArr[j] = tempGardenApartment; // Stores in the temp array the temp Garden Apartment
				}
				else if (j == buildingFloors - 1) // Penhouse Apartment floor
				{
					cout << "---Penthouse Apartment Details---" << endl;
					apartmentNum = numOfApartments;
					cout << "Apartment #" << apartmentNum << endl;
					floor = buildingFloors - 1;
					cout << "Apartment floor: " << floor << endl;
					cout << "Enter the apartment area: " << endl;
					cin >> apartmentArea;
					cout << "Enter 1 if the apartment sold, 0 if not sold: " << endl;
					cin >> apartmentStatus;
					cout << "Enter the balcony area: " << endl;
					cin >> balconySize;

					PenthouseApartment* tempPenthouseApartment = new PenthouseApartment(apartmentNum, floor, apartmentArea, apartmentStatus, balconySize); // Creates temp Penthouse Apartment using the user details
					tempApartmentArr[numOfApartments - 1] = tempPenthouseApartment; // Stores in the temp array the temp Penthouse Apartment
				}
				else // Standard Apartments floors
				{
					int floor = j;
					for (int k = 0; k < 2; k++) // Evrey floor has 2 Standard Apartments
					{
						cout << "---Standard Apartment Details---" << endl;
						apartmentNum = (j * 2) + k;
						cout << "Apartment #" << apartmentNum << endl;
						cout << "Apartment floor: " << floor << endl;
						cout << "Enter the apartment area: " << endl;
						cin >> apartmentArea;
						cout << "Enter 1 if the apartment sold, 0 if not sold: " << endl;
						cin >> apartmentStatus;
						do
						{
							cout << "Enter the amount of balconys(maximum 2): " << endl;
							cin >> amountOfBalconys;
						} while (amountOfBalconys < 0 || amountOfBalconys > 2);
						balconySizeArr = new int[amountOfBalconys];
						for (int s = 0; s < amountOfBalconys; s++)
						{
							cout << "Enter the #" << s + 1 << " balcony size: " << endl;
							cin >> balconySizeArr[s];
						}
						StandardApartment* tempStandardApartment = new StandardApartment(apartmentNum, floor, apartmentArea, apartmentStatus, amountOfBalconys, balconySizeArr); // Creates temp Standard Apartment using the user details
						tempApartmentArr[index] = tempStandardApartment; // Stores in the temp array the temp Standard Apartment
						index++; // Increments index by 1

						delete[] balconySizeArr; // Deletes the temp balcony array
					}
				}
			}
			Building* tempBuilding = new Building(buildingAddress, buildingFloors, tempApartmentArr); // Creates temp Building using the user details

			projectArr[projectIndex]->addBuilding(tempBuilding); // Creates a new Building in the required Project, using the 'addBuilding' function from Class Project

			Apartment** tempApartmentArr2 = new Apartment * [numOfApartments + amountOfApartments]; // Using a temp Apartments array
			for (int i = 0; i < amountOfApartments; i++)
			{
				tempApartmentArr2[i] = apartmentArr[i]; // Stores in the temp array the previous data from the original array
			}

			for (int i = amountOfApartments, j = 0; i < amountOfApartments + numOfApartments; i++, j++)
			{
				tempApartmentArr2[i] = tempApartmentArr[j]; // Stores in the temp array the previous data from the original array
			}
			this->amountOfApartments += numOfApartments; // Updates the 'amountOfApartments' size
			delete apartmentArr; // Deletes the previous 'apartmentArr' data
			apartmentArr = tempApartmentArr2; // 'apartmentArr' points to the temp array address

			cout << "-------------------" << endl;
			cout << "Building been added" << endl;
			cout << "-------------------" << endl;
			
			return true;
		}
	}
	if (flag == false)
	{
		cout << "-----------------------------" << endl;
		cout << "ERROR - Project dosen't exist" << endl;
		cout << "-----------------------------" << endl;
		return false;
	}
	return true;
}
// --------------------------------------------------------
bool HomeMarket::addProject()
{
	string projectName, buildingAddress;
	int amountOfBuildings, buildingFloors, numOfApartments, apartmentNum, floor, apartmentArea, gardenArea, poolStatus, balconySize, amountOfBalconys, index = 1;
	int* balconySizeArr = NULL;
	bool apartmentStatus;

	cout << "Please enter the name of the project: " << endl;
	cin >> projectName;
	for (int i = 0; i < amountOfProjects; i++)
	{
		if (projectName == projectArr[i]->getProjectName())
		{
			cout << "-------------------------------------------------" << endl;
			cout << "ERROR - project name already exists in the system" << endl;
			cout << "-------------------------------------------------" << endl;
			return false;
		}
	}
	cout << "Please enter the amount of buildings in the project: " << endl;
	cin >> amountOfBuildings;

	Building** tempBuildingArr = new Building * [amountOfBuildings]; // Using a temp Buildings array

	for (int t = 0; t < amountOfBuildings; t++) // Loops through the Buildings
	{
		cout << "Enter the amount of floors in the building: " << endl;
		cin >> buildingFloors;
		if (buildingFloors < 3) // Condition for invalid floors input
		{
			cout << "-------------------------------------------" << endl;
			cout << "ERROR - building must have a least 3 floors" << endl;
			cout << "-------------------------------------------" << endl;
			return false;
		}

		cout << "Enter the building address: " << endl;
		cin >> buildingAddress;

		cout << "Please enter the apartments details: " << endl;

		numOfApartments = (buildingFloors * 2) - 2;
		Apartment** tempApartmentArr = new Apartment * [numOfApartments]; // Using a temp Apartments array

		for (int j = 0; j < buildingFloors; j++) // Loops through all the Building floors
		{
			if (j == 0) // Garden Apartment floor
			{
				cout << "---Garden Apartment Details---" << endl;
				cout << "Apartment #1" << endl;
				apartmentNum = 1;
				cout << "Apartment floor: 0" << endl;
				floor = 0;
				cout << "Enter the apartment area: " << endl;
				cin >> apartmentArea;
				cout << "Enter 1 if the apartment sold, 0 if not sold: " << endl;
				cin >> apartmentStatus;
				cout << "Enter the garden area: " << endl;
				cin >> gardenArea;
				cout << "Enter 1 if the Garden Apartment has pool, 0 if not: " << endl;
				cin >> poolStatus;

				GardenApartment* tempGardenApartment = new GardenApartment(apartmentNum, floor, apartmentArea, apartmentStatus, gardenArea, poolStatus); // Creates temp Garden Apartment using the user details
				tempApartmentArr[j] = tempGardenApartment; // Stores in the temp array the temp Garden Apartment
			}
			else if (j == buildingFloors - 1) // Penhouse Apartment floor
			{
				cout << "---Penthouse Apartment Details---" << endl;
				apartmentNum = numOfApartments;
				cout << "Apartment #" << apartmentNum << endl;
				floor = buildingFloors - 1;
				cout << "Apartment floor: " << floor << endl;
				cout << "Enter the apartment area: " << endl;
				cin >> apartmentArea;
				cout << "Enter 1 if the apartment sold, 0 if not sold: " << endl;
				cin >> apartmentStatus;
				cout << "Enter the balcony area: " << endl;
				cin >> balconySize;

				PenthouseApartment* tempPenthouseApartment = new PenthouseApartment(apartmentNum, floor, apartmentArea, apartmentStatus, balconySize); // Creates temp Penthouse Apartment using the user details
				tempApartmentArr[numOfApartments - 1] = tempPenthouseApartment; // Stores in the temp array the temp Penthouse Apartment
			}
			else // Standard Apartments floors
			{
				int floor = j;
				for (int k = 0; k < 2; k++) // Every floor has 2 Standard Apartments
				{
					cout << "---Standard Apartment Details---" << endl;
					apartmentNum = (j * 2) + k;
					cout << "Apartment #" << apartmentNum << endl;
					cout << "Apartment floor: " << floor << endl;
					cout << "Enter the apartment area: " << endl;
					cin >> apartmentArea;
					cout << "Enter 1 if the apartment sold, 0 if not sold: " << endl;
					cin >> apartmentStatus;
					do
					{
						cout << "Enter the amount of balconys(maximum 2): " << endl;
						cin >> amountOfBalconys;
					} while (amountOfBalconys < 0 || amountOfBalconys > 2);
					balconySizeArr = new int[amountOfBalconys];
					for (int s = 0; s < amountOfBalconys; s++)
					{
						cout << "Enter the #" << s + 1 << " balcony size: " << endl;
						cin >> balconySizeArr[s];
					}
					StandardApartment* tempStandardApartment = new StandardApartment(apartmentNum, floor, apartmentArea, apartmentStatus, amountOfBalconys, balconySizeArr); // Creates temp Standard Apartment using the user details
					tempApartmentArr[index] = tempStandardApartment; // Stores in the temp array the temp Standard Apartment
					index++; // Increments index by 1

					delete[] balconySizeArr; // Deletes the temp balcony array
				}
			}
		}
		Building* tempBuilding = new Building(buildingAddress, buildingFloors, tempApartmentArr); // Creates temp Building using the user details

		Apartment** tempApartmentArr2 = new Apartment * [numOfApartments + amountOfApartments]; // Using a temp Apartments array
		for (int i = 0; i < amountOfApartments; i++)
		{
			tempApartmentArr2[i] = apartmentArr[i]; // Stores in the temp array the previous data from the original array
		}

		for (int i = amountOfApartments, j = 0; i < amountOfApartments + numOfApartments; i++, j++)
		{
			tempApartmentArr2[i] = tempApartmentArr[j]; // Stores in the temp2 array the previous data from temp1 array
		}
		this->amountOfApartments += numOfApartments; // Updates the 'amountOfApartments' size
		delete apartmentArr; // Deletes the previous 'apartmentArr' data
		apartmentArr = tempApartmentArr2; // 'apartmentArr' points to the temp array address

		tempBuildingArr[t] = tempBuilding; // Stores in the temp Building array the temp Building
	}
	Project* tempProject = new Project(projectName, amountOfBuildings, tempBuildingArr); // Creates temp Project using the user details
	Project** tempProjectArr = new Project * [amountOfProjects + 1]; // Creates temp Project array

	for (int i = 0; i < amountOfProjects; i++)
	{
		tempProjectArr[i] = projectArr[i];// Stores in the temp array the previous data from the original array
	}
	tempProjectArr[amountOfProjects] = tempProject; // Stores the new Project in the last place in the Projects array 

	this->amountOfProjects++; // Updates the 'amountOfProjects' size
	delete projectArr; // Deletes the previous 'projectArr' data
	projectArr = tempProjectArr; // 'projectArr' points to the temp array address

	cout << "-------------" << endl;
	cout << "Project added" << endl;
	cout << "-------------" << endl;

	return true;
}
// --------------------------------------------------------
bool HomeMarket::addSeller()
{
	string tempFirstName, tempLastName, tempProjectName;
	int projectIndex;
	bool flag1 = false, flag2 = false;

	cout << "Enter the first name of the Seller: " << endl;
	cin >> tempFirstName;
	cout << "Enter the last name of the Seller: " << endl;
	cin >> tempLastName;
	
	for (int i = 0; i < amountOfPersons; i++)
	{
		if ((tempFirstName == personArr[i]->getFirstName()) && (tempLastName == personArr[i]->getLastName()))
		{
			flag1 = true;
		}
	}
	if (flag1 == true)
	{
		cout << "-----------------------------" << endl;
		cout << "ERROR - Seller already exists" << endl;
		cout << "-----------------------------" << endl;
		return false;
	}

	cout << "Enter the name of the Project the Seller marketing: " << endl;
	cin >> tempProjectName;

	for (int j = 0; j < amountOfProjects; j++)
	{
		if (tempProjectName == projectArr[j]->getProjectName())
		{
			flag2 = true;
			projectIndex = j; // Stores the Project placement in the Projects array

			Seller* tempSeller = new Seller(tempFirstName, tempLastName, projectArr[projectIndex], NULL, 0); // Creates a temp Seller
			Person** tempPersonArr = new Person * [amountOfPersons + 1]; // Creates temp Persons array
			for (int k = 0; k < amountOfPersons; k++)
			{
				tempPersonArr[k] = personArr[k]; // Stores in the temp array the previous data from the original array
			}
			tempPersonArr[amountOfPersons] = tempSeller; // Stores the new Seller in the last place in the Persons array 

			this->amountOfPersons++; // Updates 'amountOfPersons' with the new size
			delete personArr; // Deletes the previous 'personArr' data
			personArr = tempPersonArr; // 'personArr' points to the temp array address
		}
	}

	if (flag2 == false)
	{
		cout << "-----------------------------" << endl;
		cout << "ERROR - Project dosen't exist" << endl;
		cout << "-----------------------------" << endl;
		return false;
	}
	else
	{
		cout << "------------" << endl;
		cout << "Seller added" << endl;
		cout << "------------" << endl;
		return true;
	}
}
// --------------------------------------------------------
bool HomeMarket::addClient()
{
	string tempFirstName, tempLastName;
	int budget;

	cout << "Enter the first name of the Client: " << endl;
	cin >> tempFirstName;
	cout << "Enter the last name of the Client: " << endl;
	cin >> tempLastName;
	for (int i = 0; i < amountOfPersons; i++)
	{
		if ((tempFirstName == personArr[i]->getFirstName()) && (tempLastName == personArr[i]->getLastName())) // Condition for existing Client
		{
			cout << "-----------------------------" << endl;
			cout << "ERROR - Client already exists" << endl;
			cout << "-----------------------------" << endl;
			return false;
		}
	}

	cout << "Enter the budget of the Client: " << endl;
	cin >> budget;

	Client* tempClient = new Client(tempFirstName, tempLastName, budget, NULL, NULL, 0); // Creates a temp Client
	Person** tempPersonArr = new Person * [amountOfPersons + 1]; // Creates a temp Persons array
	for (int k = 0; k < amountOfPersons; k++)
	{
		tempPersonArr[k] = personArr[k]; // Stores in the temp array the previous data from the original array
	}
	tempPersonArr[amountOfPersons] = tempClient; // Stores the new Client in the last place in the Persons array 

	this->amountOfPersons++; // Updates 'amountOfPersons' with the new size
	delete personArr; // Deletes the previous 'personArr' data
	personArr = tempPersonArr; // 'persontArr' points to the temp array address

	cout << "------------" << endl;
	cout << "Client added" << endl;
	cout << "------------" << endl;

	return true;
}
// --------------------------------------------------------
bool HomeMarket::printApartment() const
{
	int apartmentNum;
	string buildingAddress;
	bool flag1 = false, flag2 = false;

	cout << "Enter the Apartment Number: " << endl;
	cin >> apartmentNum;
	cout << "Enter the Building Address: " << endl;
	cin >> buildingAddress;

	for (int i = 0; i < amountOfProjects; i++)
	{
		for (int j = 0; j < projectArr[i]->getAmountOfBuildings(); j++)
		{
			if (projectArr[i]->getBuilidingAddress(j) == buildingAddress) // Condition to check if the project exsits in the system
			{
				flag1 = true;
			}
		}
	}
	if (flag1 == false)
	{
		cout << "------------------------------" << endl;
		cout << "ERROR - Building dosen't exist" << endl;
		cout << "------------------------------" << endl;
		return false;
	}

	for (int i = 0; i < amountOfProjects; i++) // Loops throgh the Projectes
	{
		for (int j = 0; j < projectArr[i]->getAmountOfBuildings(); j++)
		{
			if (projectArr[i]->getBuilidingAddress(j) == buildingAddress) // Condition for same Building address
			{
				for (int k = 0; k < amountOfApartments; k++)
				{
					if (apartmentArr[k]->getApartmentNum() == apartmentNum) // Condition for same Apartment number
					{
						flag2 = true;
						GardenApartment* tempGardenApartment = dynamic_cast<GardenApartment*>(apartmentArr[k]); // Using RTTI
						if (tempGardenApartment)
						{
							tempGardenApartment->printApartment(); // Prints Garden Apartment
						}

						StandardApartment* tempStandardApartment = dynamic_cast<StandardApartment*>(apartmentArr[k]); // Using RTTI
						if (tempStandardApartment)
						{
							tempStandardApartment->printApartment(); // Prints Standard Apartment
						}
						PenthouseApartment* tempPenthouseApartment = dynamic_cast<PenthouseApartment*>(apartmentArr[k]); // Using RTTI
						if (tempPenthouseApartment)
						{
							tempPenthouseApartment->printApartment(); // Prints Penthouse Apartment
						}
						return true;
					}
				}
			}
		}
	}

	if (flag2 == false)
	{
		cout << "-----------------------------------------------" << endl;
		cout << "ERROR - Apartment dosen't exist in the building" << endl;
		cout << "-----------------------------------------------" << endl;
		return false;
	}
	else
	{
		return true;
	}
}
// --------------------------------------------------------
bool HomeMarket::printStandardApartBalconys() const
{
	bool flag = false;

	for (int i = 0; i < amountOfApartments; i++) // Loops through the Apartments array
	{
		StandardApartment* tempStandardApart = dynamic_cast<StandardApartment*>(apartmentArr[i]); // Using RTTI
		if (tempStandardApart)
		{
			if ((tempStandardApart->getAmountOfBalconys() == 2) && tempStandardApart->getApartmentStatus() == false) // Check for 2 balconys, and availabe Apartment
			{
				flag = true;
				tempStandardApart->printApartment(); // Prints the matching Standard Apartment
			}
		}
	}
	if (flag == false)
	{
		cout << "----------------------------------------" << endl;
		cout << "ERROR - No available Standard Apartments" << endl;
		cout << "----------------------------------------" << endl;
		return false;
	}
	else
	{
		return true;
	}
}
// --------------------------------------------------------
bool HomeMarket::printSellerSalary() const
{
	string tempFirstName, tempLastName;
	int salary;
	bool flag = false;

	cout << "Enter the first name of the Seller: " << endl;
	cin >> tempFirstName;
	cout << "Enter the last name of the Seller: " << endl;
	cin >> tempLastName;

	for (int i = 0; i < amountOfPersons; i++) // Loops through the Persons
	{
		if ((personArr[i]->getFirstName() == tempFirstName) && (personArr[i]->getLastName() == tempLastName)) // Condition for same first and last name
		{
			Seller* tempSeller = dynamic_cast<Seller*>(personArr[i]); // Using RTTI, to look for a Seller
			if (tempSeller)
			{
				salary = tempSeller->sellerSalary(); // stores in 'salary' the Seller salary, using 'sellerSalary' function from Seller Class
				if (salary >= 0) // Condition for a vaild salary
				{
					flag = true;
					cout << "---------------------------------------------------" << endl;
					cout << "The Seller salary in the required month: " << salary << endl;
					cout << "---------------------------------------------------" << endl;
				}
			}
		}
	}
	if (flag == false)
	{
		cout << "----------------------------" << endl;
		cout << "ERROR - Seller dosen't exist" << endl;
		cout << "----------------------------" << endl;
		return false;
	}
	else
	{
		return true;
	}
}
// --------------------------------------------------------
bool HomeMarket::printSuitedClientApart() const
{
	int clientNumber;
	bool flag1 = false, flag2 = false, flag3 = false;

	cout << "Enter the 'Client Number': " << endl;
	cin >> clientNumber;

	for (int i = 0; i < amountOfPersons; i++)
	{
		Client* tempClient = dynamic_cast<Client*>(personArr[i]); // Using RTTI, to look for a Client
		if (tempClient)
		{
			flag1 = true;
			if (tempClient->getClientNumber() == clientNumber) // Condition for same Client Number
			{
				flag2 = true;
				for (int j = 4; j < amountOfApartments; j++) // Starts from 4 because we don't want the default apartments
				{
					if ((apartmentArr[j]->getApartmentStatus() == false) && (apartmentArr[j]->getApartmentPrice() <= tempClient->getBudget())) // Condition for available Apartment, and suited for the Client budget
					{
						flag3 = true;
						GardenApartment* tempGardenApartment = dynamic_cast<GardenApartment*>(apartmentArr[j]); // Using RTTI
						if (tempGardenApartment)
						{
							tempGardenApartment->printApartment(); // Prints Garden Apartment
						}

						StandardApartment* tempStandardApartment = dynamic_cast<StandardApartment*>(apartmentArr[j]); // Using RTTI
						if (tempStandardApartment)
						{
							tempStandardApartment->printApartment(); // Prints Standard Apartment
						}
						PenthouseApartment* tempPenthouseApartment = dynamic_cast<PenthouseApartment*>(apartmentArr[j]); // Using RTTI
						if (tempPenthouseApartment)
						{
							tempPenthouseApartment->printApartment(); // Prints Penthouse Apartment
						}
					}
				}
			}
		}
	}
	if (flag1 == false)
	{
		cout << "--------------------------------" << endl;
		cout << "ERROR - No Clients in the market" << endl;
		cout << "--------------------------------" << endl;
		return false;
	}
	else if (flag2 == false)
	{
		cout << "-------------------------------------" << endl;
		cout << "ERROR - 'Client Number' dosen't exist" << endl;
		cout << "-------------------------------------" << endl;
		return false;
	}
	else if (flag3 == false)
	{
		cout << "--------------------------------------------------------" << endl;
		cout << "ERROR - No available Apartments matches the requirements" << endl;
		cout << "--------------------------------------------------------" << endl;
		return false;
	}
	else
	{
		return true;
	}
}
// --------------------------------------------------------
bool HomeMarket::printPenthouseApart() const
{
	string tempProjectName;
	int projectIndex = 0;
	bool flag = false;

	cout << "Enter the name of the Project: " << endl;
	cin >> tempProjectName;

	for (int i = 0; i < amountOfProjects; i++)
	{
		if (projectArr[i]->getProjectName() == tempProjectName) // Condition for same Project name
		{
			flag = true;
			projectIndex = i; // Stores the Project placement in the Projects array
		}
	}
	for (int i = 0; i < projectArr[projectIndex]->getAmountOfBuildings(); i++)
	{
		projectArr[projectIndex]->printPenthouseApart(i); // Prints the required Penthouse Apartment, in the required Project, using the 'printPenthouseApart' function from the Project Class
	}

	if (flag == false)
	{
		cout << "-----------------------------" << endl;
		cout << "ERROR - Project dosen't exist" << endl;
		cout << "-----------------------------" << endl;
		return false;
	}
	else
	{
		return true;
	}
}
// --------------------------------------------------------
bool HomeMarket::apartmentSell() const
{
	string projectName, buildingAddress, sellerFirstName, sellerLastName;
	int apartmentNum, clientNum, tempClientBudget, projectIndex, apartmentIndex;
	bool flag1 = false, flag2 = false, flag3 = false, flag4 = false, flag5 = false, flag6 = false, flag7 = false, flag8 = false;
	Apartment* boughtApartment = NULL;
	Date* currentDate = new Date();

	cout << "Enter the name of the Project: " << endl;
	cin >> projectName;

	for (int i = 0; i < amountOfProjects; i++)
	{
		if (projectArr[i]->getProjectName() == projectName) // Condition for same Project name
		{
			flag1 = true;
			projectIndex = i; // Stores the Project placement in the Projects array
		}
	}
	if (flag1 == false)
	{
		cout << "-----------------------------" << endl;
		cout << "ERROR - Project dosen't exist" << endl;
		cout << "-----------------------------" << endl;
		return false;
	}

	cout << "Enter the Building Address: " << endl;
	cin >> buildingAddress;
	for (int j = 0; j < amountOfProjects; j++)
	{
		if ((projectArr[projectIndex]->amountOfApartByAddress(buildingAddress) != 0) && (projectArr[projectIndex]->amountOfApartByAddress(buildingAddress) != -1)) // Condition for exsiting Building
		{
			flag2 = true;
		}
	}
	if (flag2 == false)
	{
		cout << "------------------------------" << endl;
		cout << "ERROR - Building dosen't exist" << endl;
		cout << "------------------------------" << endl;
		return false;
	}

	cout << "Enter the Apartment Number: " << endl;
	cin >> apartmentNum;
	for (int k = 0; k < amountOfApartments; k++)
	{
		if (apartmentArr[k]->getApartmentNum() == apartmentNum) // Condition for the same Apartment number
		{
			flag3 = true;
			apartmentIndex = k; // Stores the Apartment placement in the Apartments array
		}
	}
	if (flag3 == false)
	{
		cout << "--------------------------------------" << endl;
		cout << "ERROR - Apartment Number dosen't exist" << endl;
		cout << "--------------------------------------" << endl;
		return false;
	}

	cout << "Enter the 'Client Number': " << endl;
	cin >> clientNum;

	for (int i = 0; i < amountOfPersons; i++)
	{
		Client* tempClient = dynamic_cast<Client*>(personArr[i]); // Using RTTI
		if (tempClient)
		{
			if (tempClient->getClientNumber() == clientNum) // Condition for same Client number
			{
				flag4 = true;
				tempClientBudget = tempClient->getBudget(); // Stores in 'tempClientBudget' the Client budget
			}
		}
	}
	if (flag4 == false)
	{
		cout << "-------------------------------------" << endl;
		cout << "ERROR - 'Client Number' dosen't exist" << endl;
		cout << "-------------------------------------" << endl;
		return false;
	}

	cout << "Enter the Seller First Name: " << endl;
	cin >> sellerFirstName;
	cout << "Enter the Seller Last Name: " << endl;
	cin >> sellerLastName;
	for (int i = 0; i < amountOfPersons; i++)
	{
		if (personArr[i]->getFirstName() == sellerFirstName && personArr[i]->getLastName() == sellerLastName) // Condition for exsiting Seller
		{
			flag5 = true;
		}
	}
	if (flag5 == false)
	{
		cout << "----------------------------" << endl;
		cout << "ERROR - Seller dosen't exist" << endl;
		cout << "----------------------------" << endl;
		return false;
	}

	if (apartmentArr[apartmentIndex]->getApartmentStatus() == true)
	{
		cout << "----------------------------------" << endl;
		cout << "ERROR - Apartment already sold out" << endl;
		cout << "----------------------------------" << endl;
		return false;
	}

	if (apartmentArr[apartmentIndex]->getApartmentPrice() > tempClientBudget)
	{
		cout << "------------------------------------------------------------" << endl;
		cout << "ERROR - Client budget not enough for the requested apartment" << endl;
		cout << "------------------------------------------------------------" << endl;
		return false;
	}


	apartmentArr[apartmentIndex]->setApartmentStatus(true);
	boughtApartment = apartmentArr[apartmentIndex];

	for (int i = 0; i < amountOfPersons; i++)
	{
		Client* tempClient = dynamic_cast<Client*>(personArr[i]); // Using RTTI
		if (tempClient)
		{
			if (tempClient->getClientNumber() == clientNum) // Condition for the same Client number
			{
				tempClient->addApartment(boughtApartment); // Adds the Apartment to the Client Apartments bought array
				tempClient->addDate(currentDate); // Adds the Date to the Client Purchase Date array
				cout << "-----------------" << endl;
				cout << "Apartment Bought!" << endl;
				cout << "-----------------" << endl;
				for (int j = 0; j < amountOfPersons; j++)
				{
					if ((personArr[j]->getFirstName() == sellerFirstName) && (personArr[j]->getLastName() == sellerLastName))
					{
						Seller* tempSeller = dynamic_cast<Seller*>(personArr[j]); // Using RTTI
						if (tempSeller)
						{
							tempSeller->addClient(tempClient); // Adds the Client to the Seller Clients array
						}
					}
				}
			}
		}
	}
	return true;
}
// --------------------------------------------------------
bool HomeMarket::lowestPropertyTax()
{
	int* propertyTaxArr = new int[1], min = 10000000, minClient = 0;
	bool flag = false;

	for (int i = 0; i < amountOfPersons; i++)
	{
		Client* tempClient = dynamic_cast<Client*>(personArr[i]); // Using RTTI, to look for a Client
		if (tempClient)
		{
			flag = true;
			if (tempClient->getAmountOfApartPurc() == 1) // Condition for a Client that bought a single Apartment
			{
				propertyTaxArr = tempClient->propertyTax(); // Stores in 'propertyTaxArr' the Property Tax array of the Client
				if (min > propertyTaxArr[0])
				{
					min = propertyTaxArr[0]; // Stores the minimum Property Tax in 'min'
					minClient = i; // Stores in 'minClient' the Client index
				}
			}
		}
	}

	for (int i = 0; i < amountOfPersons; i++)
	{
		Client* tempClient = dynamic_cast<Client*>(personArr[i]);
		if (tempClient)
		{
			if (i == minClient) // Same required Client index
			{
				tempClient->printPerson(); // Prints the Client details
			}
		}
	}

	if (flag == false)
	{
		cout << "--------------------------------" << endl;
		cout << "ERROR - No Clients in the system" << endl;
		cout << "--------------------------------" << endl;
		return false;
	}
	else
	{
		return true;
	}
}
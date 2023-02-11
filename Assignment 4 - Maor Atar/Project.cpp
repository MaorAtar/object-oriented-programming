/* Assignment: 4
Author: Maor Atar, ID: 318301231
*/

#include "Project.h"

// -------------------Customized c'tor---------------------
Project::Project(string _projectName, int _amountOfBuildings, Building** _buildingArr) : projectName(_projectName), amountOfBuildings(_amountOfBuildings)
{
	buildingArr = new Building * [amountOfBuildings];
	for (int i = 0; i < amountOfBuildings; i++)
	{
		buildingArr[i] = _buildingArr[i];
	}
}
// ----------------------Copy c'tor------------------------
Project::Project(const Project& copy)
{
	if (this != &copy)
	{
		this->projectName = copy.projectName;
		this->amountOfBuildings = copy.amountOfBuildings;

		buildingArr = new Building * [amountOfBuildings];
		for (int i = 0; i < amountOfBuildings; i++)
		{
			buildingArr[i] = copy.buildingArr[i];
		}
	}
	else
	{
		cout << "Same objects" << endl; // Executes if the objects are equal
	}
}
// ------------------------D'tor---------------------------
Project::~Project()
{
	if (buildingArr)
	{
		for (int i = 0; i < amountOfBuildings; i++)
		{
			delete buildingArr[i];
		}
		delete[] buildingArr;
	}
}
// ---------------------Class Methods----------------------
// --------------------------------------------------------
void Project::printProjectDetails() const
{
	cout << "-----Project Details-----" << endl;
	cout << "Project Name: " << projectName << endl;
	cout << "Amount Of Buildings: " << amountOfBuildings << endl;

	for (int i = 0; i < amountOfBuildings; i++)
	{
		cout << "Building #" << i + 1 << ": ";
		buildingArr[i]->printBulidingAprt();
	}
}
// --------------------------------------------------------
void Project::addBuilding(Building* object)
{
	Building** tempBuildingArr = new Building * [amountOfBuildings + 1]; // Creating a temp Building array with 1 extra size
	for (int i = 0; i < amountOfBuildings; i++)
	{
		tempBuildingArr[i] = buildingArr[i]; // Stores in the temp array the previous data from the original array
	}
	tempBuildingArr[amountOfBuildings] = object; // Stores in the last place in the temp array the new Apartmen
	this->amountOfBuildings++; // Incremants the 'amountOfBuildings' by 1

	delete[] buildingArr; // Deletes the previous 'buildingArr' data

	buildingArr = tempBuildingArr; // 'buildingArr' points to the temp array address
}
// --------------------------------------------------------
int Project::amountOfApartByAddress(string _address) const
{
	int amount;

	for (int i = 0; i < amountOfBuildings; i++)
	{
		if (buildingArr[i]->getAddress() == _address) // Condtion for a matching address
		{
			amount = buildingArr[i]->getAmountOfApartments(); // Stores in 'amount' the amount of Apartments in the required Building
			cout << "The amount of apartments in the #" << i + 1 << " building: " << amount << endl; // Prints the amount of Apartments
			return amount; // Returns the amount of Apartments
		}
		else
		{
			return -1;
		}
	}
}
// --------------------------------------------------------
string Project::getProjectName() const
{
	return this->projectName;
}
// --------------------------------------------------------
int Project::getAmountOfBuildings() const
{
	return this->amountOfBuildings;
}
// --------------------------------------------------------
int Project::getAmountOfApartByBuilding(int index) const
{
	return buildingArr[index]->getAmountOfApartments();
}
// --------------------------------------------------------
string Project::getBuilidingAddress(int index) const
{
	return buildingArr[index]->getAddress();
}
// --------------------------------------------------------
void Project::printPenthouseApart(int index) const
{
	buildingArr[index]->printPenthouseApart();
}
/* Assignment: 4
Author: Maor Atar, ID: 318301231
*/

#pragma once
#include "Building.h"

class Project
{
private:
	string projectName;
	int amountOfBuildings;
	Building** buildingArr;

public:
	Project() : projectName("None"), amountOfBuildings(0), buildingArr(NULL) {}; // Default c'tor
	Project(string, int, Building**); // Customized c'tor
	Project(const Project&); // Copy c'tor
	virtual ~Project(); // D'tor

	// Class Methods:
	void printProjectDetails() const; // Function to print the Project details
	void addBuilding(Building*); // Function to add a Building to the project
	int amountOfApartByAddress(string) const; // Function to get the amount of Apartments using an address
	string getProjectName() const; // Function to get the Project Name
	int getAmountOfBuildings() const; // Function to get the amount of Buildings in the Project
	int getAmountOfApartByBuilding(int) const; // Function to get the amount of Apartments in a specific Building 
	string getBuilidingAddress(int) const; // Function to get a specific Building address
	void printPenthouseApart(int) const; // Function to print Penthouse Apartment in a specific Building
};


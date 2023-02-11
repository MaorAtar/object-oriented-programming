/* Assignment: 1
Author: Maor Atar, ID: 318301231
*/

#include "Student.h"
// Customized c'tor
Student::Student(char _fullName[MAX_WORD_LENGTH], char _idNumber[MAX_ID_LENGTH], int _numOfYears, int _numOfCourses, char** _coursesNames, int* _grades, bool _scholarship)
{
	setfullName(_fullName);
	setidNumber(_idNumber);
	setnumOfYears(_numOfYears);
	setnumOfCourses(_numOfCourses);
	this->numOfYears = _numOfYears;
	this->numOfCourses = _numOfCourses;
	setCourses(_numOfCourses, _grades, _coursesNames);
	this->scholarship = _scholarship;
}
// Copy c'tor
Student::Student(const Student& other) : numOfYears(other.numOfYears), numOfCourses(other.numOfCourses), scholarship(other.scholarship)
{
	int i;

	strcpy(fullName, other.fullName);
	strcpy(idNumber, other.idNumber);
	grades = other.grades;
	coursesNames = new char* [numOfCourses];

	for (i = 0; i < numOfCourses; i++)
	{
		coursesNames[i] = other.coursesNames[i];
	}
}
// D'tor
Student::~Student()
{
	int i;

	if (coursesNames)
	{
		for (i = 0; i < numOfCourses; i++)
		{
			delete[] coursesNames[i];
		}
		delete[] coursesNames;
	}

	if (grades)
	{
		delete[] grades;
	}
	cout << "***Object Deleted!***" << endl;
}
// "Get" functions:
char* Student::getfullName()
{
	return this->fullName;
}

char* Student::getidNumber()
{
	return this->idNumber;
}

int Student::getnumOfYears() const
{
	return this->numOfYears;
}

int Student::getnumOfCourses() const
{
	return this->numOfCourses;
}

char** Student::getcoursesNames() const
{
	return this->coursesNames;
}

int* Student::getGrades() const
{
	return this->grades;
}

bool Student::getscholarship() const
{
	return this->scholarship;
}
// "Set" functions:
void Student::setfullName(char _fullName[MAX_WORD_LENGTH])
{
	// Check for a vaild name
	if (strlen(_fullName) > MAX_WORD_LENGTH)
	{
		strcpy(fullName, "Unknown");
	}
	else if (!checkForChars(_fullName))
	{
		strcpy(fullName, "Unknown");
	}
	else
	{
		strcpy(fullName, _fullName);
	}
}

void Student::setidNumber(char _idNumber[MAX_ID_LENGTH])
{
	// Check for a vaild ID
	if (strlen(_idNumber) > MAX_ID_LENGTH)
	{
		strcpy(idNumber, "000000000");
	}
	else if (!checkForNums(_idNumber))
	{
		strcpy(idNumber, "000000000");
	}
	else
	{
		strcpy(idNumber, _idNumber);
	}
}

void Student::setnumOfYears(int _numOfYears)
{
	if (_numOfYears < 1)
	{
		this->numOfYears = 0;
		this->coursesNames = NULL;
		this->grades = NULL;
	}
	this->numOfYears = _numOfYears;
}

void Student::setnumOfCourses(int _numOfCourses)
{
	if (_numOfCourses < 1)
	{
		this->numOfCourses = 0;
		this->coursesNames = NULL;
		this->grades = NULL;
	}
	this->numOfCourses = _numOfCourses;
}

void Student::setCourses(int _numOfCourses, int* _grades, char** _coursesNames)
{
	int i;

	this->coursesNames = new char* [_numOfCourses];
	for (i = 0; i < _numOfCourses; i++)
	{
		coursesNames[i] = new char[MAX_WORD_LENGTH];
	}
	this->grades = new int[_numOfCourses];

	this->coursesNames = _coursesNames;
	this->grades = _grades;

	for (i = 0; i < _numOfCourses; i++)
	{
		coursesNames[i] = _coursesNames[i];
	}
}

void Student::setscholarship(bool _scholarship)
{
	this->scholarship = _scholarship;
}
// Function to calculate the average grade:
float Student::gradesAvg() const
{
	int i;
	float average = 0.0;

	if ((numOfCourses < 0) || (numOfYears < 0)) // If executes average = 0
	{
		return average;
	}
	else
	{
		for (i = 0; i < numOfCourses; i++)
		{
			if (grades[i] < 0) // Check for a vaild grade entered
			{
				return average; // Average = 0
			}
			average += grades[i];
		}
		return average / numOfCourses;
	}
}
// Function to calculate the total tuition:
int Student::totalTuition() const
{
	if (numOfCourses < 1 || numOfYears < 1)
	{
		return 0;
	}
	if (scholarship == true) // Condition executes if the student has a scholarship
	{
		return (3000 * numOfCourses) + (1000 * numOfYears) - 2000;
	}
	else // Condition executes if the student dosen't have a scholarship
	{
		return (3000 * numOfCourses) + (1000 * numOfYears);
	}
}
// Function to print all the student details:
void Student::showDetails()
{
	int i, tuition = 0;
	float avg = 0.0;

	cout << "Student Name: " << fullName << ", ID: " << idNumber << ", Year of study: " << numOfYears << ", Scholarship: "; // Prints the student details
	if (scholarship == true)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	cout << "Grade sheet: " << endl;
	if (numOfCourses < 1 || numOfYears < 1) // Condition for a wrong input/the student don't have any completed courses
	{
		cout << "\tNo completed courses" << endl;
	}
	else // Condition to print all the courses details
	{
		for (i = 0; i < numOfCourses; i++)
		{
			cout << "\t" << coursesNames[i] << " - " << grades[i] << endl;
		}
	}

	tuition = totalTuition();
	cout << "Tuition Fees: " << tuition << endl;

	avg = gradesAvg();
	cout << "Average: " << avg << endl;
}
// Assistance function:
bool Student::checkForChars(char* str)
{
	int i = 0, flag = 0;

	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == ' ')
		{
			flag++;
		}
		i++;
	}
	if (flag != strlen(str))
	{
		return false;
	}
	return true;
}
// Assistance function:
bool Student::checkForNums(char* str)
{
	int i = 0, flag = 0;

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			flag++;
		}
		i++;
	}
	if (flag != strlen(str))
	{
		return false;
	}
	return true;
}

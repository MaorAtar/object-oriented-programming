/* Assignment: 1
Author: Maor Atar, ID: 318301231
*/
#define _CRT_SECURE_NO_WARNINGS // On my computer Visual Studio asks me to define CRT
#define MAX_WORD_LENGTH 51
#define MAX_ID_LENGTH 10

#include <iostream>
#include <string.h>

using namespace std;

class Student
{
private:
	char fullName[MAX_WORD_LENGTH], idNumber[MAX_ID_LENGTH];
	int numOfYears, numOfCourses;
	char** coursesNames;
	int* grades;
	bool scholarship;
	bool checkForNums(char* str), checkForChars(char* str); // Assistance functions
public:
	Student() : fullName("Unknown"), idNumber("000000000"), numOfYears(0), numOfCourses(0), coursesNames(NULL), grades(NULL), scholarship(false) {}; // Default c'tor
	Student(char [MAX_WORD_LENGTH], char [MAX_ID_LENGTH], int, int, char** , int*, bool); // Customized c'tor
	Student(const Student&); // Copy c'tor
	~Student(); // D'tor
	// "Get" functions:
	char* getfullName();
	char* getidNumber();
	int getnumOfYears() const;
	int getnumOfCourses() const;
	char** getcoursesNames() const;
	int* getGrades() const;
	bool getscholarship() const;
	// "Set" functions:
	void setfullName(char [MAX_WORD_LENGTH]);
	void setidNumber(char [MAX_ID_LENGTH]);
	void setnumOfYears(int);
	void setnumOfCourses(int);
	void setCourses(int, int*, char**); // Function to set all the courses
	void setscholarship(bool);
	float gradesAvg() const; // Function to calculate the average grade
	int totalTuition() const; // Function to calculate the total tuition
	void showDetails(); //Function to print all the student details
};

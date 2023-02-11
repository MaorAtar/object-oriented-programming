/* Assignment: 2
Author: Maor Atar, ID: 318301231
*/

#include <iostream>

using namespace std;

class boolArray
{
private:
	bool* array;
	int arrayLength;
	void initializeArray(int _arrayLength); // Assistance function
	bool indexCheck(int) const; // Assistance function

public:
	boolArray() : array(NULL), arrayLength(0) {}; // Default c'tor initialize "array" to "NULL" and "arrayLength" to 0
	boolArray(int); // Customized c'tor
	~boolArray(); // D'tor
	// Methods:
	void updateArray(int);
	void getArrayValues();
	void changeArrayValue(bool, int);
	bool returnValue(int) const;
	void printArray() const;
};

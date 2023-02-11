/* Assignment: 5
Author: Maor Atar, ID: 318301231
*/

#pragma once
#include <iostream>
using namespace std;

template <class K, class V>
class Map {
	K* keysArr;
	V* valuesArr;
	int size;

public:
	Map() : size(0), keysArr(NULL), valuesArr(NULL) {}; // Default c'tor
	Map(int, K[], V[]); // Customized c'tor
	Map(const Map&); // Copy c'tor
	~Map(); // D'tor

	// Class Methods:
	bool containsKey(K) const; // Function to check if a Map contains a specific Key
	bool containsValue(V) const; // Function to check if a Map contatins a specific Value
	K* keySet() const; // Function to return the Map Keys
	V* mapValues() const; // Function to return the Map Values
	string getkeysType() const; // Function to get the Keys type
	string getvaluesType() const; // Function to get the Values type

	// Overloading Functions:
	V& operator [] (const K&); // Operator to place in a specific Key a Value
	Map& operator = (const Map&); // Operator '='
	bool operator == (const Map&) const; // Operator to check for the same Map
	friend ostream& operator << (ostream& output, const Map<K, V>& map) { // Operator to print the Map
		output << "Keys type: " << map.getkeysType() << endl;
		output << "Values type: " << map.getvaluesType() << endl;
		if (map.size == 0)
		{
			output << "Map keys: {}" << endl;
			output << "Map values: {}" << endl;;
			return output;
		}
		else
		{
			output << "Map size: " << map.size << endl;
			output << "Map keys: {";
			for (int i = 0; i < map.size - 1; i++)
			{
				output << map.keysArr[i] << ", ";
			}
			output << map.keysArr[map.size - 1];
			output << "}" << endl;
			output << "Map values: {";
			for (int i = 0; i < map.size - 1; i++)
			{
				output << map.keysArr[i] << "=" << map.valuesArr[i] << ", ";
			}
			output << map.keysArr[map.size - 1] << "=" << map.valuesArr[map.size - 1];
			output << "}" << endl;
			output << "****************************" << endl;
			return output;
		}
	};
};

// -------------------Customized c'tor---------------------
template <class K, class V>
Map<K, V>::Map(int _size, K _keysArr[], V _valuesArr[])
{
	if (sizeof(*_keysArr) / sizeof(_keysArr[0]) != sizeof(*_valuesArr) / sizeof(_valuesArr[0])) // Condition to check that the sizes of the arrays are equal
	{
		throw invalid_argument("Sizes of the arrays must be equal"); // Throws 'invalid_argument' exception
	}

	for (int i = 0; i < _size; i++) // Outter loop to loop through each element in the array
	{
		for (int j = 0; j < _size; j++) // Inner loop to loop through each element in the array
		{
			if (j != i) // Condition to skip the same element check
			{
				if (_keysArr[i] == _keysArr[j]) // Condition to check for a duplicated key in the array
				{
					throw invalid_argument("Keys must be unique"); // Throws 'invalid_argument' exception
				}
			}
		}
	}
	// Executes if the Map is valid
	this->size = _size; // Updates 'size' with the size of the Map
	keysArr = new K[size]; // Allocates new memory for the Keys array
	valuesArr = new V[size]; // Allocates new memory for the Values array
	for (int i = 0; i < size; i++) // Loop to stores in the Keys, Values arrays the Map Keys, Values
	{
		keysArr[i] = _keysArr[i];
		valuesArr[i] = _valuesArr[i];
	}
}
// ----------------------Copy c'tor------------------------
template <class K, class V>
Map<K, V>::Map(const Map& object)
{
	if (this != object) // Checks for different Maps
	{
		this->size = object.size; // Updates 'size' with the size of the Map
		keysArr = new K[size]; // Allocates new memory for the Keys array
		valuesArr = new V[size]; // Allocates new memory for the Values array

		for (int i = 0; i < size; i++) // Loop to stores in the Keys, Values arrays the Map Keys, Values
		{
			keysArr[i] = object.keysArr[i];
			valuesArr[i] = object.valuesArr[i];
		}
	}
	else // Executes if the Maps are equal
	{
		cout << "Same Maps" << endl;
	}
}
// ------------------------D'tor---------------------------
template <class K, class V>
Map <K, V>::~Map()
{
	if (keysArr) // Condition to check if 'keysArr' != NULL
	{
		delete[] keysArr; // Deletes the memory used by 'keysArr'
	}

	if (valuesArr) // Condition to check if 'valuesArr' != NULL
	{
		delete[] valuesArr; // Deletes the memory used by 'valuesArr'
	}
}
// -----------------Overloading Functions------------------
template <class K, class V>
V& Map<K, V>::operator [] (const K& key)
{
	if (key > 0 && key <= size) // Condition to check if the key is within the size limites
	{
		return valuesArr[key - 1]; // If executes returns the required placement of the Value
	}
	else if (size == 0) // Condition for an empty Map
	{
		this->size++; // Increments 'size' by 1
		keysArr = new K[size]; // Allocates new memory for the Keys array
		keysArr[0] = key; // Stores the Key in the Map 'keysArr'
		valuesArr = new V[size]; // Allocates new memory for the Values array
		return valuesArr[0]; // Returns the first placement of the Value
	}
	else
	{
		this->size++; // Increments 'size' by 1

		// Uses a temp arrays to copy the old data from the Map arrays
		K* tempKeysArr = new K[size];
		V* tempValuesArr = new V[size];

		for (int i = 0; i < size - 1; i++) // 'size - 1' because we want to use the old size
		{
			tempKeysArr[i] = keysArr[i];
			tempValuesArr[i] = valuesArr[i];
		}

		delete[] keysArr; // Deletes the memory used by 'keysArr'
		delete[] valuesArr; // Deletes the memory used by 'valuesArr'

		keysArr = tempKeysArr; // 'keysArr' points to 'tempKeysArr' address
		keysArr[size - 1] = key; // Stores in the new index the new Key
		valuesArr = tempValuesArr; // 'valuesArr' points to 'tempValuesArr' address
		return valuesArr[size - 1]; // Returns the required placement of the Value
	}
}
// --------------------------------------------------------
template <class K, class V>
Map<K, V>& Map<K, V>::operator = (const Map& object)
{
	delete[] keysArr; // Deletes the memory used by 'keysArr'
	delete[] valuesArr; // Deletes the memory used by 'valuesArr'

	this->size = object.size; // Updates 'size' with the size of the Map

	keysArr = new K[size]; // Allocates new memory for the Keys array
	valuesArr = new V[size]; // Allocates new memory for the Values array

	for (int i = 0; i < size; i++) // Loop to stores in the Keys, Values arrays the Map Keys, Values
	{
		keysArr[i] = object.keysArr[i];
		valuesArr[i] = object.valuesArr[i];
	}

	return *this; // Returns the Map after the update
}
// --------------------------------------------------------
template <class K, class V>
bool Map<K, V>::operator == (const Map& object) const
{
	if (size != object.size) // Condition to check for a different size of the Maps
	{
		return false; // If executes the Maps are not the same, returns false
	}

	for (int i = 0; i < size; i++) // Loop to check for a different Key\Value in the Maps
	{
		if ((keysArr[i] != object.keysArr[i]) || (valuesArr[i] != object.valuesArr[i]))
		{
			return false; // If executes the Maps are not the same, returns false
		}
	}
	return true; // If the conditions didn't executes, means that the Maps are the same, returns true
}
// ---------------------Class Methods----------------------
template <class K, class V>
bool Map<K, V>::containsKey(K key) const
{
	for (int i = 0; i < size; i++) // Loops through the Map 'keysArr' array
	{
		if (keysArr[i] == key) // Condition to check for the same Key
		{
			return true; // If the Key is in Map, returns true
		}
	}
	return false; // If the Key is not in the Map, returns false
}
// --------------------------------------------------------
template <class K, class V>
bool Map<K, V>::containsValue(V value) const
{
	for (int i = 0; i < size; i++) // Loops through the Map 'valuesArr' array
	{
		if (valuesArr[i] == value) // Condition to check for the same Value
		{
			return true; // If the Value is in Map, returns true
		}
	}
	return false; // If the Value is not in the Map, returns false
}
// --------------------------------------------------------
template <class K, class V>
K* Map<K, V>::keySet() const
{
	return this->keysArr; // Returns the Keys array
}
// --------------------------------------------------------
template <class K, class V>
V* Map<K, V>::mapValues() const
{
	return this->valuesArr; // Returns the Values array
}
// --------------------------------------------------------
template <class K, class V>
string Map<K, V>::getkeysType() const
{
	return typeid(*keysArr).name(); // Uses 'typeid' function to return the type of the Keys
}
// --------------------------------------------------------
template <class K, class V>
string Map<K, V>::getvaluesType() const
{
	return typeid(*valuesArr).name(); // Uses 'typeid' function to return the type of the Values
}
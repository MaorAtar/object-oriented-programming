/* Assignment: 5
Author: Maor Atar, ID: 318301231
*/

#include "Map.h"

int main() {
	Map<int, char> int2charMap1;
	cout << "-------------" << endl;
	cout << "int2charMap1: " << endl;
	cout << "-------------" << endl;
	cout << int2charMap1;

	int2charMap1[1] = 'a';
	int2charMap1[2] = 'b';
	int2charMap1[3] = 'c';
	cout << "-------------" << endl;
	cout << "int2charMap1: " << endl;
	cout << "-------------" << endl;
	cout << int2charMap1;

	int2charMap1[3] = '!';
	cout << "-------------" << endl;
	cout << "int2charMap1: " << endl;
	cout << "-------------" << endl;
	cout << int2charMap1;

	cout << "Keys type:" << int2charMap1.getkeysType() << endl;
	cout << "Values type:" << int2charMap1.getvaluesType() << endl;

	int ints2[] = { 4, 5, 6 };
	char chars2[] = { 'd', 'e', 'f' };
	Map<int, char> int2charMap2(3, ints2, chars2);
	cout << "-------------" << endl;
	cout << "int2charMap2: " << endl;
	cout << "-------------" << endl;
	cout << int2charMap2;

	int2charMap1 = int2charMap2;
	cout << "-------------" << endl;
	cout << "int2charMap1: " << endl;
	cout << "-------------" << endl;
	cout << int2charMap1;


	int ints3[] = { 4, 5, 4, 6 };
	char chars3[] = { 'd', 'e', 'f', 'g' };
	try {
		Map<int, char> int2charMap3(4, ints3, chars3);
	}
	catch (invalid_argument e) {
		cout << "-------------------------------------" << endl;
		cout << "Invalid argument: " << e.what() << endl;
		cout << "-------------------------------------" << endl;
	}

	Map<int, char> int2charMap4;
	cout << "-------------" << endl;
	cout << "int2charMap4: " << endl;
	cout << "-------------" << endl;
	cout << int2charMap4;

	int2charMap4[4] = 'a';
	int2charMap4[5] = 'b';
	int2charMap4[6] = 'c';
	cout << "-------------" << endl;
	cout << "int2charMap1: " << endl;
	cout << "-------------" << endl;
	cout << int2charMap1;

	if (int2charMap1 == int2charMap2) {
		cout << "------------------------------------------" << endl;
		cout << "-int2charMap1 and int2charMap2 are equals-" << endl;
		cout << "------------------------------------------" << endl;
	}
	else {
		cout << "----------------------------------------------" << endl;
		cout << "-int2charMap1 and int2charMap2 are not equals-" << endl;
		cout << "----------------------------------------------" << endl;
	}
	cout << endl;
	if (int2charMap1 == int2charMap4) {
		cout << "------------------------------------------" << endl;
		cout << "-int2charMap1 and int2charMap4 are equals-" << endl;
		cout << "------------------------------------------" << endl;
	}
	else {
		cout << "----------------------------------------------" << endl;
		cout << "-int2charMap1 and int2charMap4 are not equals-" << endl;
		cout << "----------------------------------------------" << endl;
	}

	return 0;
}
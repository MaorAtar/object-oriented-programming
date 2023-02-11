/* Assignment: 4
Author: Maor Atar, ID: 318301231
*/

#include <iostream>
#include <time.h>

using namespace std;
// Class builded in 'Lab 2'
class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date(); // Default c'tor
	Date(int d, int m, int y); // Customized c'tor
	~Date(); // D'tor

	// Class Methods:
	int getDay();
	int getMonth();
	int getYear();
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	void printDate();
	void printMonthInWords();
	int amountOfDays();
	bool checkLeapYear();
	void nextDayDate();
};
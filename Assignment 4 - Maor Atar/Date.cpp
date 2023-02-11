/* Assignment: 4
Author: Maor Atar, ID: 318301231
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"

Date::Date()
{
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	day = timeinfo->tm_mday;
	month = timeinfo->tm_mon + 1;
	year = timeinfo->tm_year + 1900;
}

Date::Date(int d, int m, int y) :day(d), month(m), year(y) {}

int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

int Date::getYear()
{
	return year;
}

void Date::setDay(int d)
{
	day = d;
}

void Date::setMonth(int m)
{
	month = m;
}

void Date::setYear(int y)
{
	year = y;
}

void Date::printDate()
{
	cout << day << "/" << month << "/" << year << endl;
}

void Date::printMonthInWords()
{
	switch (month) {
	case 1:
		cout << "January" << endl;
		break;
	case 2:
		cout << "February" << endl;
		break;
	case 3:
		cout << "March" << endl;
		break;
	case 4:
		cout << "April" << endl;
		break;
	case 5:
		cout << "May" << endl;
		break;
	case 6:
		cout << "June" << endl;
		break;
	case 7:
		cout << "July" << endl;
		break;
	case 8:
		cout << "August" << endl;
		break;
	case 9:
		cout << "September" << endl;
		break;
	case 10:
		cout << "October" << endl;
		break;
	case 11:
		cout << "November" << endl;
		break;
	case 12:
		cout << "December" << endl;
		break;
	default:
		cout << "Month entered is invalid" << endl;
	}
}

int Date::amountOfDays()
{
	enum months { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };

	if (month == Jan || month == Mar || month == May || month == Jul || month == Aug || month == Oct || month == Dec)
	{
		return 31;
	}
	if (month == Apr || month == Jun || month == Sep || month == Nov)
	{
		return 30;
	}
	if (month == Feb)
	{
		return 28;
	}
}

bool Date::checkLeapYear()
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Date::~Date()
{
	cout << "Deleting: " << day << "/" << month << "/" << year << endl;
};

void Date::nextDayDate()
{
	if (day < amountOfDays())
	{
		day++;
	}
	if (day == amountOfDays() && month < 12)
	{
		day = 1;
		month++;
	}
	if (day == amountOfDays() && month == 12)
	{
		day = 1;
		month = 1;
		year++;
	}
}
#include <iostream>
#pragma once
using namespace std;

class Date
{
	int year, month, day;
	string intToMonth(int _month) const;
public:
	Date(int _year = 1300, int _month = 1, int _day = 1);
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	string getDate() const;
	string getStrDate() const;
	void setDate(int _year, int _month, int _day);
	void setYear(int _year);
	void setMonth(int _month);
	void setDay(int _day);
};


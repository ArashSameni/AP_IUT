#include "Date.h"
#include <string>

string Date::intToMonth(int _month) const {
	switch (_month)
	{
	case 1:
		return "farvardin";
	case 2:
		return "ordibehesht";
	case 3:
		return "khordad";
	case 4:
		return "tir";
	case 5:
		return "mordad";
	case 6:
		return "shahrivar";
	case 7:
		return "mehr";
	case 8:
		return "aban";
	case 9:
		return "azar";
	case 10:
		return "dey";
	case 11:
		return "bahman";
	case 12:
		return "esfand";
	default:
		return "|:";
	}
}

Date::Date(int _year, int _month, int _day) {
	year = _year;
	month = _month;
	day = _day;
}

int Date::getYear() const { return year; }

int Date::getMonth() const { return month; }

int Date::getDay() const { return day; }

string Date::getDate() const {
	return to_string(year) + "/" + to_string(month) + "/" + to_string(day);
}

string Date::getStrDate() const {
	string _month = intToMonth(month);
	return to_string(day) + " " + _month + " " + to_string(year);
}
void Date::setDate(int _year, int _month, int _day)
{
	if (_year <= 0 || _month <= 0 || _month > 12 || _day <= 0 || _day > 31)
		return;
	year = _year;
	month = _month;
	day = _day;
}

void Date::setYear(int _year) {
	if (_year <= 0)
		return;
	year = _year;
}
void Date::setMonth(int _month) {
	if (_month <= 0 || _month > 12)
		return;
	month = _month;
}
void Date::setDay(int _day) {
	if (_day <= 0 || _day > 31)
		return;
	day = _day;
}
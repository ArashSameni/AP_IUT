#include "Date.h"

Date::Date(int _year, int _month, int _day)
{
    year = _year;
    month = _month;
    day = _day;
}

void Date::setDate(int _year, int _month, int _day)
{
    if (isValidDate(_year, _month, _day))
    {
        year = _year;
        month = _month;
        day = _day;
    }
    else
        cout << "Date is not valid" << endl;
}

void Date::setYear(int _year)
{
    if (_year >= 1973 && _year <= 9999)
        year = _year;
    else
        cout << "Error: Invalid year (1973-9999)!" << endl;
}

int Date::getYear() { return year; }

void Date::setMonth(int _month)
{
    if (_month >= 1 && _month <= 12)
        month = _month;
    else
        cout << "Month is not valid" << endl;
}

int Date::getMonth() { return month; }

void Date::setDay(int _day)
{
    if (isValidDay(year, month, _day))
        day = _day;
    else
        cout << "Day is not invalid" << endl;
}

void Date::print()
{
    print(year, month, day);
}

void Date::print(int _year, int _month, int _day)
{
    string s_month = getNameByMonth(_month);
    printDayOfWeek(_year, _month, _day);
    cout << ", " << _day << " " << s_month << " " << _year << endl;
}

Date &Date::nextDay()
{
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day == 31)
        {
            if (month != 12)
            {
                day = 1;
                month += 1;
            }
            else if (year < 9999)
            {
                year += 1;
                month = 1;
                day = 1;
            }
            else
                cout << "Error: Next day is out of range!" << endl;
        }
        else
            day += 1;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day == 30)
        {
            day = 1;
            month += 1;
        }
        else
            day += 1;
    }
    else // month == 2
    {
        if ((day == 28 && !isLeap(year)) || (day == 29 && isLeap(year)))
        {
            day = 1;
            month += 1;
        }
        else
            day += 1;
    }
    return *this;
}

Date &Date::prevDay()
{
    if (day > 1)
        day -= 1;
    else
    {
        if (month - 1 == 1 || month - 1 == 3 || month - 1 == 5 || month - 1 == 7 || month - 1 == 8 || month - 1 == 10 || month - 1 == 0)
        {
            if (month - 1 != 0)
            {
                day = 31;
                month -= 1;
            }
            else if (year > 1973)
            {
                day = 31;
                month = 12;
                year -= 1;
            }
            else
                cout << "Error: Previous day is out of range!" << endl;
        }
        else if (month - 1 == 4 || month - 1 == 6 || month - 1 == 9 || month - 1 == 11)
        {
            day = 30;
            month -= 1;
        }
        else // month -1 == 2
        {
            if (isLeap(year))
                day = 29;
            else
                day = 28;

            month -= 1;
        }
    }
    return *this;
}

void Date::fixDay()
{
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        day = 30;
    else if (month == 2)
    {
        if (isLeap(year) && day > 29)
            day = 29;
        else if (day > 28)
            day = 28;
    }
}

Date &Date::nextMonth()
{
    if (month != 12)
        month += 1;
    else if (year < 9999)
    {
        month = 1;
        year += 1;
    }
    else
        cout << "Error: Next month is out of range!" << endl;
    fixDay();
    return *this;
}

Date &Date::prevMonth()
{
    if (month != 1)
        month -= 1;
    else if (year > 1973)
    {
        month = 12;
        year -= 1;
    }
    else
        cout << "Error: Previous month is out of range!" << endl;

    fixDay();
    return *this;
}

Date &Date::nextYear()
{
    if (year < 9999)
    {
        if (isLeap(year) && month == 2 && day == 29)
            day = 28;
        year += 1;
    }
    else
        cout << "Error: Next year is out of range!" << endl;
    return *this;
}

Date &Date::prevYear()
{
    if (year > 1973)
    {
        if (isLeap(year) && month == 2 && day == 29)
            day = 28;
        year -= 1;
    }
    else
        cout << "Error: Previous year is out of range!" << endl;
    return *this;
}

bool Date::isLeap(int _year)
{
    if (_year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0))
        return true;
    return false;
}

bool Date::isValidDay(int _year, int _month, int _day)
{
    if (_day < 1 || _day > 31)
        return false;

    if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12)
    {
        if (_day > 31)
            return false;
    }
    else if (_month == 4 || _month == 6 || _month == 9 || _month == 11)
    {
        if (_day > 30)
            return false;
    }
    else // _month == 2
    {
        if (isLeap(_year) && _day > 29)
            return false;
        else if (!isLeap(_year) && _day > 28)
            return false;
    }
    return true;
}

bool Date::isValidDate(int _year, int _month, int _day)
{
    if (_year < 1973 || _year > 9999)
        return false;
    if (_month < 1 || _month > 12)
        return false;
    if (!isValidDay(_year, _month, _day))
        return false;

    return true;
}

int Date::getDayOfWeek()
{
    return getDayOfWeek(year, month, day);
}

int Date::getDayOfWeek(int _year, int _month, int _day)
{
    static int t[] = {0, 3, 2, 5, 0, 3,
                      5, 1, 4, 6, 2, 4};
    _year -= _month < 3;
    return (_year + _year / 4 - _year / 100 +
            _year / 400 + t[_month - 1] + _day) %
           7;
}

string Date::getNameByDay(int _day)
{
    switch (_day)
    {
    case 0:
        return "Sunday";
    case 1:
        return "Monday";
    case 2:
        return "Tuesday";
    case 3:
        return "Wednesday";
    case 4:
        return "Thursday";
    case 5:
        return "Friday";
    case 6:
        return "Saturday";
    }
    return "";
}

string Date::getNameByMonth(int _month)
{
    switch (_month)
    {
    case 1:
        return "Jan";
    case 2:
        return "Feb";
    case 3:
        return "Mar";
    case 4:
        return "Apr";
    case 5:
        return "May";
    case 6:
        return "Jun";
    case 7:
        return "Jul";
    case 8:
        return "Aug";
    case 9:
        return "Sep";
    case 10:
        return "Oct";
    case 11:
        return "Nov";
    case 12:
        return "Dec";
    }
    return "";
}

void Date::printDayOfWeek()
{
    printDayOfWeek(year, month, day);
}

void Date::printDayOfWeek(int _year, int _month, int _day)
{
    int day = getDayOfWeek(_year, _month, _day);
    cout << getNameByDay(day);
}
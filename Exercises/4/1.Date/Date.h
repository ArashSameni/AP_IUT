#include <iostream>
using namespace std;

class Date{
    int year, month, day;
    static bool isValidDay(int _year, int _month, int _day);
    static string getNameByDay(int _day);
    static string getNameByMonth(int _month);
    void fixDay();
public:
    Date(int _year = 1973, int _month = 1, int _day = 1);
    void setDate(int _year, int _month, int _day);
    void setYear(int _year);
    int getYear();
    void setMonth(int _month);
    int getMonth();
    void setDay(int _day);
    void print();
    static void print(int _year, int _month, int _day);
    Date& nextDay();
    Date& prevDay();
    Date& nextMonth();
    Date& prevMonth();
    Date& nextYear();
    Date& prevYear();
    static bool isLeap(int _year);
    static bool isValidDate(int _year, int _month, int _day);
    int getDayOfWeek();
    static int getDayOfWeek(int _year, int _month, int _day);
    void printDayOfWeek();
    static void printDayOfWeek(int _year, int _month, int _day);
};
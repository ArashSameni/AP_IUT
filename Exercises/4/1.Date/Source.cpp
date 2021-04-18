#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
    Date date1(2020, 1, 1);
    date1.print();
    date1.nextDay().print();
    date1.print();

    date1.setDate(2021, 1, 31);
    date1.print();
    date1.nextDay().print();

    date1.setDate(2020, 2, 28);
    date1.print();
    date1.nextDay().print();

    date1.setDate(2020, 12, 31);
    date1.print();
    date1.nextDay().print();

    date1.setYear(1600);
    date1.print();
    date1.setDay(31);
    date1.print();
    date1.nextMonth().nextMonth().nextMonth();
    date1.print();
    date1.setDay(31);
    date1.print();

    if (Date::isValidDate(2021, 2, 29))
    {
        cout << "Date is valid" << endl;
    }
    else
    {
        cout << "Date is not valid" << endl;
    }

    if (Date::isLeap(2000))
    {
        cout << "2000 is leap year" << endl;
    }
    else
    {
        cout << "2000 is not leap year" << endl;
    }

    if (Date::isValidDate(2021, 1, 1))
    {
        Date::print(2021, 1, 1);
    }

    Date *date4 = nullptr;
    date4 = new Date(9999, 12, 30);
    date4->nextDay().print();
    date4->nextDay();
    date4->print();
    delete date4;

    Date date5(2021, 1, 1);
    date5.prevDay().print();

    Date date6(2021, 3, 31);
    date6.nextMonth().print();

    Date date7(2020, 3, 31);
    date7.prevMonth().print();

    Date date8(2020, 2, 29);
    date8.nextYear().print();

    Date date9(2020, 2, 29);
    date9.prevYear().print();
    return 0;
}
#include "hourlyPay.h"

HourlyPay::HourlyPay(Employee arg_employee,
                     EmployeePay arg_employeePay,
                     int arg_weeklyWorkedHours) : Employee(arg_employee), EmployeePay(arg_employeePay)
{
    setWeeklyWorkedHours(arg_weeklyWorkedHours);
}

float HourlyPay::getHourlyPaymentRate() const { return hourlyPaymentRate; }
float HourlyPay::getOvertimePaymentRate() const { return overtimePaymentRate; }
int HourlyPay::getWeeklyWorkedHours() const { return weeklyWorkedHours; }

bool HourlyPay::setWeeklyWorkedHours(int arg_hours)
{
    if (arg_hours >= 0 && arg_hours <= 60)
    {
        weeklyWorkedHours = arg_hours;
        return 1;
    }
    std::cout << "Working hours should be between 0 and 60 hours" << std::endl;
    return 0;
}

std::istream &operator>>(std::istream &in, HourlyPay &obj)
{
    int worked_hours;

    std::cout << "Weekly worked hours: ";
    in >> worked_hours;
    while (!obj.setWeeklyWorkedHours(worked_hours))
    {
        std::cout << "Weekly worked hours: ";
        in >> worked_hours;
    }

    obj.calculateRates();
    return in;
}

std::ostream &operator<<(std::ostream &out, const HourlyPay &obj)
{
    Employee emp = obj;
    out << "--> " << emp;

    EmployeePay emp_pay = (HourlyPay)obj;
    out << "--> " << emp_pay;

    out << "--> "
        << "Hourly Payment Rate: " << obj.hourlyPaymentRate
        << ", Overtime Payment Rate: " << obj.overtimePaymentRate
        << ", Weekly Worked Hours: " << obj.weeklyWorkedHours
        << std::endl;

    return out;
}

void HourlyPay::calculateRates()
{
    const int payment_per_week = getWeeklyPayment();
    const int weekly_worked_hours = getWeeklyWorkedHours();
    const int maximum = 40; //maximum hours of normal work per week
    const float hourly_payment = (float)payment_per_week / weekly_worked_hours;

    if (weekly_worked_hours <= maximum)
    {
        hourlyPaymentRate = hourly_payment;
        overtimePaymentRate = 0;
    }
    else
    {
        hourlyPaymentRate = hourly_payment * 0.4;
        overtimePaymentRate = hourly_payment * 0.6;
    }
}

void HourlyPay::printCheck(const HourlyPay& arg_hourlyPay)
{
    std::cout << arg_hourlyPay;
}
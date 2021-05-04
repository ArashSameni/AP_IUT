#pragma once
#include "employeePay.h"

class HourlyPay : public virtual EmployeePay
{
    float hourlyPaymentRate;
    float overtimePaymentRate;
    int weeklyWorkedHours;
    void calculateRates();

public:
    HourlyPay(Employee arg_employee,
              EmployeePay arg_employeePay,
              int arg_weeklyWorkedHours = 0);

    float getHourlyPaymentRate() const;
    float getOvertimePaymentRate() const;
    int getWeeklyWorkedHours() const;

    bool setWeeklyWorkedHours(int arg_hours);
    
    static void printCheck(const HourlyPay& arg_hourlyPay);

    friend std::istream& operator>>(std::istream& in, HourlyPay& obj);
    friend std::ostream& operator<<(std::ostream& out, const HourlyPay& obj);
};
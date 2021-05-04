#pragma once
#include "employee.h"

class EmployeePay : public virtual Employee
{
    int annualPayment;
    int weeklyPayment;

public:
    EmployeePay(Employee arg_employee, int arg_annualPayment = 0);

    int getAnnualPayment() const;
    int getWeeklyPayment() const;

    bool setAnnualPayment(int arg_annualPayment);

    friend std::istream &operator>>(std::istream &in, EmployeePay &obj);
    friend std::ostream &operator<<(std::ostream &out, const EmployeePay &obj);
};
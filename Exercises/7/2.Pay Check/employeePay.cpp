#include "employeePay.h"

EmployeePay::EmployeePay(Employee arg_employee, int arg_annualPayment) : Employee(arg_employee)
{
    setAnnualPayment(arg_annualPayment);
}

int EmployeePay::getAnnualPayment() const { return annualPayment; }
int EmployeePay::getWeeklyPayment() const { return weeklyPayment; }

bool EmployeePay::setAnnualPayment(int arg_annualPayment)
{
    const int weeksInYear = 52;
    if (arg_annualPayment >= 0)
    {
        annualPayment = arg_annualPayment;
        weeklyPayment = annualPayment / weeksInYear;
        return 1;
    }

    std::cout << "Annual payment is invalid" << std::endl;
    return 0;
}

std::istream &operator>>(std::istream &in, EmployeePay& obj)
{
    int annual_payment;

    std::cout << "Annual payment: ";
    in >> annual_payment;
    while (!obj.setAnnualPayment(annual_payment))
    {
        std::cout << "Annual payment: ";
        in >> annual_payment;
    }

    return in;
}

std::ostream &operator<<(std::ostream &out, const EmployeePay& obj)
{
    out << "Annual Payment: " << obj.annualPayment
        << ", Weekly Payment: " << obj.weeklyPayment
        << std::endl;
    return out;
}
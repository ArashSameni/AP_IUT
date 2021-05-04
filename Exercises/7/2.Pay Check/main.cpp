#include <iostream>
#include "employee.h"
#include "employeePay.h"
#include "hourlyPay.h"

int main()
{
    Employee emp;
    std::cin >> emp;

    EmployeePay emp_pay(emp);
    std::cin >> emp_pay;

    HourlyPay hourly_pay(emp, emp_pay);
    std::cin >> hourly_pay;

    HourlyPay::printCheck(hourly_pay);

    return 0;
}
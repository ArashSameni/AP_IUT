#pragma once
#include <iostream>
#include <regex>

class Employee
{
    std::string name;
    std::string employeeId;
    std::string socialSecurityNumber;

    bool isEmployeeIdValid(std::string arg_id) const;
    bool isSocialSecurityNumberValid(std::string arg_id) const;

public:
    Employee(std::string arg_name = "",
             std::string arg_employeeId = "000-00-000",
             std::string arg_socialSecurityNumber = "000-A");

    std::string getName() const;
    std::string getEmployeeId() const;
    std::string getSocialSecurityNumber() const;

    void setName(std::string arg_name);
    void setEmployeeId(std::string arg_employeeId);
    void setSocialSecurityNumber(std::string arg_socialSecurityNumber);

    friend std::istream &operator>>(std::istream &in, Employee &obj);
    friend std::ostream &operator<<(std::ostream &out, const Employee &obj);
};
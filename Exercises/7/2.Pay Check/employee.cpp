#include "employee.h"

Employee::Employee(std::string arg_name,
                   std::string arg_employeeId,
                   std::string arg_socialSecurityNumber)
{
    name = arg_name;

    if (isEmployeeIdValid(arg_employeeId))
        employeeId = arg_employeeId;
    else
        std::cout << "Employee id is incorrect" << std::endl;

    if (isSocialSecurityNumberValid(arg_socialSecurityNumber))
        socialSecurityNumber = arg_socialSecurityNumber;
    else
        std::cout << "Social security is incorrect" << std::endl;
}

std::string Employee::getName() const { return name; }
std::string Employee::getEmployeeId() const { return employeeId; }
std::string Employee::getSocialSecurityNumber() const { return socialSecurityNumber; }

void Employee::setName(std::string arg_name) { name = arg_name; }

void Employee::setEmployeeId(std::string arg_employeeId)
{
    if (isEmployeeIdValid(arg_employeeId))
        employeeId = arg_employeeId;
    else
        std::cout << "Employee id is incorrect" << std::endl;
}

void Employee::setSocialSecurityNumber(std::string arg_socialSecurityNumber)
{
    if (isSocialSecurityNumberValid(arg_socialSecurityNumber))
        socialSecurityNumber = arg_socialSecurityNumber;
    else
        std::cout << "Social security is incorrect" << std::endl;
}

bool Employee::isEmployeeIdValid(std::string arg_id) const
{
    // Valid Id: xxx-xx-xxx
    const std::regex regex_pattern("^\\d{3}-\\d{2}-\\d{3}$");
    return std::regex_match(arg_id, regex_pattern);
}

bool Employee::isSocialSecurityNumberValid(std::string arg_id) const
{
    // Valid Id: xxx-L
    const std::regex regex_pattern("^\\d{3}-[A-M]$");
    return std::regex_match(arg_id, regex_pattern);
}

std::istream &operator>>(std::istream &in, Employee &obj)
{
    std::cout << "Name: ";
    in >> obj.name;

    std::cout << "Employee-Id: ";
    in >> obj.employeeId;
    while (!obj.isEmployeeIdValid(obj.employeeId))
    {
        std::cout << "Employee-Id isn't valid. Valid format is xxx-xx-xxx" << std::endl;
        std::cout << "Employee-Id: ";
        in >> obj.employeeId;
    }

    std::cout << "Social Security Number: ";
    in >> obj.socialSecurityNumber;
    while (!obj.isSocialSecurityNumberValid(obj.socialSecurityNumber))
    {
        std::cout << "Social Security Number isn't valid. Valid format is xxx-L" << std::endl;
        std::cout << "Social Security Number: ";
        in >> obj.socialSecurityNumber;
    }

    return in;
}

std::ostream &operator<<(std::ostream &out, const Employee &obj)
{
    out << "Name: " << obj.name
        << ", Employee-Id: " << obj.employeeId
        << ", Social Security Number: " << obj.socialSecurityNumber << std::endl;
    return out;
}
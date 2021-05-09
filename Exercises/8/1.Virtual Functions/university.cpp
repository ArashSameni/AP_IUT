#include "university.h"
#include <numeric>

int professor::curid = 1;
int student::curid = 1;

professor::professor(std::string _name, int _age, int _publications)
{
    name = _name;
    age = _age;
    publications = _publications;
    id = curid++;
}

void professor::getdata()
{
    std::cin >> name;
    std::cin >> age;
    std::cin >> publications;
}

void professor::putdata()
{
    std::cout << name << " "
              << age << " "
              << publications << " "
              << id << std::endl;
}

//
student::student(std::string _name, int _age)
{
    name = _name;
    age = _age;
    id = curid++;
}

void student::getdata()
{
    std::cin >> name;
    std::cin >> age;
    for (int i = 0; i < 6; i++)
        std::cin >> marks[i];
}

void student::putdata()
{
    int marksTotal = std::accumulate(marks, marks + 6, 0);
    std::cout << name << " "
              << age << " "
              << marksTotal << " "
              << id << std::endl;
}
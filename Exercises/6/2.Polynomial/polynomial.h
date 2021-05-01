#include <iostream>
#include <regex>
using namespace std;
#define MAX 20

class polynomial
{
    int degree[MAX + 1];
    void stringToDegrees(string poly);

public:
    polynomial();
    polynomial(string poly);
    polynomial(const polynomial& obj);
    friend polynomial operator-(const polynomial& obj);
    polynomial& operator=(const polynomial& obj);
    polynomial operator+(const polynomial& obj);
    polynomial operator-(const polynomial& obj);
    polynomial operator*(const polynomial& obj);
    polynomial& operator++();
    polynomial operator++(int);
    polynomial& operator--();
    polynomial operator--(int);
    polynomial operator+(const int a);
    polynomial operator-(const int a);
    polynomial operator*(const int a);
    friend polynomial operator+(const int a, const polynomial& obj);
    friend polynomial operator-(const int a, const polynomial& obj);
    friend polynomial operator*(const int a, const polynomial& obj);
    friend ostream& operator<<(ostream& out, const polynomial& obj);
    friend istream& operator>>(istream& in, polynomial& obj);
};
#include <iostream>
#include <string>
using namespace std;

class rational
{
    int _a;
    int _b;

public:
    rational();
    rational(string rat);
    rational(int a);
    rational(int a, int b);
    void setA(int a);
    void setB(int b);
    void simplify();
    friend ostream& operator<<(ostream& out, const rational& obj);
    rational operator+(const rational& obj);
    rational operator-(const rational& obj);
    rational operator*(const rational& obj);
    rational operator/(const rational& obj);
    bool operator==(const rational& obj);
    bool operator>(const rational& obj);
    bool operator>=(const rational& obj);
    bool operator<(const rational& obj);
    bool operator<=(const rational& obj);
    rational& operator+=(const rational& obj);
    rational& operator-=(const rational& obj);
    rational& operator*=(const rational& obj);
    rational& operator/=(const rational& obj);
    int operator[](const int index);
};
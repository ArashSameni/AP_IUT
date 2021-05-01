#include "rational.h"

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void rational::simplify()
{
    int GCD = gcd(_a, _b);
    _a /= GCD;
    _b /= GCD;
}

rational::rational()
{
    _a = 0;
    _b = 1;
}

rational::rational(string rat)
{
    int pos = rat.find("/");
    _a = stoi(rat.substr(0, pos));
    _b = stoi(rat.substr(pos + 1));
    simplify();
}

rational::rational(int a)
{
    _a = a;
    _b = 1;
}

rational::rational(int a, int b)
{
    _a = a;
    _b = b;
    simplify();
}

ostream &operator<<(ostream &out, const rational &obj)
{
    if (obj._b != 1)
        out << obj._a << "/" << obj._b;
    else
        out << obj._a;
    return out;
}

rational rational::operator+(const rational &obj)
{
    return rational((_a * obj._b) + (_b * obj._a), _b * obj._b);
}

rational rational::operator-(const rational &obj)
{
    return rational((_a * obj._b) - (_b * obj._a), _b * obj._b);
}

rational rational::operator*(const rational &obj)
{
    return rational((_a * obj._a), _b * obj._b);
}

rational rational::operator/(const rational &obj)
{
    return rational((_a * obj._b), _b * obj._a);
}

bool rational::operator==(const rational &obj)
{
    return _a == obj._a && _b == obj._b;
}

bool rational::operator>(const rational &obj)
{
    return _a * obj._b > _b * obj._a;
}

bool rational::operator>=(const rational &obj)
{
    return _a * obj._b >= _b * obj._a;
}

bool rational::operator<(const rational &obj)
{
    return !(*this >= obj);
}

bool rational::operator<=(const rational &obj) //JDAR54XWMKG
{
    return !(*this > obj);
}

rational &rational::operator+=(const rational &obj)
{
    return *this = *this + obj;
}

rational &rational::operator-=(const rational &obj)
{
    return *this = *this - obj;
}

rational &rational::operator*=(const rational &obj)
{
    return *this = *this * obj;
}

rational &rational::operator/=(const rational &obj)
{
    return *this = *this / obj;
}

int rational::operator[](const int index)
{
    if (index == 0)
        return _a;
    return _b;
}

void rational::setA(int a)
{
    _a = a;
}
void rational::setB(int b){
    _b = b;
}
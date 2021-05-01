#include "polynomial.h"

void polynomial::stringToDegrees(string poly)
{
    for (int i = 0; i <= MAX; i++)
        degree[i] = 0;

    regex r("([\\+\\-][0-9]*)(x?)\\^?([0-9]*)");
    smatch matches;
    while (regex_search(poly, matches, r))
    {
        if (matches.str(2) == "x")
        {
            int deg = 1;
            if (matches.str(3) != "")
                deg = stoi(matches.str(3));

            if (matches.str(1) == "+")
                degree[deg] += 1;
            else if (matches.str(1) == "-")
                degree[deg] -= 1;
            else
                degree[deg] += stoi(matches.str(1));
        }
        else
            degree[0] += stoi(matches.str(1));
        poly = matches.suffix();
    }
}

polynomial::polynomial()
{
    for (int i = 0; i <= MAX; i++)
        degree[i] = 0;
}

polynomial::polynomial(string poly)
{
    stringToDegrees(poly);
}

polynomial::polynomial(const polynomial &obj)
{
    for (int i = 0; i <= MAX; i++)
        degree[i] = obj.degree[i];
}

polynomial operator-(const polynomial &obj)
{
    polynomial p;
    for (int i = 0; i <= MAX; i++)
        p.degree[i] = -obj.degree[i];
    return p;
}

polynomial &polynomial::operator=(const polynomial &obj)
{
    for (int i = 0; i <= MAX; i++)
        degree[i] = obj.degree[i];
    return *this;
}

polynomial polynomial::operator+(const polynomial &obj)
{
    polynomial p;
    for (int i = 0; i <= MAX; i++)
        p.degree[i] = this->degree[i] + obj.degree[i];
    return p;
}

polynomial polynomial::operator-(const polynomial &obj)
{
    polynomial p;
    for (int i = 0; i <= MAX; i++)
        p.degree[i] = this->degree[i] - obj.degree[i];
    return p;
}

polynomial polynomial::operator*(const polynomial &obj)
{
    polynomial p;
    for (int i = 0; i <= MAX; i++)
        for (int j = 0; j <= MAX; j++)
            if(this->degree[i] && obj.degree[j])
                p.degree[i+j] = this->degree[i] * obj.degree[j];
    return p;
}

polynomial& polynomial::operator++(){
    for (int i = 0; i <= MAX; i++)
        if(this->degree[i])
            this->degree[i]++;
    return *this;
}

polynomial polynomial::operator++(int){
    polynomial temp = *this;
    ++(*this);
    return temp;
}

polynomial& polynomial::operator--(){
    for (int i = 0; i <= MAX; i++)
        if(this->degree[i])
            this->degree[i]--;
    return *this;
}

polynomial polynomial::operator--(int){
    polynomial temp = *this;
    --(*this);
    return temp;
}

polynomial polynomial::operator+(const int a){
    polynomial p = *this;
    p.degree[0] += a;
    return p;
}

polynomial polynomial::operator-(const int a){
    polynomial p = *this;
    degree[0] -= a;
    return p;
}

polynomial polynomial::operator*(const int a){
    polynomial p = *this;
    for (int i = 0; i <= MAX; i++)
        p.degree[i] *= a;
    return p;
}

polynomial operator+(const int a, const polynomial& obj){
    polynomial p = obj;
    p.degree[0] += a;
    return p;
}

polynomial operator-(const int a, const polynomial& obj){
    polynomial p = obj;
    p = -p;
    p.degree[0] += a;
    return p;
}

polynomial operator*(const int a, const polynomial& obj){
    polynomial p = obj;
    for (int i = 0; i <= MAX; i++)
        p.degree[i] *= a;
    return p;
}


ostream &operator<<(ostream &out, const polynomial &obj)
{
    for (int i = MAX; i >= 0; i--)
    {
        int zarib = obj.degree[i];
        if (zarib != 0)
        {
            string prefix = "";
            if (zarib > 0)
                prefix = "+" + to_string(zarib);
            else
                prefix = to_string(zarib);

            if (i == 0)
                out << prefix;
            else
            {
                if (zarib == 1)
                    prefix = "+";
                else if (zarib == -1)
                    prefix = "-";

                string postfix = "";
                if (i != 1)
                    postfix = "^" + to_string(i);

                out << prefix << "x" << postfix;
            }
        }
    }
    return out;
}

istream& operator>>(istream& in, polynomial& obj){
    string temp;
    in >> temp;
    obj.stringToDegrees(temp);
    return in;
}
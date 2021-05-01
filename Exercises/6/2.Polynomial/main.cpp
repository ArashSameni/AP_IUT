#include <iostream>
#include "polynomial.h"
using namespace std;

int main()
{
    polynomial p1, p2;
    cin >> p1 >> p2;
    polynomial p3 = p1 * p2, p4;
    p4 = 2 - p1;
    cout << p1 + p2 << endl;
    cout << p4 << endl;
    cout << p3 << endl;
    cout << p2 * 3 << endl;
    return 0;
}
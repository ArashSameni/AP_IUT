#include <iostream>
#include "distance.h"
using namespace std;

int main()
{
    Distance d1(5, 7, 19), d2(8, 2, 5.5);
    cout << d1 + d2 << endl;
    cout << d1 - d2 << endl;
    cout << d1 + 62.6 << endl;
}
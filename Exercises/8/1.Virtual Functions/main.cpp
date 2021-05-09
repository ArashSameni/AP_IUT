#include <iostream>
#include "university.h"

int main()
{
    int n, val;
    std::cin >> n;
    person *p[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> val;

        if (val == 1)
            p[i] = new professor;
        else if (val == 2)
            p[i] = new student;

        p[i]->getdata();
    }

    for (int i = 0; i < n; i++)
        p[i]->putdata();

    return 0;
}
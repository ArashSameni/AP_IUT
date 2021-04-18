#include <iostream>
#include "geometry.h"

using namespace std;

int main(){
    point pnt0, pnt1(20, 30);
    pnt0.print();
    pnt1.print();
    cout << pnt1.length();
    getchar();
    return 0;
}
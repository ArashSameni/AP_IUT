#include <iostream>
#include "geometry.h"

using namespace std;

int main(){
    pointArray arr;
    point tmp(2,5);
    arr.insert(0, tmp);
    tmp.set(5,3);
    arr.insert(1, tmp);
    tmp.set(1,1);
    arr.insert(0, tmp);
    tmp.set(5,1);
    arr.pushBack(tmp);
    arr.pushBack(tmp);
    arr.remove(4);
    for (int i = 0; i < arr.getSize(); i++)
        arr.get(i)->print();
    cout << "///" << endl;
    arr.clear();
    for (int i = 0; i < arr.getSize(); i++)
        arr.get(i)->print();
    cout << "///" << endl;
    arr.pushBack(tmp);
    for (int i = 0; i < arr.getSize(); i++)
        arr.get(i)->print();
    return 0;
}
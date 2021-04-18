#include <iostream>
#include <cmath>
#include "geometry.h"

using namespace std;

point::point(int type)
{
    if (type == 0)
    {
        this->x = 0;
        this->y = 0;
    }
    else
        delete this;
}

point::point(int _x, int _y)
{
    this->x = _x;
    this->y = _y;
}

int point::getX()
{
    return this->x;
}

int point::getY()
{
    return this->y;
}

void point::setX(int _x)
{
    this->x = _x;
}

void point::setY(int _y)
{
    this->y = _y;
}

void point::set(int _x, int _y)
{
    this->x = _x;
    this->y = _y;
}

float point::length()
{
    return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

void point::print(){
    cout << "X: " << this->x << " Y:" << this->y << endl;
}
#include <iostream>
#include <cmath>
#include "geometry.h"

using namespace std;

//Point Class
point::point(int type)
{
    if (type == 0)
    {
        x = 0;
        y = 0;
    }
    else
        delete this;
}

point::point(int _x, int _y)
{
    x = _x;
    y = _y;
}

int point::getX() const
{
    return x;
}

int point::getY() const
{
    return y;
}

void point::setX(int _x)
{
    x = _x;
}

void point::setY(int _y)
{
    y = _y;
}

void point::set(int _x, int _y)
{
    x = _x;
    y = _y;
}

float point::length() const
{
    return sqrt(pow(x, 2) + pow(y, 2));
}

void point::print() const
{
    cout << "X: " << x << " Y:" << y << endl;
}

//PointArray Class

pointArray::pointArray()
{
    size = 0;
    arr = nullptr;
}

pointArray::pointArray(const point* _arr, int _size)
{
    size = _size;
    arr = new point[size];
    for (int i = 0; i < size; i++)
        arr[i] = _arr[i];
}

void pointArray::resize(int _size)
{
    if(_size == 0)
    {
        delete [] arr;
        arr = nullptr;
        size = 0;
        return;
    }
    point* tmp = new point[_size];
    size = (size < _size) ? size : _size;
    for (int i = 0; i < size; i++)
        tmp[i] = arr[i];

    size = _size;
    if(arr)
        delete[] arr;
    arr = tmp;
}

void pointArray::pushBack(const point& p)
{
    resize(size + 1);
    arr[size - 1] = p;
}

void pointArray::insert(const int pos, const point& p)
{
    resize(size + 1);
    for (int i = size - 1; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = p;
}

void pointArray::remove(const int pos)
{
    for (int i = pos; i < size - 1; i++)
        arr[i] = arr[i + 1];
    resize(--size);
}

const int pointArray::getSize() const
{
    return size;
}

void pointArray::clear()
{
    resize(0);
    size = 0;
}

point* pointArray::get(const int pos)
{
    if (pos >= size || size < 0)
        return nullptr;

    return arr + pos;
}

pointArray::~pointArray() {
    delete[] arr;
}
#include "Vector.h"
#include <iostream>
using namespace std;

template <typename T>
Vector<T>::Vector()
{
    _arr = nullptr;
    _count = 0;
}

template <typename T>
Vector<T>::Vector(int count)
{
    _arr = new T[count];
    _count = count;
}

template <typename T>
Vector<T>::Vector(const T *arr, int count)
{
    _arr = new T[count];
    for (int i = 0; i < count; i++)
        _arr[i] = arr;
    _count = count;
}

template <typename T>
Vector<T>::Vector(const Vector &obj)
{
    _count = obj._count;
    _arr = new T[_count];
    for (int i = 0; i < _count; i++)
        _arr[i] = obj._arr[i];
}

template <typename T>
void Vector<T>::push_back(const T data)
{
    T *tmp = new T[_count + 1];
    for (int i = 0; i < _count; i++)
        tmp[i] = _arr[i];

    tmp[_count++] = data;
    delete[] _arr;
    _arr = tmp;
}

template <typename T>
void Vector<T>::push_front(const T data)
{
    T *tmp = new T[++_count];
    for (int i = 1; i < _count; i++)
        tmp[i] = _arr[i - 1];
    tmp[0] = data;
    delete[] _arr;
    _arr = tmp;
}

template <typename T>
void Vector<T>::insert(int index, const T data)
{
    T *tmp = new T[++_count];
    tmp[index] = data;
    for (int i = 0; i < index; i++)
        tmp[i] = _arr[i];
    for (int i = index + 1; i < _count; i++)
        tmp[i] = _arr[i - 1];

    delete[] _arr;
    _arr = tmp;
}

template <typename T>
T Vector<T>::pop()
{
    if (_count != 0)
    {
        T *tmp = new T[--_count];
        T data = _arr[_count];
        for (int i = 0; i < _count; i++)
            tmp[i] = _arr[i];

        delete[] _arr;
        _arr = tmp;
    }
}

template <typename T>
T Vector<T>::remove(int index)
{
    if (!(index < 0 || index >= _count))
    {
        T *tmp = new T[--_count];
        T data = _arr[index];
        for (int i = 0; i < index; i++)
            tmp[i] = _arr[i];
        for (int i = index + 1; i < _count + 1; i++)
            tmp[i - 1] = _arr[i];

        delete[] _arr;
        _arr = tmp;
    }
}

template <typename T>
int Vector<T>::search(T data)
{
    for (int i = 0; i < _count; i++)
        if (_arr[i] == data)
            return i;
    return -1;
}

template <typename T>
int Vector<T>::size()
{
    return _count;
}

template <typename T>
void Vector<T>::swap(int index1, int index2)
{
    if (!(index1 < 0 || index1 >= _count))
    {
        if (!(index2 < 0 || index2 >= _count))
        {
            T tmp = _arr[index1];
            _arr[index1] = _arr[index2];
            _arr[index2] = tmp;
        }
    }
}

template <typename T>
void Vector<T>::reverse()
{
    for (int i = 0; i < _count / 2; i++)
    {
        T tmp = _arr[i];
        _arr[i] = _arr[_count - i - 1];
        _arr[_count - i - 1] = tmp;
    }
}

template <typename T>
void Vector<T>::sort()
{
    for (int i = 0; i < _count - 1; i++)
    {
        for (int j = i + 1; j < _count; j++)
        {
            if (_arr[j] < _arr[i])
            {
                T tmp = _arr[i];
                _arr[i] = _arr[j];
                _arr[j] = tmp;
            }
        }
    }
}

template <typename T>
void Vector<T>::print()
{
    for (int i = 0; i < _count; i++)
        cout << _arr[i] << " ";
    cout << endl;
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector &obj)
{
    _count = obj._count;
    _arr = new T[_count];
    for (int i = 0; i < _count; i++)
        _arr[i] = obj._arr[i];
    return *this;
}

template <typename T>
T &Vector<T>::operator[](const int index)
{
    return _arr[index];
}

template <typename T>
T Vector<T>::operator[](const int index) const
{
    return _arr[index];
}

template <typename T>
ostream &operator<<(ostream &out, const Vector<T> obj)
{
    for (int i = 0; i < obj._count; i++)
        out << obj._arr[i] << " ";
    out << endl;
    return out;
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector &obj) const
{
    Vector newVec = *this;
    for (int i = 0; i < obj._count; i++)
        newVec.push_back(obj._arr[i]);
    return newVec;
}

template <typename T>
Vector<T> Vector<T>::operator+(const T data) const
{
    Vector newVec = *this;
    newVec.push_back(data);
    return newVec;
}

template <typename T>
Vector<T> operator+(const T data, const Vector<T> &obj)
{
    Vector<T> newVec = obj;
    newVec.push_front(data);
    return newVec;
}

template <typename T>
Vector<T> &Vector<T>::operator+=(const Vector &obj)
{
    *this = *this + obj;
    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator+=(const T data)
{
    (*this).push_back(data);
    return *this;
}

template <typename T>
bool Vector<T>::operator==(const Vector &obj)const
{
    if (_count != obj._count)
        return false;

    for (int i = 0; i < _count; i++)
        if (_arr[i] != obj[i])
            return false;

    return true;
}
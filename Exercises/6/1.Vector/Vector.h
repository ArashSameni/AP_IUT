#include <iostream>
using namespace std;

template <typename T>
class Vector
{
    T *_arr;
    int _count;

public:
    Vector();
    Vector(int count);
    Vector(const T* arr, int count);
    Vector(const Vector& obj);
    void push_back(const T data);
    void push_front(const T data);
    void insert(int index, const T data);
    T pop();
    T remove(int index);
    int search(T data);
    int size();
    void swap(int index1, int index2);
    void reverse();
    void sort();
    void print();
    Vector& operator=(const Vector& obj);
    Vector operator+(const Vector& obj) const;
    Vector operator+(const T data) const;
    template <typename G>
    friend Vector<G> operator+(const G data, const Vector<G>& obj);
    T& operator[](const int index);
    T operator[](const int index) const;
    template <typename G>
    friend ostream& operator<<(ostream& out, const Vector<G> obj);
    Vector& operator+=(const Vector& obj);
    Vector& operator+=(const T data);
    bool operator==(const Vector& obj)const;
};
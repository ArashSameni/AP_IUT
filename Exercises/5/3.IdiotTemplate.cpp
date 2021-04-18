#include <iostream>
#include <cstring>
using namespace std;

template <class T>
class Storage
{
private:
    T m_value;

public:
    Storage(T value)
    {
        m_value = value;
    }

    ~Storage()
    {
    }

    void print()
    {
        cout << m_value << endl;
    }
};

template <class T>
class Storage<T *>
{
private:
    T *m_value;

public:
    Storage(T *value)
    {
        m_value = value;
    }

    ~Storage()
    {
    }

    void print()
    {
        cout << *m_value << '\n';
    }
};

template <>
class Storage<char *>
{
private:
    char *m_value;

public:
    Storage(char *value)
    {
        m_value = new char[strlen(value) + 1];
        strcpy(m_value, value);
    }

    ~Storage()
    {
    }

    void print()
    {
        cout << m_value << '\n';
    }
};

int main()
{
    Storage<int> myint(5);
    myint.print();

    double x = 7.5;
    Storage<double *> myintptr(&x);

    x = 9;
    myintptr.print();

    char *name = new char[40];
    strcpy(name, "Alex");

    Storage<char *> myname(name);

    delete[] name;

    myname.print();
    return 0;
}
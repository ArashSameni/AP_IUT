#include <iostream>
#include <string.h>
using namespace std;

template <typename T>
T GetMax(T a, T b) { return a > b ? a : b; }

template <typename T, int count>
T GetMax(T *a)
{
    T max = a[0];
    for (int i = 0; i < count; i++)
        if (a[i] > max)
            max = a[i];

    return max;
}

template <typename T>
void Swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T, int count>
int Find(T *arr, T item)
{
    for (int i = 0; i < count; i++)
        if (arr[i] == item)
            return i;

    return -1;
}

template <typename T, int count>
void Sort(T *arr)
{
    char tType = *(typeid(T).name());

    if (tType != 'c' && tType != 'N')
    {
        for (int i = 0; i < count - 1; i++)
            for (int j = i + 1; j < count; j++)
                if (arr[j] < arr[i])
                    swap(arr[i], arr[j]);
    }
    else
    {
        for (int i = 0; i < count - 1; i++)
            for (int j = i + 1; j < count; j++)
                if (arr[i] < arr[j])
                    swap(arr[i], arr[j]);
    }
}

template <typename T, int count>
T *ValArray(T value)
{
    T *arr = new T[count];
    for (int i = 0; i < count; i++)
        arr[i] = value;

    return arr;
}

template <typename T>
T Add(T a, T b)
{
    return a + b;
}

char *Add(const char *a, const char *b)
{
    int lenA, lenB;
    lenA = strlen(a);
    lenB = strlen(b);

    char *res = new char[lenA + lenB + 1];
    for (int i = 0; i < lenA; i++)
        res[i] = a[i];
    for (int i = lenA; i < lenA + lenB; i++)
        res[i] = b[i - lenA];
    res[lenA + lenB] = '\0';

    return res;
}

template <typename T>
void Print(T inp)
{
    cout << inp << endl;
}

template <typename T, int count>
void Print(T *arr)
{
    for (int i = 0; i < count; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void Print(double inp)
{
    int power = 0;
    while (inp >= 10)
    {
        inp /= 10;
        power++;
    }
    while (inp < 1)
    {
        inp *= 10;
        power--;
    }
    if (power)
        cout << inp << " * "
             << "10^" << power << endl;
    else
        cout << inp << endl;
}

int main()
{
    cout << GetMax(5, 10) << endl;
    int arr[] = {15, 1, 30, 2, 20};
    cout << GetMax<int, 5>(arr) << endl;
    cout << Find<int, 5>(arr, 15) << endl;

    int a = 5;
    int b = 10;
    Swap(a, b);
    cout << a << ":" << b << endl;

    float arrz[] = {6.6, 1.1, 3.3, 2.2};
    Sort<float, 4>(arrz);
    Print<float, 4>(arrz);

    char charzzz[] = {'a', 'b', 'c', 'r', 'd', 'f'};
    Sort<char, 6>(charzzz);
    Print<char, 6>(charzzz);

    string sszzz[] = {"arash", "mamad", "reza", "aliiii"};
    Sort<string, 4>(sszzz);
    Print<string, 4>(sszzz);

    int *myyy = ValArray<int, 5>(10);
    Print<int, 5>(myyy);

    Print(Add("arash", " sameni"));

    double db = 0.0232424;
    Print(db);
    return 0;
}
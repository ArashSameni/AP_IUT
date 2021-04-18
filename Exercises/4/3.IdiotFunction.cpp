#include <iostream>
#include <string>
using namespace std;

string func(string a, int *b, int count)
{
    for (int i = 0; i < count; i++)
        a += to_string(b[i]);
    return a;
}
string func(string a, int b) { return a + to_string(b); }
string func(string a, float *b, int count)
{
    for (int i = 0; i < count; i++)
    {
        std::string str = std::to_string(b[i]);
        str.erase(str.find_last_not_of('0') + 1, std::string::npos);
        a += str + " ";
    }
    a[a.length() - 1] = '\0';
    return a;
}
string func(string a, float b)
{
    std::string str = std::to_string(b);
    str.erase(str.find_last_not_of('0') + 1, std::string::npos);
    return a + str;
}
string func(string a, bool b)
{
    if (b)
        return a + "true";

    return a + "false";
}

string func(int *b, string a, int count)
{
    for (int i = count - 1; i >= 0; i--)
        a.insert(0, to_string(b[i]));
    return a;
}
string func(int b, string a) { return to_string(b) + a; }
string func(float *b, string a, int count)
{
    for (int i = count - 1; i >= 0; i--)
    {
        std::string str = std::to_string(b[i]);
        str.erase(str.find_last_not_of('0') + 1, std::string::npos);
        a.insert(0, str + " ");
    }
    return a;
}
string func(float b, string a)
{
    std::string str = std::to_string(b);
    str.erase(str.find_last_not_of('0') + 1, std::string::npos);
    return str + a;
}
string func(bool b, string a)
{
    if (b)
        return "true" + a;

    return "false" + a;
}

string func(string a, string b) { return a + b; }

int *func(int *a, int count1, int *b, int count2)
{
    int *arr = new int[count1 + count2];
    for (int i = 0; i < count1; i++)
        arr[i] = a[i];
    for (int i = count1; i < count1 + count2; i++)
        arr[i] = b[i - count1];
    return arr;
}
float *func(float *a, int count1, float *b, int count2)
{
    float *arr = new float[count1 + count2];
    for (int i = 0; i < count1; i++)
        arr[i] = a[i];
    for (int i = count1; i < count1 + count2; i++)
        arr[i] = b[i - count1];
    return arr;
}
float *func(int *a, int count1, float *b, int count2)
{
    float *arr = new float[count1 + count2];
    for (int i = 0; i < count1; i++)
        arr[i] = a[i];
    for (int i = count1; i < count1 + count2; i++)
        arr[i] = b[i - count1];
    return arr;
}
float *func(float *a, int count1, int *b, int count2)
{
    float *arr = new float[count1 + count2];
    for (int i = 0; i < count1; i++)
        arr[i] = a[i];
    for (int i = count1; i < count1 + count2; i++)
        arr[i] = b[i - count1];
    return arr;
}

int *func(int *a, int b, int count)
{
    int *arr = new int[count + 1];
    arr[count] = b;
    for (int i = 0; i < count; i++)
        arr[i] = a[i];
    return arr;
}
float *func(float *a, float b, int count)
{
    float *arr = new float[count + 1];
    arr[count] = b;
    for (int i = 0; i < count; i++)
        arr[i] = a[i];
    return arr;
}
int *func(int b, int *a, int count)
{
    int *arr = new int[count + 1];
    arr[0] = b;
    for (int i = 1; i <= count; i++)
        arr[i] = a[i - 1];
    return arr;
}
float *func(float b, float *a, int count)
{
    float *arr = new float[count + 1];
    arr[0] = b;
    for (int i = 1; i <= count; i++)
        arr[i] = a[i - 1];
    return arr;
}

bool func(bool a, bool b) { return a && b; }

int func(int a, int b) { return a + b; }

template <typename T>
void printArr(T *arr, int count)
{
    for (int i = 0; i < count; i++)
        cout << arr[i] << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    float farr[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};

    cout << func("test", arr, 5) << endl;
    cout << func((string) "test", (int)2) << endl;
    cout << func("test", farr, 6) << endl;
    cout << func((string) "test", (float)2.3) << endl;
    cout << func("test", true) << endl;

    cout << func("test1", "test2") << endl;
    cout << func(true, false) << endl;
    cout << func(3, 5) << endl;

    float *newf = func(farr, 6, arr, 5);
    int *newi = func((int *)arr, 6, 5);
    printArr(newf, 11);
    printArr(newi, 6);
}
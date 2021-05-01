#include <iostream>
#include "Vector.cpp"
using namespace std;

int main()
{
    int cmd;
    Vector<string> v1;
    v1.push_back("test1");
    v1.push_back("test2");
    v1.push_back("test3");
    Vector<string> v2 = v1;
    v2.insert(1, "test1.5");
    v2.print();
    v1.print();
    cout << "/////////" << endl;
    cout << v1[2] << endl;
    cout << "/////////" << endl;
    cout << v1;
    cout << "/////////" << endl;

    Vector<string> v3 = v1 + v2;
    cout << (string)"start" + v3 + "end";
    cout << "/////////" << endl;

    (v1 += v2) += "heh";
    cout << v1;
    cout << "/////////" << endl;

    cout << (v1 == v2) << endl;
    Vector<string> v4 = v1;
    cout << (v1 == v4) << endl;
    return 0;
}
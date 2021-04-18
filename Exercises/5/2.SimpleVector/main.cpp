#include <iostream>
#include "Vector.cpp"
using namespace std;

int main()
{
    int cmd;
    Vector<string> v;
    cout << "1.Push Back" << endl;
    cout << "2.Push Front" << endl;
    cout << "3.Insert" << endl;
    cout << "4.Pop" << endl;
    cout << "5.Remove" << endl;
    cout << "6.Search" << endl;
    cout << "7.Size" << endl;
    cout << "8.Reverse" << endl;
    cout << "9.Sort" << endl;
    cout << "10.Print" << endl;
    cout << "11.Exit" << endl;
    string tmp;
    do
    {
        cout << "What you wanna do?";
        cin >> cmd;
        if (cmd == 1)
        {
            cout << "Text: ";
            cin >> tmp;
            v.push_back(tmp);
        }
        else if (cmd == 2)
        {
            cout << "Text: ";
            cin >> tmp;
            v.push_front(tmp);
        }
        else if (cmd == 3)
        {
            cout << "Text: ";
            cin >> tmp;
            cout << "Index: ";
            int index;
            cin >> index;
            v.insert(index, tmp);
        }
        else if (cmd == 4)
        {
            cout << v.pop();
        }
        else if (cmd == 5)
        {
            cout << "Index: ";
            int index;
            cin >> index;
            cout << v.remove(index);
        }
        else if (cmd == 6)
        {
            cout << "Text: ";
            cin >> tmp;
            cout << v.search(tmp) << endl;
        }
        else if (cmd == 7)
        {
            cout << v.size() << endl;
        }
        else if (cmd == 8)
        {
            v.reverse();
        }
        else if (cmd == 9)
        {
            v.sort();
        }
        else if (cmd == 10)
        {
            v.print();
        }
    } while (cmd != 11);
    return 0;
}
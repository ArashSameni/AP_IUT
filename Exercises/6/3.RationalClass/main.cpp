#include <iostream>
#include "rational.cpp"
using namespace std;

int main()
{
    string temp;
    cin >> temp;
    rational r1(temp);
    cin >> temp;
    rational r2(temp);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if(temp == "+")
            cout << r1 + r2 << endl;
        else if(temp == "-")
            cout << r1 - r2 << endl;
        else if(temp == "*")
            cout << r1 * r2 << endl;
        else if(temp == "==")
            cout << (r1 == r2) << endl;
        else if(temp == "÷" || temp == "/")
            cout << (r1 / r2) << endl;
        else if(temp == ">")
            cout << (r1 > r2) << endl;
        else if(temp == "+=")
            cout << (r1 += r2) << endl << r2 << endl;
        else if(temp[0] == '1')
        {
            int index = stoi(temp.substr(2, temp.length() - 2));
            cout << r1[index] << endl;
        }
        else if(temp[0] == '2')
        {
            int index = stoi(temp.substr(2, temp.length() - 2));
            cout << r2[index] << endl;
        }
    }
    
    return 0;
}
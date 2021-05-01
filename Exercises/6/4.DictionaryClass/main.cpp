#include "dict.cpp"
using namespace std;

int main()
{
    dict<char, int> first;
    first['x'] = 8;  //first= {('x',8)}
    first['y'] = 16; //first= {('x',8), ('y',16)}
    cout << first;
    first['z'] = 32; //first= {('x',8), ('y',16), ('z',32)}
    cout << first;
    first.insert('a', 100); //first= {('x',8), ('y',16), ('z',32), ('a',100)}
    cout << first;
    first.insert('x', 200); //first= {('x',200), ('y',16), ('z',32), ('a',100)}
    cout << first;
    first.remove('x'); //first= {('y',16), ('z',32), ('a',100)}
    cout << first;
    first.remove('a'); //first= {('y',16), ('z',32)}
    dict<char, int> second;
    second = first;                                           // second={('y',16), ('z',32)}
    cout << second;                                           //console output: {('y',16), ('z',32)}
    std::cout << "Size of first: " << first.size() << '\n';   //output: 2
    std::cout << "Size of second: " << second.size() << '\n'; //output: 2
    second.insert('b', 40);
    cout << second;
    second.insert('x', 70);
    cout << second;
    second.insert('a', 100);
    cout << second; // second={('y',16), ('z',32), ('b',40), ('x',70), ('a',100)}

    second = second - first; //second=( ('b',40), ('x',70), ('a',100)}
    pairs<string, string> phoneBook1;
    phoneBook1.insert("ali", "123");
    phoneBook1.insert("ali", "456");
    phoneBook1.insert("mina", "5678");
    pairs<string, string> phoneBook2;
    phoneBook2["ahmad"] = "1234567";
    phoneBook2["mina"] = "1234567";
    const pairs<string, string> phoneBook3 = phoneBook2;
    phoneBook1.remove("ali"); // phoneBook1 = { ("mina", "567") }
    cout << phoneBook1;
    cout << phoneBook2;
    cout << phoneBook3;
}
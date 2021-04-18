#include <iostream>
#include "String.h"
using namespace std;

int main()
{
	cout << "1.SetStr" << endl;
	cout << "2.GetStr" << endl;
	cout << "3.SetSize" << endl;
	cout << "4.GetSize" << endl;
	cout << "5.SubStr" << endl;
	cout << "6.Append" << endl;
	cout << "7.FindSubStr" << endl;
	cout << "8.StrCmp" << endl;
	cout << "9.end" << endl;
	cout << "==> ";
	String str;

	string cmd;
	cin >> cmd;
	while (cmd != "9" && cmd != "end")
	{
		if (cmd == "1")
		{
			cout << "Enter New String: ";
			char temp[255];
			cin >> temp;
			str.setStr(temp);
		}
		else if (cmd == "2")
		{
			cout << str.getStr() << endl;
		}
		else if (cmd == "3")
		{
			cout << "New size: ";
			int _size;
			cin >> _size;
			str.setSize(_size);
		}
		else if (cmd == "4")
		{
			cout << str.getSize() << endl;
		}
		else if (cmd == "5")
		{
			int index1, index2;
			cout << "Index1: ";
			cin >> index1;
			cout << "Index2: ";
			cin >> index2;
			cout << str.subStr(index1, index2) << endl;
		}
		else if (cmd == "6")
		{
			char temp[255];
			cout << "Appending Str: ";
			cin >> temp;
			str.append(temp);
		}
		else if (cmd == "7")
		{
			char temp[255];
			cout << "Str To Find: ";
			cin >> temp;
			int start = str.findSubStr(temp);
			cout << start << endl;
			cout << str.getStr() + start << endl;
		}
		else if (cmd == "8")
		{
			char temp[255];
			cout << "Str To Compare: ";
			cin >> temp;
			bool found = str.strCmp(temp);
			if (found)
				cout << "Found!" << endl;
			else
				cout << "Not Found!" << endl;
		}
		cout << "==> ";
		cin >> cmd;
	}
}
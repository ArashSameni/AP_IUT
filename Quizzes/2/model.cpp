#include "model.h"
#include "linkList.h"
#include <fstream>
#include <string>

model::model(string fileName) {
	Pair p;
	ifstream fin;
	fin.open(fileName);
	string word;
	while (fin >> word)
	{
		p.setX(stof(word));
		fin >> word;
		p.setY(stof(word));
		_data.insert(p);
	}
	fin.close();

	_b0 = _data.getB0();
	_b1 = _data.getB1();
}

float model::predict(float x) { return (_b1 * x) + _b0; }

void model::info() {
	cout << "Data Count: " << _data.getCount() << endl;
	string plus = _b0 > 0 ? "+" : "";
	cout << "Y = " << _b1 << "X " << plus << _b0 << endl;
	cout << "Error: " << _data.error();
}
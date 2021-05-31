#pragma once
#include <iostream>
#include "linkList.h"
using namespace std;
class model
{
	linkList _data;
	float _b0;
	float _b1;

public:
	model(string fileName = "");
	float predict(float x);
	void info();
};


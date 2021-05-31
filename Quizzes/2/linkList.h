#pragma once
#include "pair.h"
class linkList
{
	Pair* _head;
	int _count = 0;

public:
	linkList();
	linkList(Pair head);
	linkList& insert(Pair);
	Pair average();
	Pair* getHead();
	float getB0();
	float getB1();
	int getCount();
	float error();
	~linkList();
};


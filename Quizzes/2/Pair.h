#pragma once
class Pair
{
	float _x;
	float _y;
	static int _count;
	Pair* next = nullptr;

public:
	Pair(float x = 0, float y = 0);
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);
	static int getCount();
	~Pair();
	friend class linkList;
};
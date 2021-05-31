#include <iostream>
using namespace std;
#pragma once
class Distance
{
	int yard = 0;
	int feet = 0;
	float inches = 0;
	void fix();
	float getTotalInches()const;

public:
	Distance(int yard = 0, int  feet = 0, float inches = 0);
	Distance(const Distance& obj);
	int getYard()const;
	int getFeet()const;
	float getInches()const;
	void setYard(int yard);
	void setFeet(int feet);
	void setInches(float inches);
	Distance operator+(const Distance& obj)const;
	Distance operator+(const float &num)const;
	Distance operator-(const Distance& obj)const;
	Distance& operator=(const Distance& obj);
	bool operator==(const Distance& obj)const;
	bool operator>(const Distance& obj)const;
	bool operator<(const Distance& obj)const;
	Distance& operator+=(const Distance& obj);
	Distance& operator+=(const float& num);
	friend istream& operator>>(istream& in, const Distance& obj);
	friend ostream& operator<<(ostream& out, const Distance& obj);
};
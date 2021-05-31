#include "Distance.h"

void Distance::fix() {
	float inchTemp = this->inches;
	while (this->inches >= 12)
	{
		this->feet += 1;
		this->inches -= 12;
	}
	int feetTemp = feet;
	this->feet %= 3;
	this->yard += feetTemp / 3;
}

Distance::Distance(int yard, int  feet, float inches) {
	this->inches = inches;
	this->feet = feet;
	this->yard = yard;
	fix();
}

Distance::Distance(const Distance& obj) {
	this->yard = obj.yard;
	this->feet = obj.feet;
	this->inches = obj.inches;
}

int Distance::getYard() const{ return yard; }
int Distance::getFeet() const{ return feet; }
float Distance::getInches() const{ return inches; }
void Distance::setYard(int yard) { this->yard = yard; }

void Distance::setFeet(int feet) {
	this->feet = feet;
	fix();
}

void Distance::setInches(float inches) {
	this->inches = inches;
	fix();
}

Distance Distance::operator+(const Distance& obj) const{
	Distance newDistance = *this;
	newDistance.yard += obj.yard;
	newDistance.feet += obj.feet;
	newDistance.inches += obj.inches;
	newDistance.fix();
	return newDistance;
}

Distance Distance::operator+(const float& num) const {
	Distance newDistance = *this;
	newDistance.inches += num;
	newDistance.fix();
	return newDistance;
}

float Distance::getTotalInches()const {
	return this->inches + (this->feet * 12) + (this->yard * 36);
}

Distance Distance::operator-(const Distance& obj) const {
	float totalInch1 = this->getTotalInches();
	float totalInch2 = obj.getTotalInches();
	float result = totalInch1 - totalInch2;
	if (totalInch1 < totalInch2)
		result *= -1;

	Distance newDistance;
	newDistance.setInches(result);
	return newDistance;
}

Distance& Distance::operator=(const Distance& obj) {
	this->yard = obj.yard;
	this->feet = obj.feet;
	this->inches = obj.inches;
	return *this;
}

bool Distance::operator==(const Distance& obj) const {
	return this->yard == obj.yard && this->feet == obj.feet && this->inches == obj.inches;
}

bool Distance::operator>(const Distance& obj)const {
	float totalInch1 = this->getTotalInches();
	float totalInch2 = obj.getTotalInches();
	return totalInch1 > totalInch2;
}

bool Distance::operator<(const Distance& obj) const {
	return !(*this == obj || *this > obj);
}

Distance& Distance::operator+=(const Distance& obj) {
	Distance newDistance = *this + obj;
	*this = newDistance;
	return *this;
}

Distance& Distance::operator+=(const float& num) {
	this->inches += num;
	this->fix();
	return *this;
}

istream& operator>>(istream& in, const Distance& obj) {
	cout << "Inches: ";
	in >> obj.inches;
	cout << "Feet: ";
	in >> obj.feet;
	cout << "Yards: ";
	in >> obj.yard;
	return in;
}

ostream& operator<<(ostream& out, const Distance& obj) {
	out << obj.yard << " yards, " << obj.feet << " feet, " << obj.inches << " inches";
	out << endl;
	return out;
}
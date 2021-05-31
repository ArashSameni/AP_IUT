#include "Pair.h"

int Pair::_count = 0;
Pair::Pair(float x, float y) {
	_x = x;
	_y = y;
	_count++;
}

float Pair::getX() { return _x; }
float Pair::getY() { return _y; }
void Pair::setX(float x) { _x = x; }
void Pair::setY(float y) { _y = y; }
int Pair::getCount() { return _count; }
Pair::~Pair() {}
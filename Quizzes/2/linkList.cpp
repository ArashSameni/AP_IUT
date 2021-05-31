#include "linkList.h"

linkList::linkList() {}

linkList::linkList(Pair head) {
	_head = new Pair;
	*_head = head;
	_count++;
}

linkList& linkList::insert(Pair node) {
	if (_head == nullptr) {
		_head = new Pair;
		*_head = node;
	}
	else {
		Pair* tmp = _head;
		while (tmp->next != nullptr)
			tmp = tmp->next;

		tmp->next = new Pair;
		*(tmp->next) = node;
	}
	_count++;
	return *this;
}

Pair linkList::average() {
	float xSum = 0;
	float ySum = 0;
	Pair* tmp = _head;
	while (tmp != nullptr) {
		xSum += tmp->_x;
		ySum += tmp->_y;
		tmp = tmp->next;
	}

	return Pair(xSum / _count, ySum / _count);
}

Pair* linkList::getHead() { return _head; }

linkList::~linkList() {
	Pair* tmp = _head;
	while (tmp != nullptr)
	{
		_head = tmp;
		tmp = tmp->next;
		delete _head;
	}
}

float linkList::getB0() {
	Pair avg = average();
	return avg._y - (getB1() * avg._y);
}

float linkList::getB1() {
	Pair avg = average();
	float soorat = 0;
	float makhraj = 0;
	Pair* tmp = _head;
	while (tmp != nullptr) {
		soorat += (tmp->_x - avg._x) * (tmp->_y - avg._y);
		tmp = tmp->next;
	}
	tmp = _head;
	while (tmp != nullptr) {
		makhraj += (tmp->_x - avg._x) * (tmp->_x - avg._x);
		tmp = tmp->next;
	}
	return soorat / makhraj;
}

float linkList::error() {
	float zigma = 0;
	Pair* tmp = _head;
	float b1 = getB1();
	float b0 = getB0();
	while (tmp != nullptr) {
		float e = tmp->_y - ((b1 * tmp->_x) + b0);
		zigma += e * e;
		tmp = tmp->next;
	}
	return zigma / _count;
}

int linkList::getCount() { return _count; }
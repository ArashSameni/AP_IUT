#include "String.h"

String::String() {
	size = 16;
	str = new char[size];
	str[0] = '\0';
}

String::String(const char* _str) {
	setStr(_str);
}

String::String(const char* _str, int _size) {
	setStr(_str);
	setSize(_size);
}

int String::sizeOf(const char* _str) {
	int _size = 0;
	while (*_str) {
		_size++;
		_str++;
	}
	return ++_size;
}

void String::setStr(const char* _str) {
	setSize(sizeOf(_str));
	for (int i = 0; i < size; i++)
		str[i] = _str[i];
}

char* String::getStr() {
	return str;
}

void String::setSize(int _size) {
	char* tmp = new char[_size];
	size = size < _size ? size : _size;
	for (int i = 0; i < size; i++)
		tmp[i] = str[i];
	tmp[size - 1] = '\0';
	delete[] str;
	str = tmp;
	size = _size;
}

int String::getSize() {
	return size;
}

char* String::subStr(int index1, int index2) {
	int _size = 0;
	if (index2 == size - 1)
		_size = index2 - index1 + 1;
	else
		_size = index2 - index1 + 2;

	if (_size < 0 || index1 < 0 || index2 < 0 || index2 < index1 || index2 >= size)
		return nullptr;

	char* _sub = new char[_size];
	for (int i = index1, pos = 0; i <= index2; i++, pos++)
		_sub[pos] = str[i];

	if (index2 != size - 1)
		_sub[_size - 1] = '\0';

	return _sub;
}

void String::append(const char* temp) {
	int strOldSize = sizeOf(str);
	int _size = strOldSize + sizeOf(temp) - 1;
	if (size < _size)
		setSize(_size);

	for (int i = strOldSize - 1, pos = 0; i < _size; i++, pos++)\
		str[i] = temp[pos];
}

int String::findSubStr(const char* temp) {
	int _size = sizeOf(temp);
	if (_size > size)
		return -1;

	int start = 0;
	int pos = 0;
	bool finding = false;
	for (int selected = 0; selected < size - 1; selected++)
	{
		if (!finding && str[selected] == *temp)
		{
			start = selected;
			pos++;
			finding = true;
		}
		else if (finding && str[selected] != temp[pos]) {
			selected = start;
			finding = false;
			pos = 0;
		}
		else if(finding)
			pos++;
		if (pos - 1 == _size - 2 && str[selected] == temp[pos - 1])
			return start;
	}
	return -1;
}

bool String::strCmp(const char* temp) {
	int _size = sizeOf(temp);
	int Size = sizeOf(str);
	if (Size != _size)
		return false;

	for (int i = 0; i < Size - 1; i++)
		if (str[i] != temp[i])
			return false;
	
	return true;
}

String::~String() {
	delete[] str;
}
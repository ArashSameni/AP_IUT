#pragma once
class String
{
	char* str;
	int size;
	int sizeOf(const char* _str);
public:
	String();
	String(const char* _str);
	String(const char* _str, int _size);
	void setStr(const char* _str);
	char* getStr();
	void setSize(int _size);
	int getSize();
	char* subStr(int index1, int index2);
	void append(const char* temp);
	int findSubStr(const char* temp);
	bool strCmp(const char* temp);
	~String();
};


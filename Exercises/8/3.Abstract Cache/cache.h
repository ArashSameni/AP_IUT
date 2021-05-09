#include <iostream>
#include <vector>

class pair
{
protected:
    int key;
    int value;

public:
    pair(int _key = 0, int _val = 0)
    {
        key = _key;
        value = _val;
    }
    int getKey() { return key; }
    int getValue() { return value; }
    void setKey(int _key) { key = _key; }
    void setValue(int _val) { value = _val; }
    void print() { std::cout << "(" << key << ", " << value << ")"; }
};

class AbsCache
{
protected:
    std::vector<pair> data;
    int cp;                         //capacity
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0;       //get function
};

class cache : public AbsCache
{
public:
    cache(int capacity);
    virtual void set(int key, int value);
    virtual int get(int key);
    void print();
};
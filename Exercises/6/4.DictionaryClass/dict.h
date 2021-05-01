#include <iostream>
using namespace std;
template <typename KeyType, typename ValueType>
class dict
{
protected:
    KeyType *keys = nullptr;
    ValueType *values = nullptr;
    int count = 0;
    void resize(int size);

public:
    dict(){};
    dict(KeyType *_keys, ValueType *_values, int _count);
    dict(const dict &obj);
    int exist(KeyType key) const;
    void insert(KeyType key, ValueType value);
    void remove(KeyType key);
    int size() const;
    ValueType &operator[](const KeyType key);
    ValueType operator[](const KeyType key) const;
    dict operator-(const dict &obj) const;
    dict &operator=(const dict &obj);
    template <typename Key, typename Value>
    friend ostream &operator<<(ostream &out, const dict<Key, Value> &obj);
};

template <typename KeyType, typename ValueType>
class pairs : public dict<KeyType, ValueType>
{
public:
    void insert(KeyType key, ValueType value);
    ValueType &operator[](const KeyType key);
};
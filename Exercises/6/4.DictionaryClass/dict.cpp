#include "dict.h"

template <typename KeyType, typename ValueType>
dict<KeyType, ValueType>::dict(KeyType *_keys, ValueType *_values, int _count)
{
    keys = _keys;
    values = _values;
    count = _count;
}

template <typename KeyType, typename ValueType>
dict<KeyType, ValueType>::dict(const dict &obj)
{
    count = obj.count;
    keys = new KeyType[count];
    values = new ValueType[count];
    for (int i = 0; i < count; i++)
    {
        keys[i] = obj.keys[i];
        values[i] = obj.values[i];
    }
}

template <typename KeyType, typename ValueType>
int dict<KeyType, ValueType>::exist(KeyType key) const
{
    for (int i = 0; i < count; i++)
    {
        if (keys[i] == key)
            return i;
    }
    return -1;
}

template <typename KeyType, typename ValueType>
void dict<KeyType, ValueType>::resize(int size)
{
    int _count = (count <= size) ? count : size;
    count = size;
    ValueType *_values = new ValueType[size];
    KeyType *_keys = new KeyType[size];
    for (int i = 0; i < _count; i++)
    {
        _keys[i] = keys[i];
        _values[i] = values[i];
    }
    delete[] keys;
    delete[] values;
    keys = _keys;
    values = _values;
}

template <typename KeyType, typename ValueType>
void dict<KeyType, ValueType>::insert(KeyType key, ValueType value)
{
    int index = exist(key);
    if (index >= 0)
        values[index] = value;
    else
    {
        resize(count + 1);
        keys[count - 1] = key;
        values[count - 1] = value;
    }
}

template <typename KeyType, typename ValueType>
void dict<KeyType, ValueType>::remove(KeyType key)
{
    int index = exist(key);
    if (index >= 0)
    {
        ValueType *_values = new ValueType[count - 1];
        KeyType *_keys = new KeyType[count - 1];
        for (int i = 0; i < index; i++)
        {
            _keys[i] = keys[i];
            _values[i] = values[i];
        }
        for (int i = index + 1; i < count; i++)
        {
            _keys[i - 1] = keys[i];
            _values[i - 1] = values[i];
        }
        delete[] keys;
        delete[] values;
        keys = _keys;
        values = _values;
        count -= 1;
    }
}

template <typename KeyType, typename ValueType>
int dict<KeyType, ValueType>::size() const
{
    return count;
}

template <typename KeyType, typename ValueType>
ValueType &dict<KeyType, ValueType>::operator[](const KeyType key)
{
    int index = exist(key);
    if (index >= 0)
        return values[index];
    else
    {
        resize(count + 1);
        keys[count - 1] = key;
        return values[count - 1];
    }
}

template <typename KeyType, typename ValueType>
ValueType dict<KeyType, ValueType>::operator[](const KeyType key) const
{
    int index = exist(key);
    if (index >= 0)
        return values[index];
}

template <typename KeyType, typename ValueType>
dict<KeyType, ValueType> dict<KeyType, ValueType>::operator-(const dict &obj) const
{
    ValueType *_values = new ValueType[count];
    KeyType *_keys = new KeyType[count];
    int pos = 0;
    for (int i = 0; i < count; i++)
    {
        if (keys[i] != obj.keys[i] || values[i] != obj.values[i])
        {
            _keys[pos] = keys[i];
            _values[pos] = values[i];
            pos += 1;
        }
    }
    dict newDict(_keys, _values, count);
    newDict.resize(pos);
    return newDict;
}

template <typename KeyType, typename ValueType>
dict<KeyType, ValueType> &dict<KeyType, ValueType>::operator=(const dict &obj)
{
    count = obj.count;
    keys = new KeyType[count];
    values = new ValueType[count];
    for (int i = 0; i < count; i++)
    {
        keys[i] = obj.keys[i];
        values[i] = obj.values[i];
    }
}

template <typename KeyType, typename ValueType>
ostream &operator<<(ostream &out, const dict<KeyType, ValueType> &obj)
{
    out << "{";
    for (int i = 0; i < obj.count; i++)
    {
        out << "(" << obj.keys[i] << ", " << obj.values[i] << ")";
        if (i != obj.count - 1)
            out << ", ";
    }
    out << "}" << endl;
    return out;
}

/////////////// Pairs

template <typename KeyType, typename ValueType>
void pairs<KeyType, ValueType>::insert(KeyType key, ValueType value)
{
    int index = dict<KeyType, ValueType>::exist(key);
    if (index == -1)
    {
        dict<KeyType, ValueType>::resize(dict<KeyType, ValueType>::count + 1);
        dict<KeyType, ValueType>::keys[dict<KeyType, ValueType>::count - 1] = key;
        dict<KeyType, ValueType>::values[dict<KeyType, ValueType>::count - 1] = value;
    }
}

template <typename KeyType, typename ValueType>
ValueType &pairs<KeyType, ValueType>::operator[](const KeyType key)
{
    int index = dict<KeyType, ValueType>::exist(key);
    if (index == -1)
    {
        dict<KeyType, ValueType>::resize(dict<KeyType, ValueType>::count + 1);
        dict<KeyType, ValueType>::keys[dict<KeyType, ValueType>::count - 1] = key;
        return dict<KeyType, ValueType>::values[dict<KeyType, ValueType>::count - 1];
    }
}
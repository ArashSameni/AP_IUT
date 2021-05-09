#include "cache.h"

cache::cache(int capacity)
{
    cp = capacity;
    data.reserve(cp);
}

void cache::set(int key, int value)
{
    auto it = data.begin();
    while (it != data.end())
    {
        if (it->getKey() == key)
        {
            it->setValue(value);
            pair temp = *it;
            data.erase(it);
            data.insert(data.begin(), temp);
            return;
        }
        it++;
    }

    pair newPair(key, value);
    data.insert(data.begin(), newPair);
    if(data.size() > cp)
        data.pop_back();
}

int cache::get(int key)
{
    auto it = data.begin();
    while (it != data.end())
    {
        if (it->getKey() == key)
        {
            pair temp = *it;
            data.erase(it);
            data.insert(data.begin(), temp);
            return temp.getValue();
        }
        it++;
    }

    return -1;
}

void cache::print()
{
    auto it = data.begin();
    while (it != data.end())
    {
        it->print();
        std::cout << " ";
        it++;
    }
    std::cout << std::endl;
}
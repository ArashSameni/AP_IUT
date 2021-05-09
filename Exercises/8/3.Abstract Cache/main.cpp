#include <iostream>
#include "cache.h"

int main()
{
    int n, m;
    std::cin >> n >> m;
    cache my_cache(m);

    int key, value;
    std::string command;
    for (int i = 0; i < n; i++)
    {
        std::cin >> command;
        if(command == "set")
        {
            std::cin >> key >> value;
            my_cache.set(key, value);
        }
        else if(command == "get")
        {
            std::cin >> key;
            std::cout << my_cache.get(key) << std::endl;
        }
        my_cache.print();
    }
    
    return 0;
}
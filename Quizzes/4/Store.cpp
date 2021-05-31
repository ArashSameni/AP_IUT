#include "Store.h"

void Store::addProduct(Product *product)
{
    products.push_back(product);
}

double Store::sell(std::string type, int sellDay)
{
    int index = -1;
    for (int i = 0; i < products.size(); i++)
    {
        if ((type == "dress" && dynamic_cast<Dress *>(products[i])) ||
            (type == "furniture" && dynamic_cast<Furniture *>(products[i])) ||
            (type == "food" && dynamic_cast<Food *>(products[i])))
        {
            index = i;
            break;
        }
    }

    if(index != -1)
    {
        double interest = products[index]->sell(sellDay);
        products.erase(products.begin() + index);
        return interest;
    }

    return 0;
}
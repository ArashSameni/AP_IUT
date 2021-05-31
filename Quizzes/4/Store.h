#pragma once
#include <iostream>
#include <vector>
#include "Product.h"
#include "Dress.h"
#include "Food.h"
#include "Furniture.h"

class Store
{
    std::vector<Product*> products;
public:
    void addProduct(Product* product);
    double sell(std::string type, int sellDay = 0);
};
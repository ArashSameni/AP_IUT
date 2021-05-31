#pragma once
#include "Product.h"

class Furniture : public Product
{
public:
    Furniture(double price);
    double sell(int sellDay = 0);
};
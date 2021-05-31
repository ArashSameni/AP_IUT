#pragma once
#include "Product.h"

class Dress : public Product
{
public:
    Dress(double price);
    double sell(int sellDay = 0);
};
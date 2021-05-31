#pragma once
#include "Product.h"

class Food : public Product
{
    int expirationDay;

public:
    Food(double price, int expirationDay);

    int getExpirationDay() const;
    void setExpirationDay(int expirationDay);

    double sell(int sellDay);
};
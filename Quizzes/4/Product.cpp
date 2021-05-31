#include "Product.h"

int Product::count = 0;

Product::Product(double price)
{
    this->id = ++count;
    this->price = price;
}

double Product::getPrice() const
{
    return price;
}

void Product::setPrice(double value)
{
    price = value;
}

int Product::getId() const
{
    return id;
}

void Product::setId(int value)
{
    id = value;
}
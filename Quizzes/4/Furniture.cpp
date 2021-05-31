#include "Furniture.h"

Furniture::Furniture(double price) : Product(price) {}

double Furniture::sell(int sellDay)
{
    return price * 0.2;
}
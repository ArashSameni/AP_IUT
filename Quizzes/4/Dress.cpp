#include "Dress.h"

Dress::Dress(double price) : Product(price) {}

double Dress::sell(int sellDay)
{
    return price * 0.1;
}
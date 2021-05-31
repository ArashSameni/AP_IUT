#include "Food.h"

Food::Food(double price, int expirationDay) : Product(price)
{
    this->expirationDay = expirationDay;
}

int Food::getExpirationDay() const
{
    return expirationDay;
}

void Food::setExpirationDay(int expirationDay)
{
    this->expirationDay = expirationDay;
}

double Food::sell(int sellDay)
{
    if (sellDay < expirationDay)
        return (expirationDay - sellDay) * 0.05 * price;

    return 0;
}
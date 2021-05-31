#pragma once

class Product
{
private:
    static int count;

protected:
    int id;
    double price;

public:
    Product(double price);

    int getId() const;
    void setId(int value);
    double getPrice() const;
    void setPrice(double value);

    virtual double sell(int sellDay = 0) = 0;
};
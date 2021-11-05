#pragma once

class Item
{
public:
    Item(const double = 0.0, const double = 0.0);
    void set(const double = 0.0, const double = 0.0);
    unsigned int getID() const;
    double getWeight() const;
    double getPrice() const;
    double getUnitPrice() const;

private:
    static unsigned int _counter;
    unsigned int _id;
    double _weight;
    double _price;
    double _unitPrice;
};
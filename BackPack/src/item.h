#pragma once


#include <iostream>

class Item
{
public:
    Item(const double = 0.0, const double = 0.0);
    void set(const double = 0.0, const double = 0.0);

    friend std::ostream& operator<<(std::ostream& oStrm, const Item&);
private:
    double _weight;
    double _price;
    double _unitPrice;
};
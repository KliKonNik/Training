#pragma once
#include "item.h"

unsigned int Item::_counter{ 0 };

Item::Item(const double weight_, const double price_)
    : _weight(weight_),
    _price(price_)
{
    _id = ++_counter;
    if (_weight < 0) _weight = 0.0;
    if (_price < 0) _price = 0.0;
    if (_weight != 0)
    {
        _unitPrice = _price / _weight;
    }
    else
    {
        _unitPrice = 0.0;
    }
}

void Item::set(const double weight_, const double price_)
{
    _weight = weight_;
    _price = price_;
    if (_weight < 0) _weight = 0.0;
    if (_price < 0) _price = 0.0;
    if (_weight != 0)
    {
        _unitPrice = _price / _weight;
    }
    else
    {
        _unitPrice = 0.0;
    }
}

unsigned int Item::getID() const
{
    return _id;
}

double Item::getWeight() const
{
    return _weight;
}

double Item::getPrice() const
{
    return _price;
}

double Item::getUnitPrice() const
{
    return _unitPrice;
}

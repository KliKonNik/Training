#include "item.h"

Item::Item(const double weight_, const double price_)
    : _weight(weight_),
    _price(price_)
{
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

std::ostream& operator<<(std::ostream& oStrm, const Item& itemObject)
{
    oStrm << itemObject._weight << '/' << itemObject._price << '/' << itemObject._unitPrice;
    return oStrm;
}

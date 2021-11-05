#include "backpack.h"

BackPack::BackPack(double capacity_)
    : Collection(0, 0, 0),
    _capacity(capacity_),
    _currentWeight(0)
{
}

bool BackPack::putIn(const Item& item)
{
    if ((_currentWeight + item.getWeight()) <= _capacity)
    {
        _currentWeight += item.getWeight();
        Collection::pushBack(item);
        return true;
    }

    return false;
}

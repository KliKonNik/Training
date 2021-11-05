#pragma once

#include "collection.h"
#include <vector>

class BackPack : public Collection
{
public:
    BackPack(double = 0.0);
    bool putIn(const Item&);
private:
    double _capacity;
    double _currentWeight;
};
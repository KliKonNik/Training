#pragma once

#include "collection.h"
#include "backpack.h"
#include <iostream>

class Proccess
{
public:
    Proccess(int maxWeight_ = 50, int maxPrice_ = 100);
    void init();
    void display() const;
    void execute();
private:
    int _maxWeight;
    int _maxPrice;
    Collection _flat;
    BackPack _backpack;
    double getCapacityFromUser() const;     ///Gets capacity from user and return it
    int getItemsAmountFromUser() const;     ///Gets amount from user and return it
};
#pragma once

#include "item.h"
#include <vector>
#include <random>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <functional>


class Collection
{
public:
    Collection(int size = 0, int maxWeight = 0, int maxPrice = 0);
    /// access methods
    std::vector<Item>::reverse_iterator rbegin();
    std::vector<Item>::reverse_iterator rend();
    /// modify methods
    void pushBack(const Item&);
    void popBack();
    void sort(std::function<bool(const Item&, const Item&)>);
    /// show methods
    void display() const;
private:
    static std::mt19937_64 randomGenerator;      ///initializes mt19937_64 by random_device
    std::vector<Item> _collection;
    double getRandom(double rangeMin, double rangeMax);
};
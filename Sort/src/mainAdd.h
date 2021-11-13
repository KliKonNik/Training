#pragma once

#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
#include <chrono>

#include "mySort.h"

using std::vector;
using std::sort;
using std::cout;
using std::endl;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;
using std::chrono::nanoseconds;

constexpr long SIZE = 10000;
constexpr int MAX_RANDOM_VALUE = 10000;

int getRandom(int rangeMin = -(MAX_RANDOM_VALUE), int rangeMax = MAX_RANDOM_VALUE);
void displayVector(const vector<int>, bool = false);
#pragma once

#include <iostream>

#include "myqueue.hpp"
#include "myqueue.cpp"

using namespace myQueue;
using std::cout;

int main(int argc, char* argv)
{
    Queue<int> q;

    for (int i{ 0 }; i < 10; ++i)
    {
        q.push(i);
    }

    cout << q.size();

    return 0;
}
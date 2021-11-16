#pragma once

#include <iostream>

#include "myqueue.hpp"

using namespace myQueue;
using std::cout;
using std::endl;

int main(int argc, char* argv)
{
    Queue<char> q;
    Queue<char> t;

    for (int i{ 0 }; i < 10; ++i)
    {
        q.push('A' + i);
        t.push('a' + 2 * i);
        t.push('a' + 2 * i + 1);
    }

    cout << "q (" << q.size() << "): " << q.front() << " - " << q.back() << endl;
    cout << "t (" << t.size() << "): " << t.front() << " - " << t.back() << endl;

    q.swap(t);

    cout << "q (" << q.size() << "): " << q.front() << " - " << q.back() << endl;
    cout << "t (" << t.size() << "): " << t.front() << " - " << t.back() << endl;

    cout << "q: ";
    while (!q.empty())
    {
        cout << q.front();
        q.pop();
    }

    cout << "\nt: ";
    while (!t.empty())
    {
        cout << t.front();
        t.pop();
    }

    cout << "\nCompare:\n\tEmpty, q != t: " << (q != t) << endl;

    for (int i{ 0 }; i < 4; ++i)
    {
        q.push('A' + i);
        t.push('A' + i);
    }

    cout << "\tEqual, q != t: " << (q != t) << endl;

    q.pop();

    cout << "\tq is shorter, q != t: " << (q != t) << endl;

    q.push('B');

    cout << "\tq has the last symbol unequal, q != t: " << (q != t) << endl;

    for (int i{ 0 }; i < 5; ++i)
    {
        q.push('A' + i);
    }

    Queue<char> r(q);

    cout << "\nr: ";
    while (!r.empty())
    {
        cout << r.front();
        r.pop();
    }

    r = q;
    r = q;
    r = r;

    cout << "\nr: ";
    while (!r.empty())
    {
        cout << r.front();
        r.pop();
    }

    for (int i{ 0 }; i < 5; ++i)
    {
        q.push('A' + i);
    }

    Queue<char>* s = new Queue<char>(q);

    cout << s->back();

    //delete s;
    s->Queue<char>::~Queue();

    cout << endl;
    return 0;
}
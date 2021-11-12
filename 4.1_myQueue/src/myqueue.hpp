#pragma once

#include "node.hpp"

namespace myQueue
{
    template<class T>
    class Queue
    {
    public:
        Queue();
        void push(T);
        T& pop();
        unsigned long size() const;
    private:
        Node<T>* _tail;
        Node<T>* _head;
        unsigned long _size;
    };
}
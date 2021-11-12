#pragma once

namespace myQueue
{
    template<class T>
    class Node
    {
    public:
        Node(T data_ = T{ 0 }, Node* prev_ = nullptr, Node* next_ = nullptr)
            :   _data(data_),
                _prev(prev_),
                _next(next_)
        {
        }
        T _data;
        Node* _next;
        Node* _prev;
    };
}

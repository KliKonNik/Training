#include "myqueue.hpp"

using namespace myQueue;

template<class T>
Queue<T>::Queue()
    :   _tail(nullptr),
        _head(nullptr),
        _size(0)
{
}

template<class T>
void Queue<T>::push(T value)
{
    if (_tail)
    {
        Node<T>* pPreviosTail = _tail;
        _tail->_next = new Node<T>(value);
        _tail = _tail->_next;
        _tail->_prev = pPreviosTail;
        ++_size;
    }
    else
    {
        _head = _tail = new Node<T>(value);
        ++_size;
    }
}

template<class T>
T& Queue<T>::pop()
{
    return T();
}

template<class T>
unsigned long Queue<T>::size() const
{
    return _size;
}
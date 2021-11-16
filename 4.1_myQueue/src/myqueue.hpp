#pragma once

#include "node.hpp"

//(constructor) //constructs the queue                              //(public member function)
//(destructor)  //destructs the queue                               //(public member function)

//Non - member functions
//operator<
//operator<=
//operator>
//operator>=
//operator<=>   //lexicographically compares the values in the queue//(function template)

namespace myQueue
{
    template<class S>
    void swap(S& lVal, S& rVal)
    {
        S tmp = lVal;
        lVal = rVal;
        rVal = tmp;
    }

    template<class T>
    class Queue
    {
    public:
        Queue();
        Queue(const Queue&);
        ~Queue();
        Queue& operator=(const Queue&);

        //Modifiers
        void push(const T&);
        void pop();
        void swap(Queue&);

        //Element access
        T& front();
        const T& front() const;
        T& back();
        const T& back() const;

        //Capacity
        size_t size() const;
        bool empty() const;

        //Non - member functions
        bool operator==(const Queue&) const;
        bool operator!=(const Queue&) const;
    private:
        Node<T>* _tail;
        Node<T>* _head;
        size_t _size;
    };

    template<class T>
    Queue<T>::Queue()
        : _tail(nullptr),
        _head(nullptr),
        _size(0)
    {
    }

    template<class T>
    Queue<T>::Queue(const Queue& source)
        : _tail(nullptr),
        _head(nullptr),
        _size(0)
    {
        if (!source.empty())
        {
            Node<T>* currentNode = source._head;
            while (currentNode)
            {
                push(currentNode->_data);
                currentNode = currentNode->_next;
            }
        }
    }

    template<class T>
    Queue<T>::~Queue()
    {
        if (_size)
        {
            Node<T>* tmp = _head;
            while (tmp != nullptr)
            {
                _head = _head->_next;
                delete tmp;
                tmp = _head;
            }
            _size = 0;
            _tail = _head = nullptr;
        }
    }

    template<class T>
    Queue<T>& Queue<T>::operator=(const Queue& rVal)
    {
        if (this == &rVal) return *this;
        if (_size)
        {
            while (!empty())
            {
                pop();
            }
        }
        if (!rVal.empty())
        {
            Node<T>* currentNode = rVal._head;
            while (currentNode)
            {
                push(currentNode->_data);
                currentNode = currentNode->_next;
            }
        }
    }

    template<class T>
    void Queue<T>::push(const T& value)
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
    void Queue<T>::pop()
    {
        Node<T>* tmp = _head;
        _head = _head->_next;
        delete tmp;
        if (_head == nullptr) _tail = nullptr;
        --_size;
    }

    template<class T>
    void Queue<T>::swap(Queue& other)
    {
        myQueue::swap(_tail, other._tail);
        myQueue::swap(_head, other._head);
        myQueue::swap(_size, other._size);
    }
    
    template<class T>
    T& Queue<T>::front()
    {
        return _head->_data;
    }
    
    template<class T>
    const T& Queue<T>::front() const
    {
        return _head->_data;
    }

    template<class T>
    T& Queue<T>::back()
    {
        return _tail->_data;
    }

    template<class T>
    const T& Queue<T>::back() const
    {
        return _tail->_data;
    }

    template<class T>
    size_t Queue<T>::size() const
    {
        return _size;
    }
    
    template<class T>
    bool Queue<T>::empty() const
    {
        return !_size;
    }

    template<class T>
    bool Queue<T>::operator==(const Queue& rVal) const
    {
        if (_size == rVal._size)
        {
            if (_size == 0) return true;

            Node<T>* leftNode = _head;
            Node<T>* rightNode = rVal._head;
            do
            {
                if ((leftNode->_data) != (rightNode->_data))
                    return false;
                leftNode = leftNode->_next;
                rightNode = rightNode->_next;
            } while (leftNode != nullptr);

            return true;
        }
        else return false;
    }

    template<class T>
    bool Queue<T>::operator!=(const Queue& rVal) const
    {
        return !(*this == rVal);
    }
} // namespace myQueue
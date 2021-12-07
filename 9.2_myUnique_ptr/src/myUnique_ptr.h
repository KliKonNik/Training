#pragma once

#include <iostream>
#include <sstream>
#include <format>
#include <string>
#include <type_traits>

using std::cout;
using std::endl;
using std::format;

namespace myUniquePtr
{
    template<class T>
    std::string to_string(const T& source)
    {
        std::stringstream s;
        s << &source;
        return s.str();
    }

    template<class T>
    class myUnique_ptr
    {
    public:
        myUnique_ptr() noexcept;
        explicit myUnique_ptr(T* ptr_) noexcept;
        ~myUnique_ptr();

        myUnique_ptr(myUnique_ptr&& source) noexcept : _ptr(source.realease()) 
        {
            //cout << format("[{}]: myUnique_ptr::Constructor(&&), _ptr = {}\n", to_string(*this), to_string(_ptr));
            cout << '[' << this << "]: myUnique_ptr::Constructor(&&), _ptr = " << _ptr << '\n';
        }
        myUnique_ptr& operator=(myUnique_ptr&&) noexcept;

        myUnique_ptr(const myUnique_ptr&) = delete;
        myUnique_ptr& operator=(const myUnique_ptr&) = delete;

        T* realease() noexcept;
        void reset(T*) noexcept;
        void swap(myUnique_ptr& other) noexcept;

        const T* get() const noexcept;
        explicit operator bool() const noexcept;

        std::add_lvalue_reference_t<T> operator*() noexcept;
        T* operator->() const noexcept;
    private:
        T* _ptr;
    };

    template<class T>
    myUnique_ptr<T>::myUnique_ptr() noexcept : _ptr(nullptr)
    {
        //cout << format("[{}]: myUnique_ptr::Constructor(), _ptr = {}\n", to_string(*this), to_string(_ptr));
        cout << '[' << this << "]: myUnique_ptr::Constructor(), _ptr = " << _ptr << '\n';
    }
    
    template<class T>
    myUnique_ptr<T>::myUnique_ptr(T* ptr_) noexcept : _ptr(ptr_)
    {
        //cout << format("[{}]: myUnique_ptr::Constructor(T*), _ptr = {}\n", to_string(*this), to_string(_ptr));
        cout << '[' << this << "]: myUnique_ptr::Constructor(), _ptr = " << _ptr << '\n';
    }
    
    template<class T>
    myUnique_ptr<T>::~myUnique_ptr()
    {
        //cout << format("[{}]: myUnique_ptr::Destructor(), _ptr = {}\n", to_string(*this), to_string(_ptr));
        cout << '[' << this << "]: myUnique_ptr::Destructor(), _ptr = " << _ptr << '\n';
        if (_ptr) delete _ptr;
    }

    template<class T>
    myUnique_ptr<T>& myUnique_ptr<T>::operator=(myUnique_ptr&& source) noexcept
    {
        //cout << format("[{}]: myUnique_ptr::operator=(&&[{}]), _ptr = {}, source._ptr = {}\n", to_string(*this), to_string(source), to_string(_ptr), to_string(source._ptr));
        cout << '[' << this << "]: myUnique_ptr::operator=(&&[" << &source << "]), _ptr = " << _ptr << ", source._ptr = " << source._ptr << '\n';

        if (this == &source)
        {
            return *this;
        }

        if (_ptr)
        {
            delete _ptr;
        }

        _ptr = source._ptr;
        source._ptr = nullptr;

        return *this;
    }

    template<class T>
    T* myUnique_ptr<T>::realease() noexcept
    {
        T* pTmp = _ptr;
        _ptr = nullptr;
        return pTmp;
    }

    template<class T>
    void myUnique_ptr<T>::reset(T* pSource) noexcept
    {
        if (_ptr) this->~myUnique_ptr();
        _ptr = pSource;
    }

    template<class T>
    void myUnique_ptr<T>::swap(myUnique_ptr& other) noexcept
    {
        //cout << format("[{}]: myUnique_ptr::swap([{}]), _ptr = {}, other._ptr = {}\n", to_string(*this), to_string(other), to_string(_ptr), to_string(other._ptr));
        cout << '[' << this << "]: myUnique_ptr::swap([" << &other << "]), _ptr = " << _ptr << ", other._ptr = " << other._ptr <<'\n';

        if (this != &other)
        {
            T* pTmp = std::move(other._ptr);
            other._ptr = std::move(_ptr);
            _ptr = std::move(pTmp);
            pTmp = nullptr;
        }
    }

    template<class T>
    const T* myUnique_ptr<T>::get() const noexcept
    {
        return _ptr;
    }

    template<class T>
    myUnique_ptr<T>::operator bool() const noexcept
    {
        return _ptr != nullptr;
    }

    template<class T>
    std::add_lvalue_reference_t<T> myUnique_ptr<T>::operator*() noexcept
    {
        return *_ptr;
    }

    template<class T>
    T* myUnique_ptr<T>::operator->() const noexcept
    {
        return _ptr;
    }

} //namespace myUniquePtr
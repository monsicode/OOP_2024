#pragma once
#include "Shared_ptr.hpp"

template <typename T>
class Weak_ptr{
    T* data;
    Counter* counter;

    void copyFrom(const Weak_ptr<T>& other);
    void free();
    void moveFrom(Weak_ptr<T>&& other);

public:
    Weak_ptr();

    //!!!
    Weak_ptr(Shared_ptr<T>& ptr);

    Weak_ptr(const Weak_ptr<T>& other);
    Weak_ptr& operator=(const Weak_ptr<T>& other);

    Weak_ptr(Weak_ptr<T>&& other);
    Weak_ptr& operator=(Weak_ptr<T>&& other);
    ~Weak_ptr();

    Shared_ptr<T> lock() const;

    bool expired() const;
};
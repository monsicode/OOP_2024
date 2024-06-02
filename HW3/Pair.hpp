#pragma once
#include "iostream"

template<typename T, typename D>
class Pair {
    T one;
    D two;

public:
    Pair(const T& first, const D& second);
    Pair(T&& first, D&& second);
    Pair(const T& first, D&& second);
    Pair(T&& first, const D& second);

    T& first();
    D& second();
    const T& first() const;
    const D& second() const;

    void setFirst(const T& newValue);
    void setFirst(T&& newValue);
    void setSecond(const D& newValue);
    void setSecond(D&& newValue);
};

template<typename T, typename D>
Pair<T,D>::Pair(const T& first, const D& second) : one(first), two(second)
{}


template<typename T, typename D>
Pair<T,D>::Pair(T&& first, D&& second) : one(std::move(first)), two(std::move(second))
{}

template<typename T, typename D>
Pair<T,D>::Pair(const T& first, D&& second) : one(first), two(std::move(second))
{}

template<typename T, typename D>
Pair<T,D>::Pair(T&& first, const D& second) : one(std::move(first)), two(second)
{}

template<typename T, typename D>
T& Pair<T, D>::first() {
    return one;
}

template<typename T, typename D>
D& Pair<T, D>::second() {
    return two;
}

template<typename T, typename D>
const T& Pair<T, D>::first() const {
    return one;
}

template<typename T, typename D>
const D& Pair<T, D>::second() const {
    return two;
}

template<typename T, typename D>
void Pair<T, D>::setFirst(const T& newValue)   {
    one = newValue;
}

template<typename T, typename D>
void Pair<T, D>::setFirst(T&& newValue)   {
    one = std::move(newValue);
}

template<typename T, typename D>
void Pair<T, D>::setSecond(const D& newValue) {
    two = newValue;
}

template<typename T, typename D>
void Pair<T, D>::setSecond(D&& newValue) {
    two = std::move(newValue);
}
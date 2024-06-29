# pragma once
#include <iostream>

struct Counter{
    unsigned weakCounter = 0;
    unsigned sharedCounter = 0;

    void removeSharedPtr(){
        sharedCounter--;

        if(sharedCounter == 0)
             weakCounter--;
    };

    void removeWeakPtr(){
        weakCounter--;
    }

    void addSharedPtr(){
      sharedCounter++;

      if(sharedCounter == 1)
          weakCounter++;
    }

    void addWeakPtr(){
      weakCounter++;
    }
};

template <typename T>
class Shared_ptr {
    T* data;
    Counter* counter;

    //за да има достъп до всички членове на класа
    template<class V>
    friend class Weak_ptr;

public:
    Shared_ptr() : Shared_ptr(nullptr){}
    Shared_ptr(T* data);

    Shared_ptr(const Shared_ptr<T>& other);
    Shared_ptr(Shared_ptr<T>&& other) noexcept;

    Shared_ptr<T>& operator=(const Shared_ptr<T>&);
    Shared_ptr<T>& operator=(Shared_ptr<T>&&);

    ~Shared_ptr();

    T* operator->();
    const T* operator->() const;

    T& operator*();
    const T& operator*() const;

    //?
    bool isInitialize() const;


private:
    void copyFrom(const Shared_ptr<T>&);
    void moveFrom(Shared_ptr<T>&&);
    void free();
};

template<typename T>
void Shared_ptr<T>::copyFrom(const Shared_ptr<T> & other) {
    data = other.data;
    counter = other.counter;

    // реално ние като копираме, добавяме нов ptr, ако не сме копирали празен ptr ще си учеличим брояча
    if(counter)
      counter->addSharedPtr(other);
}

template<typename T>
void Shared_ptr<T>::moveFrom(Shared_ptr<T> && other) {
    data = other.data;
    counter = other.counter;

    other.data = nullptr;
    other.counter = nullptr;
}

template<typename T>
void Shared_ptr<T>::free() {

    if(data == nullptr && counter == nullptr)
        return;

     counter->removeSharedPtr();

    if(counter->sharedCounter == 0)
        delete data;

    if(counter->weakCounter == 0)
        delete counter;
}

template<typename T>
Shared_ptr<T>::Shared_ptr(T* data)
{
    this->data = data;

    if(this->data)
    {
        //!!! да не забравим да заделим памет
        counter = new Counter() ;
        counter->addSharedPtr();
    }

}

template<typename T>
Shared_ptr<T>::Shared_ptr(const Shared_ptr<T>& other)
{
    copyFrom(other);
}

template<typename T>
Shared_ptr<T>::Shared_ptr(Shared_ptr<T>&& other) noexcept{
    moveFrom(std::move(other));
}

template<typename T>
Shared_ptr<T>& Shared_ptr<T>::operator=(const Shared_ptr<T>& other) {
    if(this != other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

template<typename T>
Shared_ptr<T>& Shared_ptr<T>::operator=(Shared_ptr<T> && other) {
    if(this != other)
    {
        free();
        moveFrom(std::move(other));
    }

    return *this;
}

template<typename T>
Shared_ptr<T>::~Shared_ptr()
{
    free();
}


template<typename T>
T* Shared_ptr<T>::operator->(){
    return data;
}

template<typename T>
const T* Shared_ptr<T>::operator->() const{
    return data;
}

template<typename T>
T& Shared_ptr<T>::operator*(){
    if(data == nullptr)
        throw std::runtime_error("Pointer not set");

    return *data;
}

template<typename T>
const T& Shared_ptr<T>::operator*() const{
    if(data == nullptr)
        throw std::runtime_error("Pointer not set");

    return *data;
}

#pragma once
#include <iostream>

template <typename T>
class UniquePtr{
    T* data;
public:
    UniquePtr(T* data);

    UniquePtr(const UniquePtr<T>&) = delete;
    UniquePtr& operator=(const UniquePtr<T>&) = delete;

    UniquePtr(UniquePtr<T>&& other) noexcept;
    UniquePtr& operator=(UniquePtr<T>&& other)noexcept;

    ~UniquePtr();

    T& operator*();
    const T& operator*() const;
};

template<typename T>
UniquePtr<T>::UniquePtr(T* data){
    this->data = data;
}

template<typename T>
UniquePtr<T>::UniquePtr(UniquePtr<T>&& other) noexcept{
   data = other;
   other = nullptr;
}

template<typename T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr<T>&& other) noexcept{
   if(this != &other)
   {
        delete data;
        data = other.data;
        other.data = nullptr;
   }
    return *this;
}

template<typename T>
UniquePtr<T>::~UniquePtr(){
    delete data;
}

template<typename T>
T& UniquePtr<T>::operator*(){
    return *data;
}

template<typename T>
const T& UniquePtr<T>::operator*() const{
    return *data;
}



#pragma once
#include <iostream>

template <typename T>
class Polimorphic_ptr{
    T* data;
public:
    Polimorphic_ptr() = default;
    Polimorphic_ptr(T* data) : data(data){}

    Polimorphic_ptr(const Polimorphic_ptr<T>& other);
    Polimorphic_ptr(Polimorphic_ptr<T>&& other) noexcept;

    //!!! for the return type
    Polimorphic_ptr<T>& operator=(const Polimorphic_ptr<T>& other);
    Polimorphic_ptr<T>& operator=(Polimorphic_ptr<T>&& other) noexcept;

    ~Polimorphic_ptr();

    //what will give me * in polimorphic hierarchy
    const T& operator*() const;
    T& operator*();

    const T* operator->()const;
    T* operator->();

    T* get();
    const T* get() const;

    //Приемането на const T* ptr би ограничило функцията от промяна на обекта,
    //към който сочи указателят, и по този начин би направило унищожаването на обекта неправилно.
    void reset(T*);


   // Oсвобождава контрола над притежавания обект, връща суровия
   // указател и занулява указателя в polymorphic_ptr, без да унищожава обекта.
   // Това позволява предаването на собствеността върху обекта на друг мениджър на ресурси.
    T* release();

private:
    void copyFrom(const Polimorphic_ptr<T>&);
    void moveFrom(Polimorphic_ptr<T>&&);
    void free();
};


//!!! clone()
template<typename T>
void Polimorphic_ptr<T>::copyFrom(const Polimorphic_ptr<T> & other) {
  data = other.data->clone();
}

template<typename T>
void Polimorphic_ptr<T>::moveFrom(Polimorphic_ptr<T>&& other) {
    data = other.data;

    other.data = nullptr;
}

template<typename T>
void Polimorphic_ptr<T>::free() {
    delete data;
}

template<typename T>
Polimorphic_ptr<T>::Polimorphic_ptr(const Polimorphic_ptr<T>& other){
    copyFrom(other);
}


template<typename T>
Polimorphic_ptr<T>::Polimorphic_ptr(Polimorphic_ptr<T>&& other) noexcept
{
    moveFrom(std::move(other));
}

template<typename T>
Polimorphic_ptr<T>& Polimorphic_ptr<T>::operator=(const Polimorphic_ptr<T>& other){
    if(this != other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
Polimorphic_ptr<T>& Polimorphic_ptr<T>::operator=(Polimorphic_ptr<T>&& other) noexcept{
    if(this != other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

template<typename T>
Polimorphic_ptr<T>::~Polimorphic_ptr(){
    free();
}

template<typename T>
const T& Polimorphic_ptr<T>::operator*() const{
    return *data;
}

template<typename T>
T& Polimorphic_ptr<T>::operator*(){
    return *data;
}

template<typename T>
const T* Polimorphic_ptr<T>::operator->()const{
    return data;
}

template<typename T>
T* Polimorphic_ptr<T>::operator->(){
    return data;
}

template<typename T>
T* Polimorphic_ptr<T>::get(){
    return data;
}

template<typename T>
const T* Polimorphic_ptr<T>::get() const{
    return data;
}

template<typename T>
void Polimorphic_ptr<T>::reset(T* ptr){
    free();
    data = ptr;
}

template<typename T>
T* Polimorphic_ptr<T>::release(){
     T* temp = data;
     data=nullptr;

     return temp;
}


















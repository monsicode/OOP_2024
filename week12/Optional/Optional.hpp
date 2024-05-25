#pragma once
#include <iostream>

template <typename T>
class Optional{
    T* data = nullptr;
public:

    Optional() = default;
    Optional(const T& data);

    Optional(const Optional<T>& other);
    Optional(Optional<T>&& other) noexcept;

    Optional<T>& operator=(const Optional<T>& other);
    Optional<T>& operator=(Optional<T>&& other) noexcept;

    ~Optional();

    void setValue(const T& val);
    void setValue(T&& val);

    const T& getValue() const;

    bool hasValue() const;
    void clear();

private:
    void copyFrom(const Optional<T>& other);
    void moveFrom(Optional<T>&& other);
    void free();

};

template <typename T>
Optional<T>::Optional(const T& data){
    this->data =  data;
}

template <typename T>
Optional<T>::Optional(const Optional<T>& other){
    copyFrom(other);
}

template <typename T>
Optional<T>::Optional(Optional<T>&& other) noexcept{
    moveFrom(std::move(other));
}

template <typename T>
Optional<T>& Optional<T>::operator=(const Optional<T>& other){
   if(this != &other)
   {
       free();
       copyFrom(other);
   }
   return *this;
}

template <typename T>
Optional<T>& Optional<T>::operator=(Optional<T>&& other) noexcept{
    if(this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

template <typename T>
Optional<T>::~Optional(){
    free();
}
template <typename T>
void Optional<T>::setValue(const T& val){
    if(hasValue())
        *data = val;
    else
        data = new T(val);
}

template <typename T>
void Optional<T>::setValue(T&& val){
    if(hasValue())
        *data = std::move(val);
    else
        data = new T(std::move(val));
}

template <typename T>
const T& Optional<T>::getValue() const{
    //хубаво е да направим проверка
    if(!hasValue())
        throw std::logic_error("No val to return !");

    return *data;
}

template <typename T>
bool Optional<T>::hasValue() const
{
    return data != nullptr;
}

template <typename T>
void Optional<T>::clear(){
    delete data;
    data = nullptr;
}

template <typename T>
void Optional<T>::copyFrom(const Optional<T>& other){
    if(other.hasValue())
    {
        data = new T (*other.data);
    }
    else
        data = nullptr;
}

template <typename T>
void Optional<T>::moveFrom(Optional<T>&& other){
   data = other.data;
   other.data = nullptr;
}

template <typename T>
void Optional<T>::free(){
    delete data;
}
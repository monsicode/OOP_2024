#pragma once
#include <stdexcept>

template<typename T>
class Optional{
    T* data = nullptr;
public:
    Optional() = default;
    Optional(const T& value);

    Optional(const Optional<T>&);
    Optional(Optional<T>&&) noexcept;

    Optional<T>& operator=(const Optional<T>&);
    Optional<T>& operator=(Optional<T>&&) noexcept;

    ~Optional();

    bool hasValue() const;
    const T& getValue() const;
    void setValue(const T&);
    void setValue(T&&);
    void clear();

private:

    void copyFrom(const Optional<T>&);
    void moveFrom(Optional<T>&&);
    void free();
};

// ? защо в free и moveFrom не правим допълнителни проверки, не е ли необходимо

template<typename T>
void Optional<T>::copyFrom(const Optional<T>& other) {
    if(hasValue())
    {
        *data = other.data;
    }
    else{
        data = new T(*other.data);
    }
}

template<typename T>
void Optional<T>::moveFrom(Optional<T>&& other) {
    if(other.data)
    {
        data = other.data;
        other.data = nullptr;
    }
}

template<typename T>
void Optional<T>::free() {
    if(hasValue())
    {
        delete data;
    }
}

template<typename T>
bool Optional<T>::hasValue() const {
    //    if(data)
    //        return true;
    //    else
    //        return false;

    //!!! може доста по оптимално
    return data;
}

template<typename T>
const T& Optional<T>::getValue() const {
    // ! важно е да правим приверка дали data е валиден
    if(!hasValue())
    {
        throw std::out_of_range("No value to return");
    }
    return *data;
}



template<typename T>
Optional<T>::Optional(const T& value){
    if(!data)
    {
        //!!! имаме ptr -> динамина памет, винаги трабва да заделяме
        data = new T(value);
    }
}


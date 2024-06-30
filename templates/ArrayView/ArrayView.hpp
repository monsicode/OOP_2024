#pragma once
#include <iostream>
#include <stdexcept>
#include <cstring>

template <typename T>
class ArrayView{

    const T* begin = nullptr;
    const T* end = nullptr;

public:
    //тук настройваме указателите да значт къде е началото и къде е края на обекта
    // не разбирам защо в имплементацията трабва този конструктор да бъде delete
    ArrayView(const T* obj): ArrayView(obj[0], obj[sizeof(obj)]){}
    ArrayView(const T* start, const T* end) : begin(start), end(end){}

    size_t getSize()const;
    bool isEmpty() const;

    // не връщаме цял обект, връщаме част от него
    const T& operator[](size_t ind)const;

    template<class F>
    friend std::ostream& operator>>(std::ostream& is, const ArrayView<F>&);

    ArrayView<T> substr(int startPosition, int lenght) const;
};

//!!! трабва да направим  template specialization за string
template<>
ArrayView<char>::ArrayView(const char* obj) : ArrayView(obj, obj + strlen(obj)){}

template<typename T>
size_t ArrayView<T>::getSize()const{
    return end - begin;
}

template<typename T>
bool ArrayView<T>::isEmpty() const{
    return getSize() == 0;
}

template<typename T>
const T& ArrayView<T>::operator[](size_t ind)const{
    return begin[ind];
}


template<class T>
std::ostream& operator<<(std::ostream& os, ArrayView<T>& obj){
    const T* iter = obj.begin;

    while(iter != obj.end)
    {
        os<<*iter;
        iter++;
    }

    return os;
}

template<typename T>
ArrayView<T> ArrayView<T>::substr(int startPosition, int lenght) const {
    //! трабва да върнем нов обект, но преди това проверка

    if(begin + startPosition + lenght > end)
        throw std::out_of_range("Invalid data");

    return ArrayView<T>(begin, end);
}


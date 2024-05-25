#include "DynamicNum.h"


DynamicNum::DynamicNum(){
    capacity = 8;
    data = new int [capacity];
    size = 0;
}

DynamicNum::DynamicNum(const DynamicNum& other){
    copyFrom(other);
}

DynamicNum::DynamicNum(DynamicNum&& other){
    moveFrom(std::move(other));
}

DynamicNum& DynamicNum::operator=(const DynamicNum& other){
 if(this != &other)
 {
     free();
     copyFrom(other);
 }
 return *this;
}
DynamicNum& DynamicNum::operator=(DynamicNum&& other){
    if(this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}
DynamicNum::~DynamicNum(){
    free();
}


//void DynamicNum::add(int num) {
//
//}
//void DynamicNum::remove(int num) {
//
//}
//unsigned DynamicNum::getCount(int num) const {
//
//}
//bool DynamicNum::isIn(int num) const {
//
//}

void DynamicNum::print() const{
    for (int i = 0; i < size; ++i) {
        std::cout<<data[i]<<" ";
    }
}

void DynamicNum::free(){
    delete[] data;
}
void DynamicNum::copyFrom(const DynamicNum& other){
    capacity = other.capacity;

    data = new int [capacity];
    for(int i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }

    size = other.size;
}
void DynamicNum::moveFrom(DynamicNum&& other){
    data = other.data;
    capacity = other.capacity;
    size = other.size;

    other.data = nullptr;
    other.capacity = 0;
    other.size = 0;
}

void DynamicNum::resize() {
     capacity*=2;

     int* newData = new int[capacity];

     for(int i = 0; i < size; i++)
         newData[i] = data[i];

     delete[] data;
     data = newData;

    // не е ли по-добре да направим новата дата да е nullptr, за да не сочат към едмо и също място
     newData = nullptr;
}

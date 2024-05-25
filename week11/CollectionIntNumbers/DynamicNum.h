#pragma once
#include "Collection.h"

//защо този клас трабва да е наследник на collection, има ли друг вариант//

class DynamicNum: public Collection{
protected:
    int* data;
    size_t capacity;
    size_t size;
    void resize();

public:
    DynamicNum();
    DynamicNum(const DynamicNum& other);
    DynamicNum(DynamicNum&& other);
    DynamicNum& operator=(const DynamicNum& other);
    DynamicNum& operator=(DynamicNum&& other);
    ~DynamicNum();

    void print() const override;

//the class stays abstract
//     void add(int) override;
//     void remove(int) override;
//     unsigned getCount(int) const override;
//     bool isIn(int) const override;

private:
    void free();
    void copyFrom(const DynamicNum& other);
    void moveFrom(DynamicNum&& other);

};

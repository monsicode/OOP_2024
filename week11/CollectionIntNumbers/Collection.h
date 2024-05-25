#pragma once
#include <iostream>

// защо в Collection да не сложим protected член-данна unsigned countInSet;

class Collection {
public:

    virtual void add(int) = 0;
    virtual void remove(int) = 0;
    virtual unsigned getCount(int) const = 0;
    virtual bool isIn(int) const = 0;
    virtual void print() const = 0;

    //когато няма default гърми
    virtual ~Collection() = default;

};



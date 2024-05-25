#pragma once
#include "DynamicNum.h"

class SortedCollection: public DynamicNum {

    int lowerBound(int x) const;
    int upperBound(int x) const;

public:
    void add(int) override;
    void remove(int) override;
    unsigned getCount(int) const override;
    bool isIn(int) const override;
};

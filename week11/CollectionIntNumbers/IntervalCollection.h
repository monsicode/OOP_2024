#pragma once
#include "DynamicNum.h"

class IntervalCollection: public DynamicNum {

    int start;
    int end;

    bool isInInterval(int num) const;

public:

    IntervalCollection(int start, int end);

    void add(int) override;
    void remove(int) override;
    unsigned getCount(int) const override;
    bool isIn(int) const override;
};

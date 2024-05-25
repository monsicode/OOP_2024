#pragma once
#include "DynamicNum.h"

class NormalCollection: public DynamicNum {
public:
     void add(int) override;
     void remove(int) override;
     unsigned getCount(int) const override;
     bool isIn(int) const override;
};




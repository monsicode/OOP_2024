#pragma once
#include "ConteinerFunctions.h"

class MaxFunctions :  public ConteinerFunctions {
public:
    MaxFunctions(const Vector<polymorphic_ptr<PartialFunction>> &funcs) ;

    uint32_t operator()(uint32_t number) const override ;
    PartialFunction* clone() const override ;

};



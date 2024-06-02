#pragma once
#include "ConteinerFunctions.h"

class MinFunctions :  public ConteinerFunctions {
public:
    MinFunctions(const Vector<polymorphic_ptr<PartialFunction>> &funcs) ;

    uint32_t operator()(uint32_t number) const override ;

    PartialFunction* clone() const override ;

};


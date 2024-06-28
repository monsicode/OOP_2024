#pragma once
#include "PartialFunction.h"
#include "polymorphic_ptr.hpp"
#include "Vector.hpp"

class ConteinerFunctions : public PartialFunction  {
protected:
    Vector<polymorphic_ptr<PartialFunction>> functions;
public:
    void addFunction(const polymorphic_ptr<PartialFunction>& func);
    void addFunction(polymorphic_ptr<PartialFunction>&& fun);

    unsigned getSize() const;
    bool isDefined(uint32_t number) const override;
};

//!  this funcs are missing here so the class will be abstract !
//virtual  uint32_t operator()(uint32_t number) const = 0;
//virtual PartialFunction *clone() const = 0;

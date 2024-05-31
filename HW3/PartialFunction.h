#pragma once
#include "iostream"

class PartialFunction {
public:

    virtual bool isDefined(uint32_t number) const = 0;
    virtual uint32_t calculate(uint32_t number) const = 0;

    virtual uint32_t operator()(uint32_t number) const = 0;
    //virtual uint32_t operatorbool(uint32_t number) const = 0;

    virtual PartialFunction *clone() const = 0;
    virtual ~PartialFunction() = default;

};



#include "MaxFunctions.h"

MaxFunctions::MaxFunctions(const Vector<polymorphic_ptr<PartialFunction>> &funcs) {
    for (int i = 0; i < funcs.getSize(); ++i) {
        addFunction(funcs[i]);
    }
}

uint32_t MaxFunctions::operator()(uint32_t number) const {
//    if(!isDefined(number))
//        throw std::logic_error("Can't return max result, a functions is not defined!");

    uint32_t maxResult = 0;

    for (int i = 0; i < functions.getSize(); i++) {
        maxResult = std::max(maxResult,functions[i]->operator()(number));
    }

   return maxResult;
}

PartialFunction* MaxFunctions::clone() const {
    return new MaxFunctions(*this);
}
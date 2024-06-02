#include "MinFunctions.h"

MinFunctions::MinFunctions(const Vector<polymorphic_ptr<PartialFunction>> &funcs) {
    for (int i = 0; i < funcs.getSize(); ++i) {
        addFunction(funcs[i]);
    }
}

uint32_t MinFunctions::operator()(uint32_t number) const {
    if(!isDefined(number))
        throw std::logic_error("Can't return max result, a functions is not defined!");

    uint32_t minResult = UINT32_MAX;

    for (int i = 0; i < functions.getSize(); i++) {
        minResult = std::min(minResult,functions[i]->operator()(number));
    }

    return minResult;
}

PartialFunction* MinFunctions::clone() const {
    return new MinFunctions(*this);
}
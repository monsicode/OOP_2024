#include "MinFunctions.h"

MinFunctions::MinFunctions(const Vector<polymorphic_ptr<PartialFunction>> &funcs) {
    for (int i = 0; i < funcs.getSize(); ++i) {
        addFunction(funcs[i]);
    }
}

uint32_t MinFunctions::operator()(uint32_t number) const {
    uint32_t minResult = UINT32_MAX;

    for (int i = 0; i < functions.getSize(); i++) {
        try{
            minResult = std::min(minResult,functions[i]->operator()(number));
        }
        catch(std::logic_error& err)
        {
            std::cout<<err.what()<<" ";
            return -1;
        }
    }

    return minResult;
}

PartialFunction* MinFunctions::clone() const {
    return new MinFunctions(*this);
}
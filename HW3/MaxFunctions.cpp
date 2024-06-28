#include "MaxFunctions.h"

MaxFunctions::MaxFunctions(const Vector<polymorphic_ptr<PartialFunction>> &funcs) {
    for (int i = 0; i < funcs.getSize(); ++i) {
        addFunction(funcs[i]);
    }
}

uint32_t MaxFunctions::operator()(uint32_t number) const {
    uint32_t maxResult = 0;

    for (int i = 0; i < functions.getSize(); i++) {
        try{
            maxResult = std::max(maxResult,functions[i]->operator()(number));
        }
        catch(std::logic_error& err)
        {
            std::cout<<err.what()<<" ";
            return 0;
        }
    }

   return maxResult;
}

PartialFunction* MaxFunctions::clone() const {
    return new MaxFunctions(*this);
}
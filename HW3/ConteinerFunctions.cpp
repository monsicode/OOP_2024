#include "ConteinerFunctions.h"

void ConteinerFunctions::addFunction(const polymorphic_ptr<PartialFunction>& func) {
    functions.pushBack(func);
}

void ConteinerFunctions::addFunction(polymorphic_ptr<PartialFunction>&& func) {
    functions.pushBack(func);
}

unsigned ConteinerFunctions::getSize() const{
    return functions.getSize();
}

bool ConteinerFunctions::isDefined(uint32_t number) const {
    for (size_t i = 0; i < functions.getSize(); ++i) {
        if (!functions[i]->isDefined(number)) {
            return false;
        }
    }
    return true;
}


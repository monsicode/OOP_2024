#pragma once

#include "Conteiner.h"
#include "PartialFunction.h"

class MaxFunctions : public CollectionFunctions {
public:

    MaxFunctions(const CollectionFunctions &functions);

    void test() const {
        for (int i = 0; i < getSize(); ++i) {
//            std::cout << data[i]->calculate(4) << " ";
        }
    }



//    bool isDefined(uint32_t number) const override;
//    uint32_t calculate(uint32_t number) const override;
//
//    uint32_t operator()(uint32_t number) const override;
//    PartialFunction* clone() const override;

};
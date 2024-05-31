#pragma once
#include "Conteiner.h"
#include <cstdint>

class MaximumPartialFunction : public CollectionFunctions {
public:

    MaximumPartialFunction(const Vector<polymorphic_ptr<PartialFunction>>& funcs) {
        for (int i = 0; i < size; ++i) {
            addFunction(funcs[i]);
        }
    }

    // Операция за проверка дали функцията е дефинирана
    bool isDefined(uint32_t number) const override {
        for (int i = 0; i < size; ++i){
            if (!functions[i]->isDefined(number))
                return false;
        }
        return true;
    }

    uint32_t calculate(uint32_t number) const override {
        uint32_t maxResult = 0;
        bool defined = false;
        for (int i = 0; i < size; ++i) {
            if (functions[i]->isDefined(number)) {
                defined = true;
                maxResult = std::max(maxResult, functions[i]->calculate(number));
            }
        }
        return defined ? maxResult : 0;
    }

    MaximumPartialFunction* clone() const override {
        return new MaximumPartialFunction(*this);
    }

    void test() const{

    }
};










//class MaxFunctions : public CollectionFunctions {
//public:
//
//    MaxFunctions(const CollectionFunctions& functions);
//
//    void test() const {
//        for (int i = 0; i < getSize(); ++i) {
//           std::cout << functions[i]->calculate(4) << " ";
//        }
//    }
//
//
//
////    bool isDefined(uint32_t number) const override;
////    uint32_t calculate(uint32_t number) const override;
////
////    uint32_t operator()(uint32_t number) const override;
////    PartialFunction* clone() const override;
//
//};
#pragma once
#include "PartialFunction.h"

template <class Function>
class FunctionByCriteria : public PartialFunction {
    Function fun;

//    struct FunctionResult{
//        bool isDef;
//        uint32_t value;
//    };

public:
     //FunctionByCriteria() = default;
     FunctionByCriteria(const Function& fun);

     bool isDefined(uint32_t number) const override;
     uint32_t calculate(uint32_t number) const override;

     uint32_t operator()(uint32_t number) const override;
     //uint32_t operatorbool(uint32_t number) const override;


     PartialFunction* clone() const override;

};


template <class Function>
FunctionByCriteria<Function>::FunctionByCriteria(const Function& fun):fun(fun){}

template <class Function>
bool FunctionByCriteria<Function>::isDefined(uint32_t number) const{
 return true;
}

template <class Function>
uint32_t FunctionByCriteria<Function>::calculate(uint32_t number) const{
    return number;
}

template <class Function>
uint32_t FunctionByCriteria<Function>::operator()(uint32_t number) const{
   return fun(number);
}

//template <class Function>
//uint32_t FunctionByCriteria<Function>::operatorbool(uint32_t number) const{
//
//}

template <class Function>
PartialFunction* FunctionByCriteria<Function>::clone() const{
   return new FunctionByCriteria<Function>(*this);
}







//protected:
//    struct FunctionResult{
//        bool defined;
//        uint32_t result;
//    };
//
//    using Function = const FunctionResult& (*)(uint32_t);
//
//    Function function;
//
//public:
//    //FunctionByCriteria(const Function& fun);
//
//    bool isDefined(uint32_t number) const override;
//    //uint32_t calculate(uint32_t number) const override;
//
//     uint32_t operator()(uint32_t number) const override{
//          function(number);
//     }

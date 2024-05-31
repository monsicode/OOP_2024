#include <iostream>

#include "FunctionByCriteria.hpp"
//#include "Conteiner.h"
#include "MaxFunctions.h"

using namespace std;

class Function1 {
public:
    uint32_t operator()(uint32_t num) const {
        return num / 2;
    }
};
class Function2 {
public:
    uint32_t operator()(uint32_t num) const {
        return num  * 2;
    }
};

int main() {

    Function1 fun1;
    FunctionByCriteria<Function1> cr(fun1);

    Function2 fun2;
    FunctionByCriteria<Function2> cr2(fun2);


    // Създаване на обект от тип MinimumPartialFunction
    Vector<polymorphic_ptr<PartialFunction>> funcs = { fun1, fun2 };
    MaximumPartialFunction minFunc(funcs);

    // Проверка на стойността на функцията за някои числа
    std::cout << "MinimumPartialFunction(2) = " << minFunc.calculate(2) << std::endl;
    std::cout << "MinimumPartialFunction(5) = " << minFunc.calculate(5) << std::endl;

    // Създаване на обект от тип MaximumPartialFunction
    MaximumPartialFunction maxFunc(funcs);



//    Function1 fun1;
//
//    FunctionByCriteria<Function1> cr(fun1);
//
//    CollectionFunctions col;
//
//    col.addFunction(new FunctionByCriteria<Function1>(fun1));
//    col.addFunction(new FunctionByCriteria<Function1>(fun1));



//    MaximumPartialFunction maxF(col);
//
//    maxF.test();

}

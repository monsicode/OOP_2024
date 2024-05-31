#include <iostream>

#include "FunctionByCriteria.hpp"
#include "Conteiner.h"
#include "MaxFunctions.h"

using namespace std;

class Function1 {
public:
    uint32_t operator()(uint32_t num) const {
        return num / 2;
    }
};

int main() {

    Function1 fun1;

    FunctionByCriteria<Function1> cr(fun1);

//    CollectionFunctions col;
//
//    col.addFunction(new FunctionByCriteria<Function1>(fun1));
//    col.addFunction(new FunctionByCriteria<Function1>(fun1));
//
//    MaxFunctions maxF(col);

  //  maxF.test();

}

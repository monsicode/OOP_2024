#include <iostream>
#include "FunctionByCriteria.hpp"

#include "MaxFunctions.h"
#include "MinFunctions.h"

using namespace std;
using Function = Pair<bool, uint32_t> (*)(int);
using PolimorphicPtr = polymorphic_ptr<PartialFunction>;

int main() {
    try {
        Function bebe = [](int x) {
            Pair<bool,uint32_t> test(1,x * x);
            return test;
        };

        bebe(4).first();

        PartialFunction* ptr = new FunctionByCriteria<Function>(bebe);

        PolimorphicPtr func1 = polymorphic_ptr<PartialFunction>(new FunctionByCriteria(bebe));
        PolimorphicPtr func2 = polymorphic_ptr<PartialFunction>(new FunctionByCriteria([](int x) {
            Pair<bool,uint32_t> test2(1,x * 2 - 1 );
            return test2;
        }));
        PolimorphicPtr func3 = polymorphic_ptr<PartialFunction>(new FunctionByCriteria([](int x) {
            Pair<bool,uint32_t> test2(1,x  + 5);
            return test2;
        }));


        Vector<polymorphic_ptr<PartialFunction>> funcs;
        funcs.pushBack(func1);
        funcs.pushBack(func2);
        funcs.pushBack(func3);

        MaxFunctions maxFunc(funcs);
        MinFunctions minFunc(funcs);

     cout<< "This is the maximum result of your function: " << maxFunc(3) <<endl;
     cout<< "and this is the min result of your functon: " << minFunc(3) <<endl;

    }
    catch (std::logic_error) {
        cout << "Function is not defined here";
    }
    catch(...)
    {
        cout<<"Some error";
    }


}

//        Function bebe = [](int x) {
//            FunctionResult test(x * 2);
//            return test;
//        };
//
//        FunctionByCriteria<Function> func(bebe);
//
//        ptrConteiner func1 = polymorphic_ptr<PartialFunction>(new FunctionByCriteria(bebe));
//        ptrConteiner func2 = polymorphic_ptr<PartialFunction>(new FunctionByCriteria([](int x) {
//            FunctionResult test2(x);
//            return test2;
//        }));
//
//        Vector<polymorphic_ptr<PartialFunction>> funcs;
//        funcs.pushBack(func1);
//        funcs.pushBack(func2);
//
//        MaximumPartialFunction maxFunc(funcs);
//        FunctionResult* kur = new FunctionResult (maxFunc(2));
//        std::cout << "MaximumPartialFunction(2) = " << kur->getResult() << std::endl;
//    }
#pragma once
#include <iostream>
#include <cstring>

#include "FunctionByCriteria.hpp"
#include "MaxFunctions.h"
#include "MinFunctions.h"
#include "BinaryFileManager.h"


using Function = Pair<bool, uint32_t> (*)(int);
using PolimorphicPtr = polymorphic_ptr<PartialFunction>;

class Console {

    PolimorphicPtr functionToSolve;

    bool isCorrect(int a, int b ) const;

public:

    Console(const char* fileName);
    void rangeAll(int a, int b) const;
    void rangeGenerate(int a, int b) const;
};



#pragma once
#include <fstream>

#include "CaseZeroFunction.h"
#include "CaseOneFunction.h"
#include "CaseTwoFunction.h"
#include "MaxFunctions.h"
#include "MinFunctions.h"
#include "PartialFunction.h"
#include "FunctionByCriteria.hpp"


using Function = Pair<bool, uint32_t> (*)(int);
using PolimorphicPtr = polymorphic_ptr<PartialFunction>;

//only using this class as a wrapper of some functionalities
class BinaryFileManager {
public:
    static polymorphic_ptr<PartialFunction> read(const char* fileName);
private:
    static const char* readString(std::ifstream& file) ;
    static uint32_t readUint(std::ifstream& file) ;
};


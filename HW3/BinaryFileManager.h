#pragma once
#include <fstream>
//#include "Vector.hpp"
//#include "Pair.hpp"
#include "CaseZeroFunction.h"
#include "CaseOneFunction.h"
#include "CaseTwoFunction.h"
#include "MaxFunctions.h"
#include "MinFunctions.h"
#include "PartialFunction.h"
#include "FunctionByCriteria.hpp"


using Function = Pair<bool, uint32_t> (*)(int);
using PolimorphicPtr = polymorphic_ptr<PartialFunction>;

class BinaryFileManager {
public:
    BinaryFileManager();

    polymorphic_ptr<PartialFunction> read(const char* fileName);
    void write(const char* fileName) const;
    const char* readString(std::ifstream& file) const;
private:

    uint32_t readUint(std::ifstream& file) const;

};



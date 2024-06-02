#pragma once
#include <fstream>
//#include "Vector.hpp"
//#include "Pair.hpp"
#include "CaseZeroFunction.h"
#include "MaxFunctions.h.h"
#include "MinFunctions.h.h"
#include "PartialFunction.h"
#include "FunctionByCriteria.hpp"
#include "polymorphic_ptr.hpp"


using Function = Pair<bool, uint32_t> (*)(int);

class BinaryFileManager {
public:

    BinaryFileManager(const char* fileName);

    void read(const char* fileName);
    void write(const char* fileName) const;

private:
    uint32_t readUint(std::ifstream& file);

};



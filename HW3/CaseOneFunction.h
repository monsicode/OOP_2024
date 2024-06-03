#pragma once

#include "Vector.hpp"
#include "Pair.hpp"

class CaseOneFunction {
    Vector<uint32_t> arguments;
    size_t sizeN = 0;

    bool isIn(uint32_t num) const;

public:
    CaseOneFunction(const Vector<uint32_t>& args, uint32_t N);
    Pair<bool, uint32_t> operator()(uint32_t) const;

};





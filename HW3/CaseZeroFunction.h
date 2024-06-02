#pragma once
#include "Vector.hpp"
#include "Pair.hpp"

class CaseZeroFunction {
    Vector<uint32_t> arguments;
    Vector<uint32_t> result;
    size_t sizeN = 0;
public:
    CaseZeroFunction(const Vector<uint32_t>& args, const Vector<uint32_t>& res, uint32_t N);
    Pair<bool, uint32_t> operator()(uint32_t) const;
};



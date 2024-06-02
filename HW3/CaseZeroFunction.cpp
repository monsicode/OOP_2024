#include "CaseZeroFunction.h"

CaseZeroFunction::CaseZeroFunction(const Vector<uint32_t> &args, const Vector<uint32_t> &res, uint32_t N) {
    arguments = args;
    result = res;

    sizeN = N;
}

Pair<bool, uint32_t> CaseZeroFunction::operator()(uint32_t num) const {
    Pair<bool, uint32_t> toReturn(false,0);

    for (int i = 0; i < sizeN; i++)
    {
        if (arguments[i] == num)
        {
            toReturn.setFirst(1);
            toReturn.setSecond(result[i]);

            return toReturn;
        }
    }
    return toReturn;
}
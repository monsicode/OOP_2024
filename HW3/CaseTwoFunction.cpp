#include "CaseTwoFunction.h"

bool CaseTwoFunction::isIn(uint32_t num) const{
    for(int i = 0; i < sizeN; i++)
    {
        if(arguments[i] == num)
            return true;
    }
    return false;
}

CaseTwoFunction::CaseTwoFunction(const Vector<uint32_t>& args, uint32_t N){
    arguments = args;
    sizeN = N;
}

Pair<bool, uint32_t> CaseTwoFunction::operator()(uint32_t number) const
{
    Pair<bool, uint32_t> toReturn(true,0);

    if(isIn(number))
    {
        toReturn.setSecond(1);
        return toReturn;
    }

    return toReturn;

}

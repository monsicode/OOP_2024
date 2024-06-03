#include "CaseOneFunction.h"

bool CaseOneFunction::isIn(uint32_t num) const{
    for(int i = 0; i < sizeN; i++)
    {
        if(arguments[i] == num)
            return true;
    }
    return false;
}

CaseOneFunction::CaseOneFunction(const Vector<uint32_t>& args, uint32_t N){
    arguments = args;
    sizeN = N;
}

Pair<bool, uint32_t> CaseOneFunction::operator()(uint32_t number) const
{
    if(isIn(number))
    {
         throw std::logic_error("This number is not defined");
    }

    Pair<bool, uint32_t> toReturn(true,number);

    return toReturn;

}

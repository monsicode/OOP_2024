#include <iostream>

enum class errorCode{
    OK,
    EmptyString,
    NullPtr
};

bool isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

int convertChatToNum(char ch)
{
    return ch - '0';
}

struct Result{
    errorCode code;
    unsigned number;
};

Result converStringToInt(const char* str)
{
    if(!str)
        return {errorCode::NullPtr, 0};

    if(!*str)
        return {errorCode::EmptyString, 0};

    unsigned number = 0;

    while(*str)
    {
        if(isDigit(*str)) {
            number *= 10;
            number += convertChatToNum(*str);
        }
        str++;
    }

    return {errorCode::OK, number};

}


int main() {

    Result ans;
    ans = converStringToInt("as23");

    if (ans.code == errorCode::OK)
     std::cout << ans.number;
    else
        std::cout<<"Error!";

}
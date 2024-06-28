#include "Console.h"

void Console::swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

bool Console::isCorrect(int a, int b) const {
    if (a < 0 && b < 0)
        return false;
    return true;
}

Console::Console(const char *fileName) {
    try {
        functionToSolve = BinaryFileManager::read(fileName);
    }
    catch (std::ios_base::failure &err) {
        std::cout << err.what();
    }
}

void Console::rangeAll(int& a, int& b) const {
    if (!isCorrect(a, b))
        throw std::out_of_range("Your range can't be in negative!");

    if (a < 0)
        a = 0; // we make the lower bound to be zero

    if (b < 0)
        b = 0;

    if(a > b)
        swap(a,b);

    std::cout << "Result: \n";
    for (int i = a; i < b; i++) {
        if (functionToSolve->isDefined(i)) {
            std::cout << "f(" << i << ") = " << functionToSolve->operator()(i);
            std::cout << std::endl;
        }
    }
}

void Console::rangeGenerate(int& curr, int b) const {
    if (!isCorrect(curr, b))
        throw std::out_of_range("Your range can't be in negative!");

    if (curr < 0)
        curr = 0;

    std::cout << "Result: \n";

    //in this case if the function is not defined it will print it's not defined
    std::cout << "f(" << curr << ") = " << functionToSolve->operator()(curr);
    std::cout << std::endl;

}
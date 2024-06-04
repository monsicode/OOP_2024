#include "Console.h"

bool Console::isCorrect(int a, int b) const {
    if (a < 0 && b < 0)
        return false;
    return true;
}

Console::Console(const char *fileName) {
    functionToSolve = manager.read(fileName);
}

void Console::range(int a, int b) const {
    if (!isCorrect(a, b))
        throw std::out_of_range("Your range can't be in negative!");

    std::cout << "Your range is: [ " << a << " " << b << " ] ";
    std::cout << std::endl;

    if (a < 0)
        a = 0; // we make the lower bound to be zero


    for (int i = a; i < b; i++) {
        if (functionToSolve->isDefined(i)) {
            std::cout << "f(" << i << ") = " << functionToSolve->operator()(i);
            std::cout << std::endl;
        }
    }
}

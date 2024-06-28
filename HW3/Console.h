#pragma once
#include <iostream>
#include <cstring>

#include "BinaryFileManager.h"

class Console {

    PolimorphicPtr functionToSolve;
    bool isCorrect(int a, int b ) const;

public:

    Console(const char* fileName);

    //first mode
    void rangeAll(int& a, int& b) const;

    //second mode
    void rangeGenerate(int& a, int b) const;

    static void swap(int& a, int& b);
};



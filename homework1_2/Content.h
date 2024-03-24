#pragma once
#include "Constants.h"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace constants;

class Content{
    char text[MAX_SIZE_CONTENT];

    char getChar(size_t pos) const;

public:

    Content();

    Content(const char* fileName);

    void readFrom(const char* fileName);


    int getCharPos(int k) const;

    void changeKBit(unsigned k);

    void mixWith(const Content& str);

    void saveTo(const char* fileName) const;

};
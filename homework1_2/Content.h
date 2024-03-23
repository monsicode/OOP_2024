#pragma once
#include "Constants.h"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace constants;

class Content{
    char text[MAX_SIZE_CONTENT];


    char getChar(int pos) const
    {
        return text[pos];
    }


public:

    Content(){}

    Content(const char* fileName){
        readFrom(fileName);
    }

    void readFrom(const char* fileName) {
        std::ifstream ifs(fileName, std::ios::binary | std::ios::in);

        if (!ifs.is_open()) {
            std::cout << "File is not open!" << std::endl;
            return;
        }

        ifs.read(text, MAX_SIZE_CONTENT);

        ifs.close();
    }


    int getCharPos(int k) const
    {
      return k / 8;
    }

    void changeKBit(int k){

        for(int i = 0; i < MAX_SIZE_CONTENT; i+=k)
        {
            int pos = getCharPos(i);
            int posInMask = k % 8;

            text[pos] |= (1<<posInMask);
        }
    }

    void mixWith(const Content& str){
        int sizeFirst = strlen(text);
        int sizeSecond = strlen(str.text);

        int minimum = sizeFirst > sizeSecond ? sizeSecond : sizeFirst;
        for (int i = 0; i < minimum;++i) {
            text[i] ^= str.getChar(i);
        }
    }

    void saveTo(const char* fileName) const{
            std::ofstream ofs(fileName, std::ios::binary);

            if(!ofs.is_open())
            {
                return ;
            }

            ofs.write((const char*)text, sizeof(text));
            ofs.close();

    }

    void addContent(const char* text)
    {
        strcpy(this->text,text);
    }

    void printCont()const{
        std::cout<<text;
    }

};
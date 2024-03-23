#pragma once
#include <iostream>
#include "Constants.h"

using namespace constants;

class Genre {
    unsigned char genre;

    void addGenre(char str);
    char getFromBucket(int index) const;
    int getGenreBucket(char genre) const ;

public:
    Genre(const char* str);
    void printGenre() const;

    void setGenere(const char* str)
    {
        for(int i = 0; str[i] != '\0'; i++ )
        {
            addGenre(str[i]);
        }
    }


};



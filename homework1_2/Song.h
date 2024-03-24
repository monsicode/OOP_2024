#pragma once
#include <iostream>
#include "Constants.h"
#include "Content.h"
#include "Time.h"
#include "Genre.h"

using namespace constants;

class Song{
    char name[MAX_SIZE_SONG];
    Time time;
    Genre genre;
    Content contentSong;

public:

    Song(){};

    void addToSong(const char* name, size_t hours, size_t min, size_t seconds, const char* str);

   void readSong(const char* fileName);

   void printSong() const;

   const char* getName() const;

   char getGenreSong() const;

    void mixSong(const Song& s2);

    void saveTo(const char* fileName) const;

    void changeKBit(int k);

    const Time& getTime() const;

};
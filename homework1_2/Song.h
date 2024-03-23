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

    void addToSong(const char* name, size_t hours, size_t min, size_t seconds, const char* str){
        strcpy(this->name, name);
        time.setHours(hours);
        time.setMins(min);
        time.setSeconds(seconds);
        genre.setGenere(str);
    }

   void readSong(const char* fileName)
   {
     contentSong.readFrom(fileName);
   }

   void printSong() const
   {
       std::cout<<name<< " " ;
       time.serialize(std::cout);
       genre.printGenre();
   }

   const char* getName() const
   {
    return name;
   }

   char getGenreSong() const{
        return genre.getGenre();
    }

    void mixSong(const Song& s2)
    {
        contentSong.mixWith(s2.contentSong);
    }

    void saveTo(const char* fileName)
    {
        contentSong.saveTo(fileName);
    }

};
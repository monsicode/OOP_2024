#pragma once
#include "Song.h"
#include "Time.h"

class Playlist {

    Song songs[MAX_SIZE_SONGS];
    size_t countSongs = 0;

    bool validCount() const{
        return countSongs < MAX_SIZE_SONGS;
    }

public:

    Playlist();

    void add(const char* name, size_t hours, size_t min, size_t seconds, const char* str, const char* fileName){
        if(!validCount())
        {
            cout<<"Error, max count songs reached";
            return;
        }

        songs[countSongs].addToSong(name,hours,min,seconds,str);
        songs[countSongs].readSong(fileName);

        countSongs++;
    }

    void print() const;

    void find(const Song& song) const;

    void findGenre(char genre) const;

    void mix(const Song& s1, const Song& s2);

    void save(const Song& song, const char* fileName);


};



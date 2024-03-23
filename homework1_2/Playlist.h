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

    void print() const{
        for (int i = 0; i < countSongs; ++i) {
            songs[i].printSong();
        }
    }

    size_t find(const char* sName) const {

        for (int i = 0; i < countSongs; ++i) {
            if (strcmp(songs[i].getName(), sName) == 0) {
                //songs[i].printSong();
                return i;
                break;
            }
        }
        return -1;
    }

    void findGenre(const char* genre) const{
        Genre temp(genre);

        for (int i = 0; i < countSongs; ++i) {
            if (songs[i].getGenreSong() == temp.getGenre()){
                songs[i].printSong();
                break;
            }
        }
    }

    void mix(const char* s1,const char* s2){

       size_t pos1 = find(s1);
       size_t pos2 = find(s2);

       if(pos1==-1 || pos2==-1)
       {
           cout<<"Songs not found ";
           return;
       }

       songs[pos1].mixSong(songs[pos2]);
    }

    void sortByName()
    {

    }

    void save(const char* song, const char* fileName)
    {
       int pos = find(song);

       songs[pos].saveTo(fileName);
    }

};



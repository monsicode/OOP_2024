#pragma once
#include "Song.h"
#include "Time.h"

class Playlist {

    Song songs[MAX_SIZE_SONGS];
    size_t countSongs = 0;

    bool validCount() const{
        return countSongs < MAX_SIZE_SONGS;
    }

    void insertionSort(bool (*comparator)(Song& a, Song& b)) {
        Song key;
        int j;
        for (int i = 1; i < countSongs; i++) {
            key = songs[i];
            j = i - 1;

            while (j >= 0 && comparator(songs[j], key)) {
                songs[j + 1] = songs[j];
                j--;
            }

            songs[j + 1] = key;
        }
    }



public:

    size_t getSong(const char* sName) const {

        for (int i = 0; i < countSongs; ++i) {
            if (strcmp(songs[i].getName(), sName) == 0) {
                //songs[i].printSong();
                return i;
                break;
            }
        }
        return -1;
    }

    Playlist(){};

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
            std::cout<<std::endl;
        }
    }


    void find(const char* sName) const {

        for (int i = 0; i < countSongs; ++i) {
            if (strcmp(songs[i].getName(), sName) == 0) {
                songs[i].printSong();
                std::cout << std::endl;
                break;
            }
        }
    }

    void findGenre(const char* genre) const{
        Genre temp(genre);

        for (int i = 0; i < countSongs; ++i) {
            if ((songs[i].getGenreSong() & temp.getGenre()) == temp.getGenre()){
                songs[i].printSong();
                std::cout<<std::endl;
            }
        }
    }

    void mix(const char* s1,const char* s2){

       size_t pos1 = getSong(s1);
       size_t pos2 = getSong(s2);

       if(pos1==-1 || pos2==-1)
       {
           cout<<"Songs not found ";
           return;
       }

       songs[pos1].mixSong(songs[pos2]);
    }


    void sortByName()
    {
        insertionSort([](Song& a, Song& b) {
            return strcmp(a.getName(), b.getName()) > 0;
        });
    }

    //TODO
    void sortByDuration()
    {

    }
    void save(const char* song, const char* fileName)
    {
       int pos = getSong(song);

       songs[pos].saveTo(fileName);
    }

    void read(const char* song,const char* fileName)
    {
        int pos = getSong(song);

        songs[pos].readSong(fileName);
        songs[pos].printSong();
    }

};



#pragma once
#include "Song.h"
#include "Time.h"

class Playlist {

    Song songs[MAX_SIZE_SONGS];
    size_t countSongs = 0;

    enum class Criteria {
        sortByName,
        sortByDuration
    };

    bool validCount() const;
    void sortHelper(const Criteria& cr);
    void insertionSort(bool (*comparator)(Song& a, Song& b)) ;
    bool validate(int pos) const;

public:

    int getSong(const char* sName) const ;

    Playlist();

    void add(const char* name, size_t hours, size_t min, size_t seconds, const char* str, const char* fileName);

    void print() const;
    void find(const char* sName) const ;

    void findGenre(const char* genre) const;

    void mix(const char* s1,const char* s2);

    void sortByName();
    void sortByDuration();

    void save(const char* song, const char* fileName) const;
    void read(const char* song,const char* fileName);

    void changeKBit(const char* songName, unsigned bit);

};



#include "Song.h"

void Song::addToSong(const char* name, size_t hours, size_t min, size_t seconds, const char* str){
    strcpy(this->name, name);
    time.setHours(hours);
    time.setMins(min);
    time.setSeconds(seconds);
    genre.setGenere(str);
}

void Song::readSong(const char* fileName)
{
    contentSong.readFrom(fileName);
}

void Song::printSong() const
{
    std::cout<<name<< " " ;
    time.serialize(std::cout);
    genre.printGenre();
}

const char* Song::getName() const
{
    return name;
}

char Song::getGenreSong() const{
    return genre.getGenre();
}

void Song::mixSong(const Song& s2)
{
    contentSong.mixWith(s2.contentSong);
}

void Song::saveTo(const char* fileName) const
{
    contentSong.saveTo(fileName);
}

void Song::changeKBit(unsigned k)
{
    contentSong.changeKBit(k);
}

const Time& Song::getTime() const{
    return time;
}
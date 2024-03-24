#include "Genre.h"

void Genre::addGenre(char str){
    int mask = getGenreBucket(str);

    if(mask == -1)
    {
        std::cout << "Invalid return genre";
        return;
    }

    genre |=(1<<mask);
}

const char* Genre::getFromBucket(size_t index) const
{
    switch(index) {
        case 0:
            return "Rock";
        case 1:
            return "Pop";
        case 2:
            return "Hip-hop";
        case 3:
            return "Electro";
        case 4:
            return "Jazz";
    }
}

int Genre::getGenreBucket(char genre) const {
    switch(genre) {
        case 'r':
            return 0;
        case 'p':
            return 1;
        case 'h':
            return 2;
        case 'e':
            return 3;
        case 'j':
            return 4;
        default:
            return -1;
    }
}

Genre::Genre(const char* str)
{
    setGenere(str);
}

void Genre::printGenre() const{
    for (int i = 0; i < 5; ++i) {
        if(genre & (1<<i)){
            std::cout<<getFromBucket(i)<<" ";
        }
    }
}

void Genre::setGenere(const char* str)
{
    for(int i = 0; str[i] != '\0'; i++ )
    {
        addGenre(str[i]);
    }
}

unsigned char Genre::getGenre() const{
    return genre;
}


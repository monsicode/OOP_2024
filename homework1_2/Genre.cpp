#include "Genre.h"


void Genre::addGenre(char str){
    int mask = getGenreBucket(str);

    genre |=(1<<mask);
}

char Genre::getFromBucket(int index) const
{
    switch(index) {
        case 0:
            return 'r';
        case 1:
            return 'p';
        case 2:
            return 'h';
        case 3:
            return 'e';
        case 4:
            return 'j';
        default:
            return -1;
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
            std::cout<<getFromBucket(i);
        }
    }
}

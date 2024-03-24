#include <iostream>
#include "Playlist.h"

int main() {

    Playlist p;
    p.add("Song2", 0, 3, 55, "rp","song.dat");
    p.add("Alabama", 0, 3, 46, "h","song1.dat");
    p.add("Zeze", 0, 2, 40, "r","song2.dat");

    p.sortByDuration();
    p.print();


}

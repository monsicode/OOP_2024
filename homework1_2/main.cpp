#include <iostream>
#include "Playlist.h"

int main() {

//    Time time(4,30,56);
//    cout<<time.getSecondFromMidnight();
//    Content content;
//    content.addContent("V");
//    content.saveTo("song.dat");
//
//    Content content1;
//    content1.addContent("Re");
//    content1.saveTo("song2.dat");

//    Song song;
//    song.addToSong("Song1", 0, 1, 55, "rp");


    Playlist p;
    p.add("Song2", 0, 3, 55, "rp","song.dat");
    p.add("Alabama", 0, 3, 46, "h","song1.dat");
    p.add("Zeze", 0, 2, 40, "r","song2.dat");
    p.sortByDuration();
    p.print();


}

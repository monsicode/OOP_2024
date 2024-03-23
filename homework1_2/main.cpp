#include <iostream>
#include "Playlist.h"

int main() {

    Content content;
    content.addContent("V");
    content.saveTo("song.dat");

    Content content1;
    content1.addContent("Ua");
    content1.saveTo("song1.dat");

//    Song song;
//    song.addToSong("Song1", 0, 1, 55, "rp");


    Playlist p;
    p.add("Song2", 0, 1, 55, "rp","song.dat");
    p.add("Song1", 0, 3, 40, "p","song1.dat");

    //p.find("Song2");
    p.mix("Song1", "Song2");
    p.save("Song1", "song3.dat");

    p.add("Song3", 0,2,56,"rpe", "song3.dat");
    //p.find("Song3");
    p.sortByName();
    p.print();
//
//
//    p.read("Song1", "song3.dat");

}

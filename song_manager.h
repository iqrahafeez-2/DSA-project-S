#ifndef SONG_MANAGER_H
#define SONG_MANAGER_H

#include <iostream>
#include <fstream>
#include <string>

class SongManager {
private:
    std::string filename;

public:
    // Constructor to initialize filename
    SongManager(const std::string& file);

    // Method to add a song to the file
    void addSong();

    // Method to view all songs in the file
    void viewSongs();
};

#endif  // SONG_MANAGER_H

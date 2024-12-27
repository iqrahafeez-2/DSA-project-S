#ifndef PLAYLIST_MANAGER_H
#define PLAYLIST_MANAGER_H

#include <string>

// Define the PlaylistNode class (for individual songs in the playlist)
class PlaylistNode {
public:
    std::string song;   // Song title
    PlaylistNode* next; // Pointer to the next song in the list

    PlaylistNode(const std::string& song) : song(song), next(nullptr) {}
};

// Define the Playlist class (for managing the list of songs)
class Playlist {
private:
    PlaylistNode* head; // Head of the list, points to the first song

public:
    Playlist(); // Constructor
    ~Playlist(); // Destructor

    void addSong(const std::string& song); // Add a song
    void removeSong(const std::string& song); // Remove a song
    void display() const; // Display the playlist
};

#endif // PLAYLIST_MANAGER_H

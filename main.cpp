#include "playlist_manager.h"  // Ensure this file defines the Playlist class
#include "stack.h"  // Ensure this defines the Stack template
#include "queue.h"  // Ensure this defines the Queue template
#include <iostream>
#include <fstream>

using namespace std;

// Function to load songs from a file into the playlist
void loadSongsFromFile(const string& fileName, Playlist& playlist) {
    ifstream file(fileName);
    string song;
    while (getline(file, song)) {
        playlist.addSong(song);  // Assuming addSong is a method of Playlist
    }
}

int main() {
    // Instantiate Playlist, Stack, and Queue with correct template parameters
    Playlist playlist;  // Playlist should be defined in playlist_manager.h
    Stack<string> history;  // Stack of strings for playback history
    Queue<string> playbackQueue;  // Queue of strings for playback

    // Load songs into the playlist from a file
    loadSongsFromFile("songs.txt", playlist);

    // Display the loaded playlist
    cout << "Playlist:\n";
    playlist.display();  // Assuming display is a method of Playlist

    // Add songs to playback queue
    cout << "\nAdding to playback queue...\n";
    playbackQueue.enqueue("Song A");
    playbackQueue.enqueue("Song B");
    playbackQueue.enqueue("Song C");

    // Display the playback queue
    cout << "Playback queue:\n";
    playbackQueue.display();  // Assuming display is a method of Queue

    // Play a song from the queue
    cout << "\nPlaying song from queue...\n";
    string currentSong = playbackQueue.dequeue();
    history.push(currentSong);  // Assuming push is a method of Stack
    cout << "Now playing: " << currentSong << endl;

    // Display playback history
    cout << "\nPlayback history:\n";
    history.display();  // Assuming display is a method of Stack

    return 0;
}

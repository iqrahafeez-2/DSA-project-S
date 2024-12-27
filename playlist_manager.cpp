#include "playlist_manager.h"
#include <iostream>
using namespace std;

Playlist::Playlist() : head(nullptr) {}

Playlist::~Playlist() {
    while (head) {
        PlaylistNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void Playlist::addSong(const std::string& song) {
    PlaylistNode* newNode = new PlaylistNode(song); // Create a new node with the song
    newNode->next = head; // Point new node's next to the current head
    head = newNode;  // Update head to the new node
}

void Playlist::removeSong(const std::string& song) {
    PlaylistNode* current = head;
    PlaylistNode* prev = nullptr;

    while (current && current->song != song) {
        prev = current;
        current = current->next;
    }

    if (current) {  // Song found
        if (prev) {
            prev->next = current->next;  // Remove current node from the list
        }
        else {
            head = current->next;  // Update head if the song was the first node
        }
        delete current;  // Delete the node
    }
}

void Playlist::display() const {
    PlaylistNode* current = head;
    while (current) {
        cout << current->song << endl;  // Output song name
        current = current->next;  // Move to the next song in the list
    }
}

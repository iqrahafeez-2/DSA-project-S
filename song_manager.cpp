#include "song_manager.h"
#include <iostream>
#include <fstream>

SongManager::SongManager(const std::string& file) : filename(file) {}

void SongManager::addSong() {
    std::ofstream file(filename, std::ios::app);
    if (!file) {
        std::cerr << "Error opening file.\n";
        return;
    }

    std::string title, artist, filePath;
    std::cin.ignore();
    std::cout << "Enter song title: ";
    std::getline(std::cin, title);
    std::cout << "Enter artist name: ";
    std::getline(std::cin, artist);
    std::cout << "Enter file path: ";
    std::getline(std::cin, filePath);

    file << title << "|" << artist << "|" << filePath << "\n";
    file.close();
    std::cout << "Song added successfully.\n";
}

void SongManager::viewSongs() {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file.\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << "\n";
    }
    file.close();
}

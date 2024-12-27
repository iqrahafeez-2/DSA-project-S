#include "http_server.h"
#include "playlist_manager.h" // Include the correct header

// Define the global instances here
Queue<string> playbackQueue;
Stack<string> history;

void initializeWinsock() {
    // Placeholder for Winsock initialization if required
    cout << "Winsock initialized (Placeholder function)." << endl;
}

void handleLoadPlaylist(HttpRequest& req, HttpResponse& res) {
    Playlist playlist; // Use Playlist class instead of PlaylistManager

    // For demonstration, adding some songs to the playlist
    playlist.addSong("Song 1");
    playlist.addSong("Song 2");
    playlist.addSong("Song 3");

    // Retrieve and format the playlist
    string response = "Playlist: ";
    playlist.display(); // Display playlist on the console for debugging purposes

    // Note: You can customize this logic if you need the playlist in string format
    res.send(response); // Send the response as a string
}

void handleEnqueue(HttpRequest& req, HttpResponse& res) {
    string song = req.getParam("song");  // Retrieve the "song" parameter from the request
    playbackQueue.enqueue(song);

    string response = "Song added to the queue: " + song;
    res.send(response);  // Send the response as a string
}

void handleDequeue(HttpRequest& req, HttpResponse& res) {
    if (playbackQueue.isEmpty()) {
        res.send("Error: Queue is empty");
        return;
    }
    string song = playbackQueue.dequeue();
    history.push(song);

    string response = "Song dequeued: " + song;
    res.send(response);  // Send the response as a string
}

void handleHistory(HttpRequest& req, HttpResponse& res) {
    vector<string> historyList = history.toVector();

    string response = "History: ";
    for (const auto& song : historyList) {
        response += song + " | ";
    }
    res.send(response);  // Send the response as a string
}

void startServer() {
    HttpServer server;

    // Define routes and their corresponding handlers
    server.route("/loadPlaylist", handleLoadPlaylist);
    server.route("/enqueue", handleEnqueue);
    server.route("/dequeue", handleDequeue);
    server.route("/history", handleHistory);

    server.listen(8080, []() {
        cout << "Server running at http://localhost:8080" << endl;
        });
}

/*int main() {
    initializeWinsock();
    startServer();
    return 0;
}*/

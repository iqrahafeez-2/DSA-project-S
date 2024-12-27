#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include <functional>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include "queue.h"  // Assuming these headers exist
#include "stack.h"  // Assuming these headers exist
#include "playlist_manager.h"  // Assuming this header exists

using namespace std;

class HttpRequest {
public:
    string getParam(const string& key) {
        // Placeholder for getting parameters from the request.
        return "";
    }
};

class HttpResponse {
public:
    // Send a plain text response
    void send(const string& message) {
        cout << "Response: " << message << endl;
    }
};

class HttpServer {
public:
    void route(const string& path, function<void(HttpRequest&, HttpResponse&)> handler) {
        // For simplicity, we are not implementing actual routing logic here.
        // In a real scenario, this would set up a handler for each route.
        cout << "Routing path: " << path << endl;
    }

    void listen(int port, function<void()> callback) {
        cout << "Server listening on port " << port << endl;
        callback();
    }
};

// Declare global instances
extern Queue<string> playbackQueue;
extern Stack<string> history;

// Function prototypes
void initializeWinsock();
void handleLoadPlaylist(HttpRequest& req, HttpResponse& res);
void handleEnqueue(HttpRequest& req, HttpResponse& res);
void handleDequeue(HttpRequest& req, HttpResponse& res);
void handleHistory(HttpRequest& req, HttpResponse& res);
void startServer();

#endif // HTTP_SERVER_H

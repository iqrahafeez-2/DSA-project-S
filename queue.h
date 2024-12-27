#ifndef QUEUE_H
#define QUEUE_H

#include <vector>   // Include vector header
#include <string>   // Include string header

using namespace std;

template <typename T>
struct QueueNode {
    T data;
    QueueNode* next;
};

template <typename T>
class Queue {
private:
    QueueNode<T>* front;
    QueueNode<T>* rear;
public:
    Queue();
    ~Queue();
    void enqueue(const T& data);
    T dequeue();
    bool isEmpty() const;
    void display() const;
    vector<T> toVector() const;  // To convert queue to vector
};

#endif

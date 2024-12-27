#include "queue.h"
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
Queue<T>::Queue() : front(nullptr), rear(nullptr) {}

template <typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename T>
void Queue<T>::enqueue(const T& data) {
    QueueNode<T>* newNode = new QueueNode<T>{ data, nullptr };
    if (rear) {
        rear->next = newNode;
    }
    else {
        front = newNode;
    }
    rear = newNode;
}

template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        return T(); // Return default-constructed value
    }
    QueueNode<T>* temp = front;
    T data = front->data;
    front = front->next;
    if (!front) {
        rear = nullptr;
    }
    delete temp;
    return data;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return front == nullptr;
}

template <typename T>
void Queue<T>::display() const {
    QueueNode<T>* current = front;
    while (current) {
        cout << current->data << endl;
        current = current->next;
    }
}

template <typename T>
vector<T> Queue<T>::toVector() const {
    vector<T> result;
    QueueNode<T>* current = front;
    while (current) {
        result.push_back(current->data);
        current = current->next;
    }
    return result;
}

// Explicit template instantiation
template class Queue<string>;

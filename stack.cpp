#include "stack.h"
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
Stack<T>::Stack() : top(nullptr) {}

template <typename T>
Stack<T>::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

template <typename T>
void Stack<T>::push(const T& data) {
    StackNode<T>* newNode = new StackNode<T>{ data, top };
    top = newNode;
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        return T(); // Return default-constructed value
    }
    StackNode<T>* temp = top;
    T data = top->data;
    top = top->next;
    delete temp;
    return data;
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return top == nullptr;
}

template <typename T>
void Stack<T>::display() const {
    StackNode<T>* current = top;
    while (current) {
        cout << current->data << endl;
        current = current->next;
    }
}

template <typename T>
vector<T> Stack<T>::toVector() const {
    vector<T> result;
    StackNode<T>* current = top;
    while (current) {
        result.push_back(current->data);
        current = current->next;
    }
    return result;
}

// Explicit template instantiation
template class Stack<string>;

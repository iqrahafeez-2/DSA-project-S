#ifndef STACK_H
#define STACK_H

#include <vector>   // Include vector header
#include <string>   // Include string header

using namespace std;

template <typename T>
struct StackNode {
    T data;
    StackNode* next;
};

template <typename T>
class Stack {
private:
    StackNode<T>* top;
public:
    Stack();
    ~Stack();
    void push(const T& data);
    T pop();
    bool isEmpty() const;
    void display() const;
    vector<T> toVector() const;  // To convert stack to vector
};

#endif

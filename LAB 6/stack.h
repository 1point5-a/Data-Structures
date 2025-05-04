#ifndef STACKADTSLL_H
#define STACKADTSLL_H

#include <cstdio>
#include <cstdlib>

// Stack class using singly linked list (SLL)
class Stack {
private:
    struct Node {
        char data;
        struct Node* next;
    };
    Node* head;

public:
    Stack(); // Constructor
    int push(char data); // Push function
    char pop(); // Pop function
    char peek(); // Peek function
};

#endif

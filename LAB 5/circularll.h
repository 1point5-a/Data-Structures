#ifndef CLIST_H
#define CLIST_H

#include <cstdlib>
#include <cstdio>

// Node structure for the circular linked list
struct Node {
    int data;
    Node* next;
};

// Circular Linked List class
class List {
private:
    Node* tail;

public:
    List();
    ~List();

    void insertEnd(int data);
    void deleteBegin();
    bool isEmpty();
    void display();
    int front(); // Returns the front element
};

#endif

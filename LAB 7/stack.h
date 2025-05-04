// Stack.h - Stack ADT implemented using an array of characters with inline definitions

#ifndef STACK_H
#define STACK_H

class Stack {
private:
    char arr[100];
    int top;

public:
    // constructor to initialize stack
    Stack() {
        top = -1;
    }

    // function to check if stack is full
    int isFull() {
        return top == 99;
    }

    // function to check if stack is empty
    int isEmpty() {
        return top == -1;
    }

    // function to push an element onto the stack
    int push(char value) {
        if (isFull())
            return 0;

        arr[++top] = value;
        return 1;
    }

    // function to pop an element from the stack
    char pop() {
        if (isEmpty())
            return '\0';

        return arr[top--];
    }

    // function to get the top element without popping
    char peek() {
        if (isEmpty())
            return '\0';

        return arr[top];
    }

    // destructor (optional, no dynamic memory)
    ~Stack() {
        // No dynamic memory to free
    }
};

#endif

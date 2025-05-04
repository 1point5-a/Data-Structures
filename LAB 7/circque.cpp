// Circular Queue ADT implemented using an integer array
#include <cstdio>

class Queue {
private:
    int arr[5];
    int front, rear, size;
public:
    Queue(); // constructor to initialize queue
    int enqueue(int); // function to add an element to the queue
    int dequeue(); // function to remove an element from the queue
    int peek(); // function to get the front element
    int isFull(); // function to check if queue is full
    int isEmpty(); // function to check if queue is empty
};


int main() {
    Queue q;
    int choice, value, result;

    while (1) {
        // ***** (Main Menu) *****
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            // ***** (Performing Enqueue) *****
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                result = q.enqueue(value);
                if (result)
                    printf("Enqueued %d successfully.\n", value);
                else
                    printf("Queue is full. Cannot enqueue %d.\n", value);
                break;

            // ***** (Performing Dequeue) *****
            case 2:
                result = q.dequeue();
                if (result != -1)
                    printf("Dequeued %d successfully.\n", result);
                else
                    printf("Queue is empty. Cannot dequeue.\n");
                break;

            // ***** (Performing Peek) *****
            case 3:
                result = q.peek();
                if (result != -1)
                    printf("Front element is %d.\n", result);
                else
                    printf("Queue is empty. No element to peek.\n");
                break;

            // ***** (Exiting Program) *****
            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
}

// constructor to initialize queue
Queue::Queue() {
    front = -1;
    rear = -1;
    size = 5;
}

// function to check if queue is full
int Queue::isFull() {
    return (rear + 1) % size == front;
}

// function to check if queue is empty
int Queue::isEmpty() {
    return front == -1;
}

// function to add an element to the queue
int Queue::enqueue(int value) {
    if (isFull())
        return 0;

    if (isEmpty())
        front = rear = 0;
    else
        rear = (rear + 1) % size;

    arr[rear] = value;
    return 1;
}

// function to remove an element from the queue
int Queue::dequeue() {
    if (isEmpty())
        return -1;

    int data = arr[front];

    if (front == rear)
        front = rear = -1; // queue becomes empty
    else
        front = (front + 1) % size;

    return data;
}

// function to get the front element
int Queue::peek() {
    if (isEmpty())
        return -1;

    return arr[front];
}

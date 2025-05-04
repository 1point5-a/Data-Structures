//Code to implement queue ADT using an array

#include <iostream>
#include <stdio.h>
using namespace std;
#define SIZE 5

class queue
{
private:
    int front;
    int rear;
    int arr[SIZE];

public:
    queue();
    int enqueue(int);
    int dequeue();
    int peek();
};

// Main Function: implements queue operation in a menu
int main()
{
    printf("***    Queue Operations    ***\n");
    queue q;
    int choice, data, dequeued, peeked, status;

    while (1)
    {
        printf("1 to Enqueue\n");
        printf("2 to Dequeue\n");
        printf("3 to Peek\n");
        printf("4 to Exit\n\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Data To Enqueue: ");
            scanf(" %d", &data);
            status = q.enqueue(data);
            if (status != -1)
                printf("Data enqueued into the queue successfully\n\n");
            else
                printf("Queue Full, unable to enqueue\n\n");
            break;

        case 2:
            dequeued = q.dequeue();
            if (dequeued != -1)
            {
                printf("Data dequeued successfully\n");
                printf("Data dequeued = %d\n\n", dequeued);
            }
            else
                printf("Queue Empty, unable to dequeue data\n\n");
            break;

        case 3:
            peeked = q.peek();
            if (peeked != -1)
            {
                printf("Data peeked from the front successfully\n");
                printf("Data peeked = %d\n\n", peeked);
            }
            else
                printf("Queue Empty, unable to peek data\n\n");
            break;

        case 4:
            printf("Exiting the Program...\n");
            return 0;

        default:
            printf("Enter valid choice...\n\n");
            break;
        }
    }
}

// Enqueue Function: adds data to the rear of the queue
int queue::enqueue(int dt)
{
    if (rear == SIZE - 1)
        return -1; // Queue is full

    if (front == -1)
        front = 0;

    rear++;
    arr[rear] = dt;
    return 0;
}

// Dequeue Function: removes data from the front of the queue
int queue::dequeue()
{
    if (front == -1 || front > rear)
        return -1; // Queue is empty

    int temp = arr[front];
    arr[front] = 0;

    if (front == rear)
        front = rear = -1; // Reset if last element dequeued
    else
        front++;

    return temp;
}

// Peek Function:peeks data from the front of the queue
int queue::peek()
{
    if (front == -1 || front > rear)
        return -1; // Queue empty

    return arr[front];
}

// Constructor to initialize queue
queue::queue()
{
    front = rear = -1;
    for (int i = 0; i < SIZE; i++)
        arr[i] = 0;
}

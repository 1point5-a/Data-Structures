// Queue ADT implemented using an integer-linked list

class Queue {
    private:
        struct Node {
            int data;
            Node* next;
        };
        Node* front;
        Node* rear;
    public:
        Queue(); // constructor to initialize queue
        int enqueue(int); // function to add an element to the queue
        int dequeue(); // function to remove an element from the queue
        int peek(); // function to get the front element
        int isEmpty(); // function to check if queue is empty
        ~Queue(); // destructor to free memory
    };
    
    #include <cstdio>
    #include <cstdlib>
    
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
                        printf("Failed to enqueue %d.\n", value);
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
        front = rear = NULL;
    }
    
    // function to check if queue is empty
    int Queue::isEmpty() {
        return front == NULL;
    }
    
    // function to add an element to the queue
    int Queue::enqueue(int value) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (!newNode)
            return 0; // memory allocation failed
    
        newNode->data = value;
        newNode->next = NULL;
    
        if (isEmpty())
            front = rear = newNode;
        else {
            rear->next = newNode;
            rear = newNode;
        }
    
        return 1;
    }
    
    // function to remove an element from the queue
    int Queue::dequeue() {
        if (isEmpty())
            return -1;
    
        Node* temp = front;
        int data = temp->data;
        front = front->next;
    
        if (front == NULL)
            rear = NULL;
    
        free(temp);
        return data;
    }
    
    // function to get the front element
    int Queue::peek() {
        if (isEmpty())
            return -1;
    
        return front->data;
    }
    
    // destructor to free memory
    Queue::~Queue() {
        while (!isEmpty())
            dequeue();
    }
    
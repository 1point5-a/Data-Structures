#include <cstdio>
#include <cstdlib>

// Circular Linked List Implementation using C-style memory allocation
class List {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* tail; // Points to the last node

public:
    List() { tail = NULL; }

    // Inserts a node at the beginning
    void insertBeginning(int value);

    // Inserts a node at the end
    void insertEnd(int value);

    // Inserts a node at a specific position
    void insertPosition(int value, int pos);

    // Deletes the first node
    void deleteBeginning();

    // Deletes the last node
    void deleteEnd();

    // Deletes a node at a specific position
    void deletePosition(int pos);

    // Searches for a value in the list
    int search(int value);

    // Displays the list
    void display();
};

int main() {
    List list;
    int choice, value, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Beginning\n");
        printf("2. Insert End\n");
        printf("3. Insert Position\n");
        printf("4. Delete Beginning\n");
        printf("5. Delete End\n");
        printf("6. Delete Position\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                list.insertBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                list.insertEnd(value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");

                scanf("%d", &pos);

                list.insertPosition(value, pos);
                break;
            case 4:
                list.deleteBeginning();
                break;
            case 5:
                list.deleteEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                list.deletePosition(pos);
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                pos = list.search(value);
                if (pos == -1)
                    printf("Value not found\n");
                else
                    printf("Value found at position: %d\n", pos);
                break;
            case 8:
                list.display();
                break;
            case 9:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

// Inserts a node at the beginning
void List::insertBeginning(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    if (!tail) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
    }
}

// Inserts a node at the end
void List::insertEnd(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    if (!tail) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

// Inserts a node at a specific position
void List::insertPosition(int value, int pos) {
    if (pos <= 1) {
        insertBeginning(value);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    Node* temp = tail->next;
    for (int i = 0; temp != tail && i < pos - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    if (temp == tail) tail = newNode;
}

// Deletes the first node
void List::deleteBeginning() {
    if (!tail) return;
    Node* temp = tail->next;
    if (tail == tail->next) {
        tail = NULL;
    } else {
        tail->next = temp->next;
    }
    free(temp);
}

// Deletes the last node
void List::deleteEnd() {
    if (!tail) return;
    Node* temp = tail->next;
    if (tail == tail->next) {
        free(tail);
        tail = NULL;
        return;
    }
    while (temp->next != tail) {
        temp = temp->next;
    }
    temp->next = tail->next;
    free(tail);
    tail = temp;
}

// Deletes a node at a specific position
void List::deletePosition(int pos) {
    if (!tail) return;
    if (pos <= 1) {
        deleteBeginning();
        return;
    }
    Node* temp = tail->next;
    Node* prev = NULL;
    for (int i = 0; temp != tail && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == tail) {
        deleteEnd();
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Searches for a value in the list
int List::search(int value) {
    if (!tail) return -1;
    Node* temp = tail->next;
    int pos = 0;
    do {
        if (temp->data == value) return pos;
        temp = temp->next;
        pos++;
    } while (temp != tail->next);
    return -1;
}

// Displays the list
void List::display() {
    if (!tail) {
        printf("List is empty\n");
        return;
    }
    Node* temp = tail->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

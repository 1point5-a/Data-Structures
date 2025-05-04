#include "circularll.h"
#include <cstdio>
#include <cstdlib>

int main() {
    List queue;
    int timeSlice;
    
    printf("Enter fixed time slot: ");
    scanf("%d", &timeSlice);

    int choice;
    while (1) {
        printf("\n1. Insert Process\n2. Execute\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int processTime;
            printf("Enter process execution time: ");
            scanf("%d", &processTime);
            queue.insertEnd(processTime);
        } else if (choice == 2) {
            if (queue.isEmpty()) {
                printf("No processes to execute.\n");
                continue;
            }

            int remainingTime = queue.front();
            queue.deleteBegin();

            remainingTime -= timeSlice;
            if (remainingTime > 0) {
                queue.insertEnd(remainingTime);
                printf("Process executed for %d units, remaining time: %d\n", timeSlice, remainingTime);
            } else {
                printf("Process completed execution.\n");
            }
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}

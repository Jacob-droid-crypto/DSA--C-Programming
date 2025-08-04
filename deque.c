#include <stdio.h>
#define MAX 10

int main() {
    int queue[MAX];
    int front = -1, rear = -1;
    int choice, item;
    int i;

    printf("Menu:\n");
    printf("1: Insert Front\n2: Insert Rear\n3: Delete Front\n4: Delete Rear\n5: Display\n6: Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            
            if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
                printf("Overflow: Deque is full!\n");
            } 
            else {
                printf("Enter element to insert at front: ");
                scanf("%d", &item);
                if (front == -1 && rear == -1) {
                    front = rear = 0;
                    queue[front] = item;
                } else if (front == 0) {
                    front = MAX - 1;
                    queue[front] = item;
                } else {
                    front = front - 1;
                    queue[front] = item;
                }
            }
        }

        if (choice == 2) {

            if ((front == 0 && rear == MAX - 1) || (rear == front - 1)) {
                printf("Overflow: Deque is full!\n");
            } else {
                printf("Enter element to insert at rear: ");
                scanf("%d", &item);
                if (front == -1 && rear == -1) {
                    front = rear = 0;
                    queue[rear] = item;
                } else if (rear == MAX - 1) {
                    rear = 0;
                    queue[rear] = item;
                } else {
                    rear = rear + 1;
                    queue[rear] = item;
                }
            }
        }

        if (choice == 3) {

            if (front == -1) {
                printf("Underflow: Deque is empty!\n");
            } else {
                printf("Deleted element from front: %d\n", queue[front]);
                if (front == rear) {
                    front = rear = -1;
                } else if (front == MAX - 1) {
                    front = 0;
                } else {
                    front = front + 1;
                }
            }
        }

        if (choice == 4) {

            if (front == -1) {
                printf("Underflow: Deque is empty!\n");
            } else {
                printf("Deleted element from rear: %d\n", queue[rear]);
                if (front == rear) {
                    front = rear = -1;
                } else if (rear == 0) {
                    rear = MAX - 1;
                } else {
                    rear = rear - 1;
                }
            }
        }

        if (choice == 5) {

            if (front == -1) {
                printf("Deque is empty!\n");
            } else {
                printf("Deque elements: ");
                i = front;
                while (i != rear) {
                    printf("%d ", queue[i]);
                    i = (i + 1) % MAX;
                }
                printf("%d\n", queue[rear]);
            }
        }

        if (choice == 6) {
            printf("Exiting...\n");
            break;
        }

        if (choice < 1 || choice > 6) {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}


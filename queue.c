#include <stdio.h>

int main() {
    int array[10];
    int i, m;
    int rear = -1, front = -1; 

    printf("Enter the number of elements : ");
    scanf("%d", &m);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &array[i]);
    }

    rear = m - 1; 
    front = 0;     

    if (rear == 9) {
        printf("Overflow: Queue is full, cannot enqueue.\n");
    } else {
        rear = rear + 1;
        int item;
        printf("Enter the item to be added: ");
        scanf("%d", &item);
        array[rear] = item;

        printf("Queue after enqueue:\n");
        for (i = front; i <= rear; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
    return 0;
}


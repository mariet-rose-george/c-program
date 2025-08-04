#include <stdio.h>
#include <stdlib.h>

int *queue;
int front = -1, rear = -1;
int MAX; 

int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue %d\n", value);
    } else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue\n");
        return -1;
    } else {
        int val = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return val;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    printf("Enter the size of the queue: ");
    scanf("%d", &MAX);

    queue = (int *)malloc(MAX * sizeof(int));
    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    do {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1)
                    printf("Dequeued: %d\n", value);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    free(queue);
    return 0;
}


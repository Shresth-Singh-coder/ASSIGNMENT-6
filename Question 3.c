//Implement circular queue using array and perform enquee dequeue and display operation.

#include <stdio.h>

int front = -1, rear = -1;

void display(int size, int queue[]) {
    printf("Queue contents:\n\n");

    if (front == -1 && rear == -1) {
        printf("Queue is empty.\n");
    } else {
        int i = front;
        while (i != rear) {
            printf("  %d", queue[i]);
            i = (i + 1) % size;
        }
        printf("  %d\n", queue[i]);
    }
}

void push(int size, int queue[]) {
    if (front == -1 && rear == -1) {
        front = rear = 0;
        printf("Enter element: ");
        scanf("%d", &queue[rear]);
    }
    else if ((rear + 1) % size == front) {
        printf("Queue is full (overflow).\n");
    }
    else {
        rear = (rear + 1) % size;
        printf("Enter element: ");
        scanf("%d", &queue[rear]);
    }
}

void pop(int size, int queue[]) {
    if (front == -1 && rear == -1) {
        printf("Queue is empty (underflow).\n");
    }
    else if (front == rear) {
        printf("Deleted: %d\n", queue[front]);
        front = rear = -1;
    }
    else {
        printf("Deleted: %d\n", queue[front]);
        front = (front + 1) % size;
    }
}

int main() {
    int size;
    printf("Enter the capacity of circular queue: ");
    scanf("%d", &size);

    int queue[size];
    int run = 1;

    while (run) {
        int choice;
        printf("\nMenu:\n  1. Display\n  2. Enqueue\n  3. Dequeue\n  9. Exit\n\nChoose option: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                display(size, queue);
                break;
            case 2:
                push(size, queue);
                break;
            case 3:
                pop(size, queue);
                break;
            case 9:
                run = 0;
                break;
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}

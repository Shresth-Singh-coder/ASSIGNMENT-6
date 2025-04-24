//Take a scenario of a clinic in which patients are in queue and as the doctor sees a node it become dequeue from the queue. Each node must include waiting list number which must update when dequeue happens.

#include <stdio.h>

int front = -1, rear = -1;

void display(int size, int queue[]) {
    printf("Current queue elements:\n\n");

    if (front == -1 && rear == -1) {
        printf("Queue is empty (underflow).\n");
    } else {
        int i = front;
        while (i % size != rear) {
            printf("  %d", queue[i]);
            i = (i + 1) % size;
        }
        printf("  %d\n", queue[i]);
    }
}

void push(int size, int queue[]) {
    if (front == -1 && rear == -1) {
        front = rear = 0;
        printf("Enter value: ");
        scanf("%d", &queue[rear]);
    }
    else if ((rear + 1) % size == front) {
        printf("Queue is full (overflow).\n");
    }
    else {
        rear = (rear + 1) % size;
        printf("Enter value: ");
        scanf("%d", &queue[rear]);
    }
}

void pop(int size, int queue[]) {
    if (front == -1 && rear == -1) {
        printf("Nothing to delete (underflow).\n");
    }
    else if (front == rear) {
        printf("Removed: %d\n", queue[front]);
        front = rear = -1;
    }
    else {
        printf("Removed: %d\n", queue[front]);
        front = (front + 1) % size;
    }
}

int main() {
    int size;
    printf("Enter queue size: ");
    scanf("%d", &size);

    int queue[size];
    int running = 1;

    while (running) {
        int choice;
        printf("\nChoose an operation:\n");
        printf("  1. Display\n  2. Push\n  3. Pop\n  9. Exit\n\n: ");
        scanf("%d", &choice);
        printf("\n");

        if (choice == 1) {
            display(size, queue);
        }
        else if (choice == 2) {
            push(size, queue);
        }
        else if (choice == 3) {
            pop(size, queue);
        }
        else if (choice == 9) {
            running = 0;
        }
        else {
            printf("Invalid option.\n");
        }
    }

    return 0;
}

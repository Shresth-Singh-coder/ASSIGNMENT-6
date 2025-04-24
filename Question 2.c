//Implement queue using link list and perform enqueue, dequeue and display function.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *temp = NULL, *tail = NULL;

int enqueue() {
    struct node *nnode = (struct node *)malloc(sizeof(struct node));

    if (!nnode) {
        printf("\nUnable to allocate memory for new node.\n");
        return -1;
    }

    printf("\nEnter value: ");
    scanf("%d", &nnode->data);
    nnode->next = NULL;

    if (head == NULL && tail == NULL) {
        head = tail = nnode;
    } else {
        tail->next = nnode;
        tail = nnode;
    }

    return 0;
}

int dequeue() {
    if (head == NULL) {
        printf("\nQueue is empty.\n");
        return -1;
    }

    temp = head;
    head = head->next;
    free(temp);

    if (head == NULL) {
        tail = NULL;
    }

    return 0;
}

int display() {
    if (head == NULL) {
        printf("\nQueue is empty.\n");
        return -1;
    }

    temp = head;
    while (temp != NULL) {
        printf("\nData: %d", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}

int main() {
    int running = 1, choice;

    while (running) {
        printf("\nChoose an operation:\n");
        printf("1. Enqueue\n");
        printf("2. Display\n");
        printf("3. Dequeue\n");
        printf("9. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                display();
                break;
            case 3:
                dequeue();
                break;
            case 9:
                printf("\nProgram terminated.\n");
                running = 0;
                break;
            default:
                printf("\nInvalid selection.\n");
        }
    }

    return 0;
}

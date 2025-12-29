#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

int isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == (rear + 1) % SIZE);
}

int isEmpty() {
    return (front == -1);
}

void enQueue(int element) {
    if (isFull()) {
        printf("\nQueue is full\n");
    } else {
        if (front == -1) 
            front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\nInserted %d\n", element);
    }
}

int deQueue() {
    int element;
    if (isEmpty()) {
        printf("\nQueue is empty\n");
        return -1;
    } else {
        element = items[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        printf("\nDeleted %d\n", element);
        return element;
    }
}

void peek() {
    if (isEmpty()) {
        printf("\nQueue is empty\n");
    } else {
        printf("\nFront element is %d\n", items[front]);
    }
}

void display() {
    if (isEmpty()) {
        printf("\nQueue is empty\n");
    } else {
        int i;
        printf("\nQueue elements: ");
        for (i = front; i != rear; i = (i + 1) % SIZE) {
            printf("%d ", items[i]);
        }
        printf("%d\n", items[i]);
    }
}

int main() {
    int value, choice;
    while (1) {
        printf("\n\n***** MENU *****\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enQueue(value);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("\nWrong selection! Try again.");
        }
    }
    return 0;

}


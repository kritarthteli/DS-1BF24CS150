#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int queue_array[MAX];
int front = -1;
int rear = -1;

void insert() {
    int item;
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter element to insert: ");
    scanf("%d", &item);
    if (front == -1) {
        front = 0;
    }
    rear = rear + 1;
    queue_array[rear] = item;
    printf("%d inserted into queue\n", item);
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow or Queue is empty\n");
        return;
    }
    printf("Element deleted is: %d\n", queue_array[front]);
    front = front + 1;
}

void display() {
    int i;
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue_array[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
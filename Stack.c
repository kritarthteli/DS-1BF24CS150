#include <stdio.h>
#define SIZE 10 

int stack[SIZE];
int top = -1;  

void push(int x) {
    if (top == SIZE - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    top++;
    stack[top] = x;
    printf("%d pushed to stack.\n", x);
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    int val = stack[top];
    top--;
    printf("%d popped from stack.\n", val);
    return val;
}

int peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack[top];
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n---Menu---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");   

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                value = peek();
                if (value != -1)
                    printf("Top element: %d\n", value);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

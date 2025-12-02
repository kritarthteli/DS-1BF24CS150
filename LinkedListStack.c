#include<stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *new_node = NULL;
struct Node *top = NULL;
struct Node *temp = NULL;
struct Node *last = NULL;
struct Node *prev = NULL;
struct Node *next = NULL;
struct Node *curr = NULL;

void Create_Node(int val) {
    new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> data = val;
    new_node -> next = NULL;
    return;
}

void push(int val) {
    Create_Node(val);
    if(top == NULL)
        top = new_node;
    else{
        new_node -> next = top;
        top = new_node;
    }
}

void pop() {
    if(top == NULL)
        printf("Empty list");
    else if(top->next == NULL) {
        int n = top->data;
        free(top);
        top = NULL;
        printf("poped: %d", n);
    }
    else {
        int n = top->data;
        temp = top;
        top = top->next;
        free(temp);
        printf("poped: %d", n);
    }
}

display() {
    temp = top;
    while(temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main() {
    int choice, val, pos;
    printf("-----MENU-----\n");
    printf("1. push\n");
    printf("2. pop\n");
    printf("3. Display\n");
    printf("0. Exit\n");

    do {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1 : {
                printf("Enter value: ");
                scanf("%d", &val);
                printf("\n");
                push(val);
                break;
            }
            case 2 : pop(); printf("\n"); break;

            case 3 : {
                display();
                printf("\n");
                break;
            }
            case 0 : printf("Exiting"); break;

            default : {
                printf("Invalid choice!");
                printf("\n");
                break;
            }

        }
    }while(choice != 0);
}
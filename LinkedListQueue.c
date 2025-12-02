#include<stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *new_node = NULL;
struct Node *front = NULL;
struct Node *temp = NULL;
struct Node *rear = NULL;

void Create_Node(int val) {
    new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> data = val;
    new_node -> next = NULL;
    return;
}

void enque(int val) {
    Create_Node(val);
    if(front == NULL)
        front = new_node;
    else{
        rear = front;
        while(rear -> next != NULL)
            rear = rear -> next;
        rear -> next = new_node;
    }
}

void deque() {
    if(front == NULL)
        printf("Empty list");
    else if(front->next == NULL) {
        int n = front->data;
        free(front);
        front = NULL;
        printf("Dequed: %d", n);
    }
    else {
        int n = front->data;
        temp = front;
        front = front->next;
        free(temp);
        printf("Dequed: %d", n);
    }
}

display() {
    temp = front;
    while(temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main() {
    int choice, val, pos;
    printf("-----MENU-----\n");
    printf("1. Enque\n");
    printf("2. Deque\n");
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
                enque(val);
                break;
            }
            case 2 : deque(); printf("\n"); break;
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

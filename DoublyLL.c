#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL; 
Node *temp = NULL; 

Node *Create_Node(int val) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node -> data = val;
    new_node -> next = NULL;
    new_node -> prev = NULL;
    return (new_node); 
}

void Insert_beg(int val) {
    Node *new_node = Create_Node(val);
    if(head == NULL)
        head = new_node;
    else {
        new_node -> next = head;
        head -> prev = new_node;
        head = new_node;
    }
}

void Delete_val(int val) {
    if(head == NULL)
        printf("Empty LL");
    else if(head->next == NULL) {
        free(head);
        head = NULL;
    }
    else {  
        temp = head;
        while(temp != NULL && temp->data != val) 
            temp = temp -> next;
        if(temp == NULL)
            printf("Invalid value\n");
        else {
            temp -> prev -> next = temp -> next;
            temp -> next -> prev = temp -> prev;
            free(temp);
        }
    }
}

display() {
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main() {
    int choice, val;
    printf("-----MENU-----\n");
    printf("1. Insert at the beginning\n");
    printf("2. Delete value\n");
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
                Insert_beg(val);
                break;
            }
            case 2 : {
                printf("Enter value to delete: ");
                scanf("%d", &val);
                printf("\n");
                Delete_val(val);
                break;
            }
            case 3 : {
                display();
                printf("\n");
                break;
            }
            case 0 : printf("Exiting"); break;
        }
    }while(choice != 0);
}
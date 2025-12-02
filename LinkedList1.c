#include<stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *new_node = NULL;
struct Node *head = NULL;
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

void Insert_beg(int val) {
    Create_Node(val);
    if(head == NULL)
        head = new_node;
    else{
        new_node -> next = head;
        head = new_node;
    }
}

void Insert_end(int val) {
    Create_Node(val);
    if(head == NULL)
        head = new_node;
    else{
        last = head;
        while(last -> next != NULL)
            last = last -> next;
        last -> next = new_node;
    }
}

void Insert_pos(int pos, int val) {
    Create_Node(val);
    if(head == NULL)
        head = new_node;
    else {
        temp = head;
        for(int i=1; i<pos-1; i++) {
            if(temp == NULL){
                printf("Index out of bound\n\n");
                return;
            }
            temp = temp -> next;
        }

        new_node -> next = temp -> next;
        temp -> next = new_node;
    }
}

void Delete_beg() {
    if(head == NULL)
        printf("Empty list");
    else if(head->next == NULL) {
        free(head);
        head = NULL;
    }
    else {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void Delete_end() {
    if(head == NULL)
        printf("Empty list");
    else if(head->next == NULL) {
        free(head);
        head = NULL;
    }
    else {
        temp = head;
        while(temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        free(temp);
        prev->next = NULL;
    }
}

void Delete_pos(int pos) {
    if(head == NULL)
        printf("Empty list");
    else if(head->next == NULL) {
        free(head);
        head = NULL;
    }
    else {
        temp = head;
        for(int i=0; i<pos-1; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
}

void Sort() {
    if(head == NULL)
        return head;

    int temp;
    for(struct Node *i=head; i->next != NULL; i=i->next) {
        for(struct Node *j=i->next; j != NULL; j=j->next) {
            if(i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void Reverse() {
    curr=head;
    while(curr!=NULL)
    {
        
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head = prev;
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
    int choice, val, pos;
    printf("-----MENU-----\n");
    printf("1. Insert at the beginning\n");
    printf("2. Insert at the end\n");
    printf("3. Insert at position\n");
    printf("4. Delete first element\n");
    printf("5. Delete last element\n");
    printf("6. Delete element at position\n");
    printf("7. Sort\n");
    printf("8. Reverse the LL\n");
    printf("9. Display\n");
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
                printf("Enter value: ");
                scanf("%d", &val);
                printf("\n");
                Insert_end(val);
                break;
            }
            case 3 : {
                printf("Enter position, value: ");
                scanf("%d %d", &pos, &val);
                printf("\n");
                Insert_pos(pos, val);
                break;
            }
            case 4 : Delete_beg(); printf("\n"); break;
            case 5 : Delete_end(); printf("\n"); break;
            case 6 : {
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                printf("\n");
                Delete_pos(pos);
                break;
            }
            case 7 : Sort(); printf("Sorted"); break;
            case 8 : Reverse(); printf("Reversed");
            case 9 : {
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

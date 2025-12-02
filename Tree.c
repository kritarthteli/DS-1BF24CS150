#include<stdio.h>
#include<stdlib.h>

typedef struct BST {
    int data;
    struct BST *left;
    struct BST *right;
}Node;

Node *root = NULL;

Node* create(int val) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node -> data = val;
    new_node -> left = new_node -> right = NULL;
    return new_node;
}

Node* insert(Node *root, int val) {
    if(root == NULL) {
        root = create(val);
        return root;
    }

    if(val < root->data)
        root->left = insert(root->left, val);
    else if(val > root->data)
        root->right = insert(root->right, val);
    return root;
}

// In-order Traversal (Left, Root, Right)
void inorder(Node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Pre-order Traversal (Root, Left, Right)
void preorder(Node *root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order Traversal (Left, Right, Root)
void postorder(Node *root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    int choice, value;

    printf("\n--- Binary Search Tree Menu ---\n");
    printf("1. Insert\n");
    printf("2. In-order Traversal\n");
    printf("3. Pre-order Traversal\n");
    printf("4. Post-order Traversal\n");
    printf("0. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                printf("Enter value: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            }
            case 2: inorder(root); printf("\n"); break;
            case 3: preorder(root); printf("\n"); break;
            case 4: postorder(root); printf("\n"); break;
            case 0: printf("Exited"); printf("\n"); return 0;
            default: printf("Invalid choice"); printf("\n"); break;
        }
    }while(choice != 0);
    return 0;
}

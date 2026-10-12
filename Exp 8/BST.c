#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Search for a value
struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value)
        return root;

    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

// Find minimum node
struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL)
        return NULL;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        // No left child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        // No right child
        if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Main function
int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n\n--- BST MENU ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Inorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                if (search(root, value))
                    printf("Value found\n");
                else
                    printf("Value not found\n");
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Value deleted (if it existed).\n");
                break;

            case 4:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Structure for a tree node
struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

// Stack of pointers to tree nodes
struct Node *stack[MAX];
int top = -1;

// Push a node pointer into stack
void push(struct Node *node)
{
    stack[++top] = node;
}

// Pop a node pointer from stack
struct Node *pop()
{
    return stack[top--];
}

// Create a new tree node
struct Node *createNode(char data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Check whether the symbol is an operator
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Construct expression tree from postfix expression
struct Node *constructTree(char postfix[])
{
    int i;
    char ch;
    struct Node *node;
    struct Node *left;
    struct Node *right;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];

        // If operand
        if (isalnum(ch))
        {
            node = createNode(ch);
            push(node);
        }
        // If operator
        else if (isOperator(ch))
        {
            // First popped node becomes RIGHT child
            right = pop();
            // Second popped node becomes LEFT child
            left = pop();

            // Create operator node
            node = createNode(ch);
            node->left = left;
            node->right = right;

            // Push the newly created subtree back onto stack
            push(node);
        }
    }

    // Final node in stack is the root of the expression tree
    return pop();
}

// Inorder traversal (Left, Root, Right)
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
}

// Preorder traversal (Root, Left, Right)
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal (Left, Right, Root)
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

// Main function
int main()
{
    char postfix[MAX];
    struct Node *root;

    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    root = constructTree(postfix);

    printf("\nExpression Tree Traversals:\n");

    printf("Inorder   : ");
    inorder(root);
    printf("\n");

    printf("Preorder  : ");
    preorder(root);
    printf("\n");

    printf("Postorder : ");
    postorder(root);
    printf("\n");

    return 0;
}
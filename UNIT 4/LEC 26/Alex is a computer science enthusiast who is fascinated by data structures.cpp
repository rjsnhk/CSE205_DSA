#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* root = NULL;

struct Node* createNode(int input)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = input;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary search tree
struct Node* insert(struct Node* node, int input)
{
    // If the tree is empty, return a new node
    if (node == NULL)
        return createNode(input);

    // Otherwise, recur down the tree
    if (input < node->data)
        node->left = insert(node->left, input);
    else if (input > node->data)
        node->right = insert(node->right, input);

    return node;
}

// Function to perform preorder traversal
void preorder(struct Node* temp)
{
    if (temp != NULL)
    {
        printf("%d ", temp->data); // Print the current node's data
        preorder(temp->left);      // Recur on the left subtree
        preorder(temp->right);     // Recur on the right subtree
    }
}

int main()
{
    int input;
    while (1)
    {
        scanf("%d", &input);
        if (input < 1)
            break;
        root = insert(root, input); // Insert the input value into the BST
    }
    preorder(root); // Perform preorder traversal starting from the root
    return 0;
}


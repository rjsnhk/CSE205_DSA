#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left child
   and a pointer to the right child */
struct node {
    int data;
    struct node* left;
    struct node* right;
};

/* Helper function to check if a binary tree is a BST */
int isBSTUtil(struct node* node, int min, int max) {
    // Base case: An empty tree is a BST.
    if (node == NULL)
        return 1;

    // Check if the current node's data is within the valid range (min, max).
    if (node->data < min || node->data > max)
        return 0;

    // Recursively check the left and right subtrees, narrowing the valid range.
    return isBSTUtil(node->left, min, node->data - 1) &&
           isBSTUtil(node->right, node->data + 1, max);
}

/* Function to check if the given tree is a binary search tree */
int isBST(struct node* root) {
    // Use the helper function with the initial valid range of INT_MIN and INT_MAX.
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data) {
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

/* Function to build a binary tree from user input */
struct node* buildTree() {
    int data;
    struct node* root = NULL;

    scanf("%d", &data);

    if (data == -1)
        return NULL;

    root = newNode(data);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

int main() {
    struct node* root = buildTree();

    if (isBST(root))
        printf("The given binary tree is a BST\n");
    else
        printf("The given binary tree is not a BST\n");

    return 0;
}


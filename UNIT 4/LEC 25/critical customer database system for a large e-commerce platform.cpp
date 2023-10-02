#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new binary tree node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to build a binary tree
struct Node *buildBinaryTree() {
    int data;
    scanf("%d", &data);

    if (data == -1) {
        return NULL;  // Return NULL for an empty node
    }

    struct Node *root = createNode(data);

    root->left = buildBinaryTree();
    root->right = buildBinaryTree();

    return root;
}

// Helper function to check if a binary tree has duplicate values
bool hasDuplicateValuesUtil(struct Node *root, int *visited, int *found) {
    if (root == NULL) {
        return false;
    }

    // If the customer ID has been visited before, it's a duplicate
    if (visited[root->data]) {
        *found = 1;
        return true;
    }

    // Mark the customer ID as visited
    visited[root->data] = 1;

    // Recursively check the left and right subtrees
    bool leftDup = hasDuplicateValuesUtil(root->left, visited, found);
    bool rightDup = hasDuplicateValuesUtil(root->right, visited, found);

    return leftDup || rightDup;
}

// Function to check if a binary tree has duplicate values
bool hasDuplicateValues(struct Node *root) {
    int visited[101] = {0}; // Assuming customer IDs are in the range [1, 100]
    int found = 0; // Flag to indicate if a duplicate is found

    hasDuplicateValuesUtil(root, visited, &found);

    return found == 1;
}

int main() {
    struct Node *root = NULL;

    root = buildBinaryTree();

    if (hasDuplicateValues(root)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}


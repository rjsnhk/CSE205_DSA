#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the BST
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node with the given data
struct TreeNode* newNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to find the height of a BST
int height(struct TreeNode* root) {
    if (root == NULL) {
        return -1; // Height of an empty tree is -1
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        // Return the maximum of the left and right subtree heights plus 1 for the current node
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
}

int main() {
    struct TreeNode* root = NULL;
    int numNodes, nodeData;

    scanf("%d", &numNodes);

    // Insert nodes into the BST
    for (int i = 0; i < numNodes; i++) {
        scanf("%d", &nodeData);
        root = insert(root, nodeData);
    }

    // Calculate the height of the BST
    int treeHeight = height(root);

    printf("%d", treeHeight+1);

    return 0;
}


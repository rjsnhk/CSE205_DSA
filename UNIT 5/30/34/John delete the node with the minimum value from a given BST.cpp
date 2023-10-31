#include <iostream>

// Define a structure for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to insert a new key into a BST
TreeNode* insert(TreeNode* root, int key) {
    if (root == NULL) return new TreeNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

// Function to delete the node with the minimum value in the BST
TreeNode* deleteMinNode(TreeNode* root) {
    if (root == NULL) return NULL;
    
    if (root->left == NULL) {
        // If the left child is NULL, it's the minimum node, so remove it
        TreeNode* temp = root->right;
        delete root;
        return temp;
    }
    
    root->left = deleteMinNode(root->left);
    return root;
}

// Function to print the values of the BST nodes
void printValues(TreeNode* root) {
    if (root != NULL) {
        printValues(root->left);
        std::cout << root->data << " ";
        printValues(root->right);
    }
}

int main() {
    int N;
    std::cin >> N;

    TreeNode* root = NULL;
    
    for (int i = 0; i < N; i++) {
        int key;
        std::cin >> key;
        root = insert(root, key);
    }

    root = deleteMinNode(root);
    
    if (root == NULL) {
        std::cout << "(Empty tree)" << std::endl;
    } else {
        printValues(root);
        std::cout << std::endl;
    }

    return 0;
}


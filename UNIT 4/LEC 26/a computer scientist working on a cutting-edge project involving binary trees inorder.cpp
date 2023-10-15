#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = new Node;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// Function to find the nth inorder node
void NthInorder(struct Node* node, int& n, int& result) {
    if (node == nullptr || n <= 0) {
        return;
    }

    // Recur on the left subtree
    NthInorder(node->left, n, result);

    // Increment the count and check if it reaches n
    n--;
    if (n == 0) {
        result = node->data; // Found the nth node
        return;
    }

    // Recur on the right subtree
    NthInorder(node->right, n, result);
}

int main() {
    struct Node* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->right->right = newNode(50);

    int n;
    cin >> n;

    int result = -1; // Initialize result to a sentinel value
    NthInorder(root, n, result);

    if (result != -1) {
        cout << result << endl;
    } else {
        cout << "Node not found." << endl;
    }

    return 0;
}


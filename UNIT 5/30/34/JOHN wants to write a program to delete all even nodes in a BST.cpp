#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int value) {
    if (root == NULL) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

Node* deleteEvenNodes(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    root->left = deleteEvenNodes(root->left);
    root->right = deleteEvenNodes(root->right);
    if (root->data % 2 == 0) {
        // If the node's data is even, delete it and return its child (if any).
        Node* temp = root;
        if (root->left == NULL) {
            root = root->right;
        } else if (root->right == NULL) {
            root = root->left;
        } else {
            // Node has both children, so find the in-order successor.
            Node* minRight = root->right;
            while (minRight->left != NULL) {
                minRight = minRight->left;
            }
            root->data = minRight->data;
            root->right = deleteEvenNodes(root->right);
        }
        delete temp;
    }
    return root;
}

void printBST(Node* root) {
    if (root != NULL) {
        printBST(root->left);
        cout << root->data << " ";
        printBST(root->right);
    }
}

int main() {
    int n;
    cin >> n;
    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        root = insert(root, data);
    }

    root = deleteEvenNodes(root);
    printBST(root);

    return 0;
}


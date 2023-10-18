#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new BST node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a node into the BST
void insert(Node*& root, int data) {
    if (root == nullptr) {
        root = createNode(data);
        return;
    }
    if (data < root->data)
        insert(root->left, data);
    else
        insert(root->right, data);
}

// Morris Traversal to find the Kth smallest element
int KSmallestUsingMorris(Node* root, int k) {
    int count = 0;
    int kthSmallest = -1;
    Node* current = root;

    while (current != nullptr) {
        if (current->left == nullptr) {
            count++;
            if (count == k)
                kthSmallest = current->data;
            current = current->right;
        } else {
            Node* predecessor = current->left;
            while (predecessor->right != nullptr && predecessor->right != current)
                predecessor = predecessor->right;

            if (predecessor->right == nullptr) {
                predecessor->right = current;
                current = current->left;
            } else {
                predecessor->right = nullptr;
                count++;
                if (count == k)
                    kthSmallest = current->data;
                current = current->right;
            }
        }
    }

    return kthSmallest;
}

int main() {
    Node* root = nullptr;
    int data, k;
    do {
        cin >> data;
        if (data > 0)
            insert(root, data);
    } while (data > 0);
    cin >> k;

    int kthSmallest = KSmallestUsingMorris(root, k);
    cout << "Smallest kth value " << kthSmallest << endl;
    
    return 0;
}


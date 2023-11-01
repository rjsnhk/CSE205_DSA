#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void reverseInOrderTraversal(Node* root, int K, int& count, int& result) {
    if (root == nullptr || count >= K) {
        return;
    }

    // Traverse the right subtree first
    reverseInOrderTraversal(root->right, K, count, result);

    // Increment the count
    count++;

    // If the Kth largest element is found, update the result
    if (count == K) {
        result = root->data;
        return;
    }

    // Traverse the left subtree
    reverseInOrderTraversal(root->left, K, count, result);
}

int main() {
    Node* root = nullptr;
    int n, K, count = 0, result;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        if (root == nullptr) {
            root = createNode(data);
        } else {
            Node* current = root;
            while (true) {
                if (data <= current->data) {
                    if (current->left == nullptr) {
                        current->left = createNode(data);
                        break;
                    }
                    current = current->left;
                } else {
                    if (current->right == nullptr) {
                        current->right = createNode(data);
                        break;
                    }
                    current = current->right;
                }
            }
        }
    }

    cin >> K;

    reverseInOrderTraversal(root, K, count, result);

    if (count < K) {
        cout << "Doesn't exist.";
    } else {
        cout << result;
    }

    return 0;
}


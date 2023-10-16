#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node{val, nullptr, nullptr};
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void post_order_traversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    post_order_traversal(root->left);
    post_order_traversal(root->right);
    cout << root->val << " ";
}

int main() {
    Node* root = nullptr;
    int val;
    while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }
        root = insert(root, val);
    }
    cout << "Post order Traversal:" << endl;
    post_order_traversal(root);
    cout << endl;
    return 0;
}

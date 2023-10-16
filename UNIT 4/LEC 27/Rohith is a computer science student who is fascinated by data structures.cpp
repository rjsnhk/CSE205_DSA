#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    } else {
        Node* cur;
        if (data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
        } else {
            cur = insert(root->right, data);
            root->right = cur;
        }
        return root;
    }
}

void postOrder(Node* root)
{
    if (root == nullptr)
        return;

    // Traverse the left subtree
    postOrder(root->left);

    // Traverse the right subtree
    postOrder(root->right);

    // Print the current node's data
    cout << root->data << " ";
}

int getHeight(Node* root) 
{
    if (root == nullptr)
        return -1; // Height of an empty tree is -1

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    // Return the maximum height between left and right subtrees, plus 1 for the current node
    return max(leftHeight, rightHeight) + 1;
}

int main() {
    Node* root = nullptr;

    int n;
    int data;

    cin >> n;

    while (n-- > 0) {
        cin >> data;
        root = insert(root, data);
    }

    cout << "Post-order traversal: ";
    postOrder(root);
    cout << "\nHeight of the tree: " << getHeight(root) << endl;

    return 0;
}


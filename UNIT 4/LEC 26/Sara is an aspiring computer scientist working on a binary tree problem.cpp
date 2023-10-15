#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build the tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    
    return root;
}

// Function to check if the trees are identical
int isIdentical(struct Node* root1, struct Node* root2) {
    // If both trees are empty, they are identical
    if (root1 == NULL && root2 == NULL) {
        return 1;
    }
    
    // If one tree is empty and the other is not, they are not identical
    if (root1 == NULL || root2 == NULL) {
        return 0;
    }
    
    // Check if the current nodes have the same value
    if (root1->data != root2->data) {
        return 0;
    }
    
    // Recursively check left and right subtrees
    int leftIdentical = isIdentical(root1->left, root2->left);
    int rightIdentical = isIdentical(root1->right, root2->right);
    
    // Return true if both subtrees are identical
    return leftIdentical && rightIdentical;
}

int main() {
    struct Node* root1 = NULL;
    struct Node* root2 = NULL;
    int n1, n2, data;

    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &data);
        root1 = insertNode(root1, data);
    }

    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &data);
        root2 = insertNode(root2, data);
    }

    if (isIdentical(root1, root2)) {
        printf("The two binary trees are identical.\n");
    } else {
        printf("The two binary trees are not identical.\n");
    }

    return 0;
}


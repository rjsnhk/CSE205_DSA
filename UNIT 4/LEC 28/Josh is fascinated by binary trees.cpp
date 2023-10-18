#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

void preOrder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

int main() {
    struct node* root = NULL;

    int t;
    int data;

    scanf("%d", &t);

    while (t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    preOrder(root);
    printf("\n");
    
    return 0;
}


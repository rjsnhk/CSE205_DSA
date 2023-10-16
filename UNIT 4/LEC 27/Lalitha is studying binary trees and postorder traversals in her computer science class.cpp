#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int ans[MAX_NODES];
int idx = 0;

struct TreeNode* createNode(int x) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void postorder(struct TreeNode* root)
{
    if (root == NULL)
        return;

    // Traverse the left subtree
    postorder(root->left);

    // Traverse the right subtree
    postorder(root->right);

    // Store the current node's value in the ans array
    ans[idx++] = root->val;
}

int* postorderTraversal(struct TreeNode* root) 
{
    // Initialize the idx variable to 0
    idx = 0;

    // Perform a post-order traversal to fill the ans array
    postorder(root);

    return ans;
}

struct TreeNode* createTree(int arr[], int i, int n)
{
    if (i >= n || arr[i] == -1) {
        return NULL;
    }

    // Create a new node with the current element from the array
    struct TreeNode* root = createNode(arr[i]);

    // Recursively create the left and right subtrees
    root->left = createTree(arr, 2 * i + 1, n);
    root->right = createTree(arr, 2 * i + 2, n);

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX_NODES];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = createTree(arr, 0, n);

    int* postorderResult = postorderTraversal(root);

    for (int i = 0; i < n; ++i) {
        printf("%d ", postorderResult[i]);
    }

    return 0;
}


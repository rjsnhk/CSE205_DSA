#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* root = NULL;
struct Node* temp;

struct Node* createNode(int input)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = input;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build the binary search tree
void create(int input)
{
    struct Node* newNode = createNode(input);
    if (root == NULL)
    {
        root = newNode;
        return;
    }
    
    struct Node* current = root;
    while (1)
    {
        if (input <= current->data)
        {
            if (current->left == NULL)
            {
                current->left = newNode;
                return;
            }
            else
            {
                current = current->left;
            }
        }
        else
        {
            if (current->right == NULL)
            {
                current->right = newNode;
                return;
            }
            else
            {
                current = current->right;
            }
        }
    }
}

// Function to perform the in-order traversal
void inorder(struct Node* temp)
{
    if (temp == NULL)
        return;
    inorder(temp->left);
    printf("%d ", temp->data);
    inorder(temp->right);
}

int main()
{
    int input;
    while (1)
    {
        scanf("%d", &input);
        if (input < 1)
            break;
        create(input);
    }
    inorder(root);
    return 0;
}



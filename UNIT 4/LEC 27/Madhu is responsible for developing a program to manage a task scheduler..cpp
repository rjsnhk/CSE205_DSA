#include<iostream>
using namespace std;

struct node
{
  int data;
  struct node* left;
  struct node* right;
};

struct node* root = NULL;

void append(struct node* &root, int d)
{
  if (root == NULL)
  {
    root = new node;
    root->data = d;
    root->left = NULL;
    root->right = NULL;
  }
  else if (d < root->data)
  {
    append(root->left, d);
  }
  else
  {
    append(root->right, d);
  }
}

void postorder(struct node* root)
{
  if (root == NULL)
    return;

  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}

int main()
{
  int d;
  do
  {
    cin >> d;
    if (d > 0)
      append(root, d);
  } while (d != -1);

  cout << "Post order Traversal:" << endl;
  postorder(root);

  return 0;
}


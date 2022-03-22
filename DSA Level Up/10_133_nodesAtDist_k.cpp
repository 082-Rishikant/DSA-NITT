#include <iostream>
#include <climits>
using namespace std;

class node
{
public:
  int data;
  node *left;
  node *right;
  node(int n)
  {
    data = n;
    left = NULL;
    right = NULL;
  }
};

void print(node *root)
{ // PreOrder Traversal Printing
  if (root == NULL)
    return;
  cout << root->data << " ";
  print(root->left);
  print(root->right);
  return;
}

void atDistanceK(node* root, int k)
{
  if(root==NULL)
    return;
  if(k==0)
  {
    cout<<root->data<<" ";
    return;
  }
  atDistanceK(root->left, k-1);
  atDistanceK(root->right, k-1);
  return;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  node *root = NULL;
  root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->left->right->left = new node(7);
  root->right->right = new node(6);

  print(root);  cout << endl; 

  int k=3;
  atDistanceK(root, k);
  return 0;
}
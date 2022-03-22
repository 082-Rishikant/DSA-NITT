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

int myMaxSumSubTree(node *root, int select)
{
  if (root == NULL)
    return 0;
  int incl = INT_MIN;
  if (select == 0)
  {
    incl = root->data + myMaxSumSubTree(root->left, 1) + myMaxSumSubTree(root->right, 1);
    int excl = max(myMaxSumSubTree(root->left, 1), myMaxSumSubTree(root->left, 0)) + max(myMaxSumSubTree(root->right, 1), myMaxSumSubTree(root->right, 0));
    return max(incl, excl);
  }
  else
  {
    return myMaxSumSubTree(root->left, 0) + myMaxSumSubTree(root->right, 0);
  }
}

class Pair
{
public:
  int incl;
  int excl;
};

Pair prateekMaxSumSubTree(node *root)
{
  Pair p;
  if (root == NULL)
  {
    p.incl = 0;
    p.excl = 0;
    return p;
  }
  Pair leftSum = prateekMaxSumSubTree(root->left);
  Pair rightSum = prateekMaxSumSubTree(root->right);
  p.incl = root->data + leftSum.excl + rightSum.excl;
  p.excl = max(leftSum.incl, leftSum.excl) + max(rightSum.incl, rightSum.excl);
  return p;
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

  print(root);
  cout << endl;

  cout << myMaxSumSubTree(root, 0) << endl;
  Pair p = prateekMaxSumSubTree(root);
  cout << max(p.incl, p.excl);
  return 0;
}
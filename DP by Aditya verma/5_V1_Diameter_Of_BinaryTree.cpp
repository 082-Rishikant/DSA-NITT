#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>

const int N = 1e9 + 7;
using namespace std;

struct Node
{
public:
  int data;
  Node *left;
  Node *right;
};

int res = 0;
int solve(Node *root)
{
  if (root == NULL)
    return 0;
  if (root->left == NULL && root->right == NULL)
    return 1;

  int l = solve(root->left);
  int r = solve(root->right);

  if (root->left != NULL && root->right != NULL)
  {
    res = max(res, l + r + 1);
    return max(l, r) + 1;
  }
  if (root->left == NULL)
    return r + 1;
  if (root->right == NULL)
    return l + 1;
}
// Function to return the diameter of a Binary Tree.
int diameter(Node *root)
{
  // Your code here
  int h = solve(root);
  if (root->left == NULL || root->right == NULL)
  {
    return max(h, res);
  }
  return res;
}

int main()
{
  Node *root = NULL;
  cout << diameter(root); // Here make a Binary Tree And then run this Programm I did not create any binary tree beacase I just save the code here
  return 0;
}
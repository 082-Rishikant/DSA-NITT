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

struct Node{
  public:
  int data;
  Node* left;
  Node* right;
};

int result = INT_MIN;

int solve(Node *root)
{
  if (root == NULL)
    return 0;
  if (root->left == NULL && root->right == NULL)
    return (root->data);

  int left = solve(root->left);
  int right = solve(root->right);

  if (root->left && root->right)
  {
    result = max(result, left + right + root->data);
    return max(left, right) + root->data;
  }
  if (left == 0)
    return (right + root->data);
  if (right == 0)
    return (left + root->data);
}

int maxPathSum(Node *root)
{
  int ans = solve(root);
  if (root->left == NULL || root->right == NULL)
    return max(ans, result);
  return result;
}

int main()
{
  Node* root=NULL; // Here make a Binary Tree And then run this Programm I did not create any binary tree beacase I just save the code here 
  cout << maxPathSum(root);
  return 0;
}
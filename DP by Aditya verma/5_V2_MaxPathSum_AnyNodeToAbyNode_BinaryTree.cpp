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
  // Base condtition
  if (root == NULL)
    return 0;

  // Hypothesis
  int left = solve(root->left);
  int right = solve(root->right);

  // Induction
  int temp = max(max(left, right) + root->data, root->data);
  int ans = max(temp, left + right + root->data);
  result = max(result, ans);
  return temp;
}

//Function to return maximum path sum from any node in a tree.
int findMaxSum(Node *root)
{
  solve(root);
  return result;
}

int main()
{
  Node *root = NULL;
  cout<<findMaxSum(root);// Here make a Binary Tree And then run this Programm I did not create any binary tree beacase I just save the code here 
  return 0;
}
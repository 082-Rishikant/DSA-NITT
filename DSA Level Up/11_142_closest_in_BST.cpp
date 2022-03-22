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

node *insertBST(node *root, int d)
{
  if (root == NULL)
  {
    return new node(d);
  }
  else if (root->data > d)
  {
    root->left = insertBST(root->left, d);
  }
  else
  {
    root->right = insertBST(root->right, d);
  }
  return root;
}

void closestOneRecusive(node *root, int t, int diff, int &ans)
{
  if (root == NULL)
    return;

  if (diff > abs(root->data - t))
  {
    ans = root->data;
    diff = abs(root->data - t);
  }
  if (t > root->data)
    closestOneRecusive(root->right, t, diff, ans);
  else
    closestOneRecusive(root->left, t, diff, ans);

  return;
}

int closestOneIterative(node *root, int t, int diff, int &ans)
{
  while (root != NULL)
  {
    if (diff > abs(root->data - t))
    {
      ans = root->data;
      diff = abs(root->data - t);
    }
    if (t > root->data)
      root=root->right;
    else
      root=root->left;
  }
  return ans;
}

int main()
{
  int arr[] = {5, 1, 8, 13, 7, 2, 99, 45, 212, 5};
  node *root = NULL;
  for (auto it : arr)
  {
    root = insertBST(root, it);
  }

  int target = 100;
  int diff = INT_MAX;
  int ans;

  // ======Optimized Recursive Approach with space Complexity O(h)======
  closestOneRecusive(root, target, diff, ans);
  cout<<ans;

  // ======Optimized Iterative Approach space Complexity O(1)======
  closestOneIterative(root, target, diff, ans);
  cout << ans;
  return 0;
}
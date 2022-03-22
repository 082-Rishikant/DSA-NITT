#include <bits/stdc++.h>
using namespace std;

class node
{
public:
  node *zero = NULL;
  node *one = NULL;
};

class Trie
{
  node *root;

public:
  Trie()
  {
    root = new node();
  }

  void insert(int n)
  {
    node *temp = root;
    for (int i = 31; i >= 0; i--)
    {
      int bit = 1 << i & n;
      if (bit == 0)
      {
        if (temp->zero == NULL)
        {
          temp->zero = new node();
        }
        temp = temp->zero;
      }
      else
      {
        if (temp->one == NULL)
        {
          temp->one = new node();
        }
        temp = temp->one;
      }
    }
  }

  int findMaxXOR(int n)
  {
    node *temp = root;
    int ans = 0;
    int i = 31;
    while (temp != NULL && i >= 0)
    {
      int bit = n & (1 << i);
      if (bit == 0)
      {
        if (temp->one != NULL)
        {
          ans = ans + (1 << i);
          temp = temp->one;
        }
        else
          temp = temp->zero;
      }
      else
      {
        if (temp->zero != NULL)
        {
          ans = ans + (1 << i);
          temp = temp->zero;
        }
        else
          temp = temp->one;
      }
      i--;
    }
    return ans;
  }
};

int main()
{
  vector<int> arr = {5, 7, 2, 3, 5, 25};
  Trie t;
  int maxi = 0;
  for (auto it : arr)
  {
    t.insert(it);
    int curr = t.findMaxXOR(it);
    maxi = max(maxi, curr);
  }
  cout << maxi;
  return 0;
}
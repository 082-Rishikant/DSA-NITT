#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
using namespace std;

class node
{
public:
  int data;
  int counter;
  node *left;
  node *right;
  node(int n)
  {
    data = n;
    counter = -1;
    left = NULL;
    right = NULL;
  }
};

map<int, vector<pair<int, int>>> mp;

void verticalPrint(node* root, int vOrder, int level)
{
  if(root==NULL)
    return;
  mp[vOrder].push_back({level, root->data});
  verticalPrint(root->left, vOrder-1, level+1);
  verticalPrint(root->right, vOrder+1, level+1);
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
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->left->right->left = new node(7);
  root->left->right->right = new node(8);
  root->left->right->right->left = new node(9);
  root->left->right->right->right = new node(10);
  root->right = new node(3);
  root->right->right = new node(6);

  verticalPrint(root, 0, 0);
  
  for(auto it:mp){
    sort(it.second.begin(), it.second.end());
    for(auto item:it.second){
      cout<<item.second<<" ";
    }cout<<endl;
  }
  return 0;
}
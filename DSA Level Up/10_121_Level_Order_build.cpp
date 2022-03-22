#include<iostream>
#include<queue>
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
queue<node*> q;

void print(node* root)
{// PreOrder Traversal Printing
  if(root==NULL)
    return;
  cout<<root->data<<" ";
  print(root->left);
  print(root->right);
  return;
}

node* levelOrderBuild()
{
  int temp; cin>>temp;
  node* root=new node(temp);
  q.push(root);

  while (!q.empty())
  {
    node* curr=q.front(); q.pop();
    cin>>temp;
    if(temp!=-1){
      curr->left=new node(temp);
      q.push(curr->left);
    }
    cin>>temp;
    if(temp!=-1){
      curr->right=new node(temp);
      q.push(curr->right);
    }
  }
  return root;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  node* root=levelOrderBuild();
  print(root);
  return 0;
}
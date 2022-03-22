#include <iostream>
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

node *buildTree()
{
  int temp;
  cin >> temp;
  if (temp == -1)
    return NULL;
  node *root = new node(temp);
  root->left = buildTree();
  root->right = buildTree();
  return root;
}

void print(node *root)
{ // PreOrder Traversal Printing
  if (root == NULL)
    return;
  cout << root->data << " ";
  print(root->left);
  print(root->right);
  return;
}

void levelOrder_Or_BFS(node* root, queue<node*> q)
{
  if(root==NULL)
    return;
  q.push(root);
  q.push(NULL);
  while(!q.empty()){
    if(q.front()==NULL){
      q.pop();
      if(q.empty())
        continue;
      cout<<"\n";
      q.push(NULL);
    }
    node* temp=q.front();
    q.pop();
    cout<<temp->data<<" ";
    if(temp->left)
      q.push(temp->left);
    if(temp->right) 
      q.push(temp->right);
  }
  return;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  node* root=buildTree();
  queue<node*> q;
  levelOrder_Or_BFS(root, q);
  return 0;
}
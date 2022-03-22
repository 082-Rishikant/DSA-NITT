#include<iostream>
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

node* buildTree(){
  int temp; cin>>temp;
  if(temp==-1)
    return NULL;
  node* root=new node(temp);
  root->left=buildTree();
  root->right=buildTree();
  return root;
} 

int Diameter(node* root, int &maxD){
  if(root==NULL)
    return 0;
  int left=Diameter(root->left, maxD);
  int right=Diameter(root->right, maxD);
  maxD=max(left+right+1, maxD);
  return max(left, right)+1;
}

void print(node* root)
{// PreOrder Traversal Printing
  if(root==NULL)
    return;
  cout<<root->data<<" ";
  print(root->left);
  print(root->right);
  return;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  node* root=NULL;
  root=buildTree();
  print(root);  cout<<endl;
  int maxD=0;
  Diameter(root, maxD);
  cout<<maxD;
  return 0;
}
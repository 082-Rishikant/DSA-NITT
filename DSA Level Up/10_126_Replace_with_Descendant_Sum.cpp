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

void print(node* root)
{// PreOrder Traversal Printing
  if(root==NULL)
    return;
  cout<<root->data<<" ";
  print(root->left);
  print(root->right);
  return;
}

int replaceSum(node* root){
  if(root==NULL){
    return 0;
  }
  int left=replaceSum(root->left);
  int right=replaceSum(root->right);
  int sum=root->data;
  if(left!=0 || right!=0)
    root->data=left+right;
  return sum+left+right;
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

  int sum=0;
  replaceSum(root);
  print(root);
  return 0;
}
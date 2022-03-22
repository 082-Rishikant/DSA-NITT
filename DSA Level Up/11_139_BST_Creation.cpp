#include<iostream>
using namespace std;

class node{
  public:
    int data;
    node* left;
    node* right;
    node(int n)
    {
      data=n;
      left=NULL;
      right=NULL;
    }
};

node* insertBST(node* root, int d)
{
  if(root==NULL){
    return new node(d);
  }else if(root->data>d)
  {
    root->left=insertBST(root->left, d);
  }else{
    root->right=insertBST(root->right, d);
  }
  return root;
}

void inOrder(node* root)
{
  if(root==NULL)
    return;
  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
  return;
}

int main()
{
  int arr[]={5,1,8,13,7,2,99,45,212,5};
  node* root=NULL;
  for(auto it:arr)
  {
    root=insertBST(root, it);
  }

  inOrder(root);
  return 0;
}
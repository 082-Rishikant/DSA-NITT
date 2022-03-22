#include<iostream>
#include<climits>
#include<algorithm>
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

void inOrderSucc(node* root, int t, int &justG)
{
  if(root==NULL)
    return;
  
  if(t<root->data)
  {
    justG=min(justG, root->data);
    inOrderSucc(root->left, t, justG);
  } 
  else
    inOrderSucc(root->right, t, justG);
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
  int justG=INT_MAX;
  inOrderSucc(root, 45, justG);
  if(justG==INT_MAX)
    cout<<"No inOrder Successor";
  else
    cout<<justG;
  return 0;
}
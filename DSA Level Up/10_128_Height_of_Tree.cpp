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

int findHeight(node* root){
  if(root==NULL){
    return 0;
  }
  int left=findHeight(root->left);
  int right=findHeight(root->right);
  return max(left, right)+1;
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
  // we are calculating the height increased by 1
  cout<<(findHeight(root)-1)<<endl; // reduce by 1
  return 0;
}
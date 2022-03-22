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

node* findLSucc(node* root)
{
  if(root==NULL)
    return NULL;
  else{
    node* head=root;
    while(head->right!=NULL)
    {
      head=head->right;
    }
    return head;
  }
}

node* findRSucc(node* root)
{
  if(root==NULL)
    return NULL;
  else{
    node* head=root;
    while(head->left!=NULL)
    {
      head=head->left;
    }
    return head;
  }
}

pair<node* , node*> bstToSortedLinkedList(node* root)
{
  if(root==NULL)
    return {NULL, NULL};
  
  pair<node* , node*> l=bstToSortedLinkedList(root->left);
  if(root->left==NULL)
    l.first=root;
  else{
    l.second->right=root;
    root->left=NULL;
  }
  pair<node* , node*> r=bstToSortedLinkedList(root->right);
  if(root->right==NULL)
    r.second=root;
    else{
      root->right=r.first;
    }
  return {l.first, r.second};
}

void printLL(node* root)
{
  while(root!=NULL)
  {
    cout<<root->data<<" ";
    root=root->right;
  }
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
  // inOrder(root);

  root=bstToSortedLinkedList(root).first;
  printLL(root);
  return 0;
}
#include<iostream>
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

void inOrder(node* root)
{
  if(root==NULL)
    return;
  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
  return;
}

node* insertMinHeight(node* root, int arr[], int l, int r)
{
  if(l>r)
    return NULL;
  
  int mid=(l+r)/2;
  root=new node(arr[mid]);

  // Now from l to mid-1 put all the nodes in leftSubtree
  root->left=insertMinHeight(root->left, arr, l, mid-1);
  // and from mid+1 to r put all elements in rightSubtree
  root->right=insertMinHeight(root->right, arr, mid+1, r);
  return root;
}

int main()
{
  int arr[]={5,1,8,13,7,2,99,45,212,5};
  int n=sizeof(arr)/sizeof(arr[0]);
  // first sort the array
  sort(arr, arr+n);
  node* root=NULL;
  int l=0;  int r=n-1;
  root=insertMinHeight(root, arr, 0, r);
  inOrder(root);
  return 0;
}
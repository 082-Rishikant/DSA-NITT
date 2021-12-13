#include<iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    public: 
        node(int n)
        {
            data=n;
            left=NULL;
            right=NULL;
        }
};

node* BSTfromArr(int arr[], int l, int r)
{
    node* root=NULL;
    if(l>r)
    {
        return NULL;
    }
    if(r>=l)
    {
        int mid=(l+r)/2;
        root=new node(arr[mid]);
        root->left=BSTfromArr(arr, l, mid-1);
        root->right=BSTfromArr(arr, mid+1, r);
    }
    return root;
}

void inOrder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
    return;
}

int main()
{
    int arr[]={1, 2, 3, 4, 5, 6, 7};
    node* root=BSTfromArr(arr, 0, 6);
    inOrder(root);
    return 0;
}
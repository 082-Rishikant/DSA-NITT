#include<iostream>
using namespace std;

struct node
{
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

node* BSTfrompreOrder(int arr[], int* idx, int key, int min, int max, int n)
{
    if(*idx>=n)
    {
        return NULL;
    }
    node* root=NULL;
    if(key>min && key<max)
    {
        root=new node(key);
        *idx=*idx+1;
        if(*idx<n)
        {
            root->left=BSTfrompreOrder(arr, idx, arr[*idx], min, key, n);
        }
        if(*idx<n)
        {
            root->right=BSTfrompreOrder(arr, idx, arr[*idx], key, max, n);
        }
    }
    return root;
}

void preOrder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    return;
}

int main()
{
    int arr[]={10, 2, 1, 11, 13};
    int n=5;
    int idx=0;
    node* root=BSTfrompreOrder(arr, &idx, arr[0], INT_MIN, INT_MAX, n);

    preOrder(root);
    return 0;
}
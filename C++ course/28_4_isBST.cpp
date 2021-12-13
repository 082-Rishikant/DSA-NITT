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

node* buildBST1(node* root, int val)
{
    if(root==NULL)
    {
        return new node(val);
    }
    if(root->data>val)
    {
        root->left=buildBST1(root->left, val);
    }
    else
    {
        root->right=buildBST1(root->right, val);
    }
    return root;
}

// WRONG LOGIC*******************
bool isBST(node* root)
{
    if(root==NULL || (root->left==NULL && root->right==NULL))
    {
        return true;
    }
    else if(root->left==NULL || root->right==NULL)
    {
        if(root->left==NULL && root->data<root->right->data)
        {
            if(isBST(root->right)==true)
                return true;
        }
        if(root->right==NULL && root->data>root->left->data)
        {
            if(isBST(root->left)==true)
                return true;
        }
    }
    else if(root->data>root->left->data && root->data<root->right->data)
    {
        if(isBST(root->left)==true && isBST(root->right)==true)
        {
            return true;
        }
    }
    return false;
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

// OPTIMIZED APPROACH******************  
// O(N)
bool isBST2(node* root, int min , int max)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->data>min && root->data<max)
    {
        if(isBST2(root->left, min, root->data) && isBST2(root->right, root->data, max))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    node* root=NULL;
    int arr[]={2,11,73,9,1,4,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    root=buildBST1(root,arr[0]);
    for(int i=1;i<n;i++)
    {
        buildBST1(root,arr[i]);
    }

    // inOrder(root);

    // WRONG LOGIC*******************
    // if(isBST(root)==1)
    //     cout<<"A BST Tree\n";
    // else
    //     cout<<"Not a BST\n";

    cout<<isBST2(root, INT_MIN, INT_MAX);
    
    return 0;
}
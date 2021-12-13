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

// void buildBST2(node* &root, int val)
// {
//     node* newNode=new node(val);
//     if(root==NULL)
//     {
//         root=newNode;
//         return;
//     }
//     if(root->data>val)
//     {
//         if(root->left==NULL)
//         {
//             root->left=newNode;
//             return;
//         }
//         buildBST2(root->left, val);
//     }
//     else
//     {
//         if(root->right==NULL)
//         {
//             root->right=newNode;
//             return;
//         }
//         buildBST2(root->right, val);
//     }
//     return;
// }

node* buildBST1(node* root, int val)
{
    // node* newNode=new node(val);
    if(root==NULL)
    {
        return new node(val);
    }
    if(root->data>val)
    {
        // if(root->left==NULL)
        // {
        //     root->left=newNode;
        //     return root;
        // }
        // buildBST(root->left, val);
        root->left=buildBST1(root->left, val);
    }
    else
    {
        // if(root->right==NULL)
        // {
        //     root->right=newNode;
        //     return root;
        // }
        // buildBST(root->right, val);
        root->right=buildBST1(root->right, val);
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
    node* root=NULL;
    int arr[]={2,11,73,9,1,4,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    root=buildBST1(root,arr[0]);
    // cout<<n;
    for(int i=1;i<n;i++)
    {
        buildBST1(root,arr[i]);
        // buildBST2(root,arr[i]);
    }

    // preOrder(root);
    inOrder(root);
    return 0;
}
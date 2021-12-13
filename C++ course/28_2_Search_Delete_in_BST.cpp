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

bool search(node* root, int k)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==k)
    {
        return true;
    }
    if (root->data>k)
    {
        return search(root->left, k);
    }
    else
    {
        return search(root->right, k);
    }
    return false;  
}

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

node* inorderSucc(node* root)
{
   node* curr=root;
   while (curr->left!=NULL)
   {
       curr=curr->left;
   }
   return curr;
}

node* deleteinBST(node* root, int k)
{
    if(root->data==k)
    {
        if(root->left==NULL)
        {
            node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            node* temp=root->left;
            free(root);
            return temp;
        }
        else
        {
            node* temp=inorderSucc(root->right);
            root->data=temp->data;
            root->right=deleteinBST(root->right, temp->data);
        }
        
    }
    else if(root->data>k)
    {
        root->left=deleteinBST(root->left, k);
    }
    else
    {
        root->right=deleteinBST(root->right, k);
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
    node* root=NULL;
    int arr[]={2,11,73,9,1,4,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    root=buildBST1(root,arr[0]);
    for(int i=1;i<n;i++)
    {
        buildBST1(root,arr[i]);
    }

    // if(search(root, 3))
    // {
    //     cout<<"True";
    // }
    // else
    // {
    //     cout<<" false";
    // }
    inOrder(root);
    deleteinBST(root, 11);
    cout<<endl;
    inOrder(root);
    return 0;
}
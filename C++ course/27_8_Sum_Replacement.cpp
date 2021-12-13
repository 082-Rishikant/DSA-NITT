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

int sumRep(node* &root)
{
    if(root==NULL)
    {
        return 0;
    }
    root->data=sumRep(root->left)+sumRep(root->right)+root->data;
    return root->data;
}

void sumRep2(node* &root)
{
    if(root==NULL)
    {
        return;
    }
    sumRep2(root->left);
    sumRep2(root->right);

    if(root->left!=NULL)
        root->data+=root->left->data;
    if(root->right!=NULL)
        root->data+=root->right->data;

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
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->left->left=new node(6);
    root->right->right=new node(7);

    cout<<sumRep(root)<<endl;
    cout<<endl;
    sumRep2(root);
    inOrder(root);
    return 0;
}
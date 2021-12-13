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

void  flatTreeToLL(node* root)
{
    if(root==NULL || (root->left==NULL && root->right==NULL))
    {
        return;
    }
    if(root->left!=NULL)
    {
        flatTreeToLL(root->left);
        node* temp=root->right;
        root->right=root->left;
        root->left=NULL;

        node* t=root->right;
        while (t->right!=NULL)
        {
            t=t->right;
        }
        t->right=temp;
    }
    flatTreeToLL(root->right);
    return;
}

void print(node* root)
{
    while (root!=NULL)
    {
        cout<<root->data<<" ";
        root=root->right;
    }
}

int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->left->left=new node(6);
    root->right->right=new node(7);

    flatTreeToLL(root);
    print(root);
    return 0;
}
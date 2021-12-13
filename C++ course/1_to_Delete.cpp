#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

public:
    node(int n)
    {
        data = n;
        left = NULL;
        right = NULL;
    }
};

void func(node* root)
{
    if(root==NULL || (root->left==NULL && root->right==NULL))
    {
        return;
    }
    func(root->left);
    if(root->left!=NULL)
    {
        node* temp=root->right;
        root->right=root->left;
        root->left=NULL;
        node* tail=root->right;
        while (tail->right!=NULL)
        {
            tail=tail->right;
        }
        tail->right=temp;
    }
    func(root->right);
    return;
}

void printLL(node* root)
{
    while (root!=NULL)
    {
        cout<<root->data<<" ";
        root=root->right;
    }
    return;
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
}

int main()
{
    struct node *root = NULL;
    root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    preOrder(root); cout<<endl;
    func(root);
    printLL(root); cout<<endl;
    printLL(root);
    return 0;
}
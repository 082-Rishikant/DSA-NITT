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


int distance(node* root, int k, int dist)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->data==k)
    {
        return dist;
    }
    int l=distance(root->left, k, dist+1);
    if(l!=-1)
    {
        return l;
    }
    int r=distance(root->right, k, dist+1);
    if(r!=-1)
    {
        return r;
    }
    return -1;
}

node* LCA(node* root, int n1, int n2)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==n1 || root->data==n2)
    {
        return root;
    }
    node* l=LCA(root->left, n1, n2);
    node* r=LCA(root->right, n1, n2);
    if(l!=NULL && r!=NULL)
    {
        return root;
    }
    else if(l==NULL && r==NULL)
    {
        return NULL;
    }
    else if(l!=NULL)
    {
        return LCA(root->left, n1, n2);
    }
    else
    {
        return LCA(root->right, n1, n2);
    }
}

int minDistance(node* root, int n1, int n2)
{
    node* lca=LCA(root, n1 , n2);

    int d1=distance(root, n1, 0);
    int d2=distance(root, n2, 0);

    return d1+d2;
}

int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->left->left=new node(6);
    root->right->right=new node(7);

    cout<<minDistance(root, 2, 3);
    return 0;
}
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

void printSubtree(node* root, int k)
{
    if(root==NULL || k<0)
    {
        return;
    }
    if(k==0)
    {
        cout<<root->data<<" ";
        return;
    }
    printSubtree(root->left, k-1);
    printSubtree(root->right, k-1);
    return;
}

int  nodesAtK(node* root, int target, int k)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->data==target)
    {
        printSubtree(root, k);
        return 0;
    }
    int dl=nodesAtK(root->left, target, k);
    if(dl!= -1)
    {
        if(dl+1==k)
        {
            cout<<root->data<<" ";
        }
        else
        {
            printSubtree(root->right, k-dl-2);
        }
        return dl+1;
    }
    int dr=nodesAtK(root->right, target, k);
    if(dr!= -1)
    {
        if(dr+1==k)
        {
            cout<<root->data<<" ";
        }
        else
        {
            printSubtree(root->left, k-dr-2);
        }
        return dr+1;
    }
    return -1;
}

int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->left->left=new node(6);
    root->right->right=new node(7);

    nodesAtK(root, 2, 3);
    return 0;
}
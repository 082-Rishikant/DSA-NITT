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

int height(node* root) // O(n)
{
    if(root==NULL)
    {
        return 0;
    }
    return max(height(root->left), height(root->right))+1;
}

bool bruteForce(node* root) // O(n*n)
{
    if(root==NULL)
    {
        return true;
    }
    if(bruteForce(root->left)==false || bruteForce(root->right)==false)
        return false;
        
    int lh=height(root->left);
    int rh=height(root->right);
    if(abs(lh-rh)>1)
    {
        return false;
    }
    return true;
}

bool optimizedApproach(node* root, int * height) // O(n)
{
    if(root==NULL)
    {
        return true;
    }
    int lh=0;
    int rh=0;
    if(optimizedApproach(root->left, &lh)==false || optimizedApproach(root->right, &rh)==false)
        return false;
        
    
    if(abs(lh-rh)>1)
    {
        return false;
    }
    *height=max(lh, rh)+1;
    return true;
}

int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->left->left=new node(6);
    root->right->right=new node(7);

    cout<<bruteForce(root)<<endl;  // O(n*n)
    int height=0;
    cout<<optimizedApproach(root, &height)<<endl; // O(n)
    return 0;
}
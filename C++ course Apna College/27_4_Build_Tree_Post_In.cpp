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

void inOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
    return;
}

node* buildTree(int post[], int in[], int start, int end)
{
    static int idx=6;
    if(start>end)
    {
        return NULL;
    }
    node* newNode=new node(post[idx]);
    int pos=start;
    while (in[pos]!=post[idx])
    {
        pos++;
    }
    idx--;
    if(start==end)
    {
        return newNode;
    }
    newNode->right=buildTree(post, in, pos+1, end);
    newNode->left=buildTree(post, in, start, pos-1);
    return newNode;
}

int main()
{
    int Post[]={4,5,2,6,7,3,1};
    int In[]={4,2,5,1,6,3,7};
    node* root=buildTree(Post, In, 0, 6);
    inOrder(root);
    return 0;
}
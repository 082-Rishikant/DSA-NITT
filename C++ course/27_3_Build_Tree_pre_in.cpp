#include <iostream>
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

struct node* buildTree(int pre[], int in[], int start, int end)
{
    if(start>end)
    {
        return NULL;
    }
    static int idx=0;
    node* newNode=new node(pre[idx]);
    int pos=start;
    while (in[pos]!=pre[idx])
    {
        pos++;
    }
    idx++;
    if(start==end)
    {
        return newNode;
    }
    newNode->left=buildTree(pre,in, start,pos-1);
    newNode->right=buildTree(pre,in, pos+1,end);
    return newNode;
}

int main()
{
    int pre[]={1,2,4,3,5};
    int in[]={4,2,1,5,3};
    node* root=buildTree(pre, in,0,4);
    inOrder(root);
    return 0;
}
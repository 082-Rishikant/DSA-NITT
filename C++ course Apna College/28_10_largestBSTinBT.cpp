#include <iostream>
#include<climits>
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

struct info{
    int l;
    int max_l;
    bool flag;
    int minimum;
    int maximum;
};

info largestBSTinBT(node* root)
{
    if(root==NULL)
    {
        return {0, 0, true, INT_MIN, INT_MAX};
    }
    if(root->left==NULL && root->right==NULL)
    {
        return {1, 1, true, root->data, root->data};
    }
    info leftinfo=largestBSTinBT(root->left);
    info rightinfo=largestBSTinBT(root->right);

    info curr;
    curr.l=(1+leftinfo.l+rightinfo.l);

    if(leftinfo.flag==true && rightinfo.flag==true && root->data>leftinfo.maximum && root->data<rightinfo.minimum){
        curr.flag=true;
        curr.maximum=max(root->data, max(leftinfo.maximum, rightinfo.maximum));
        curr.minimum=min(root->data, min(leftinfo.minimum, rightinfo.minimum));
        curr.max_l=curr.l;
        return curr;
    }
    curr.flag=false;
    curr.max_l=max(leftinfo.max_l, rightinfo.max_l);
    return curr;
}

int main()
{
    node *root = new node(2);
    root->left = new node(1);
    root->right = new node(6);
    root->right->right = new node(73);
    root->right->left = new node(11);
    root->right->left->left = new node(10);

    cout<<largestBSTinBT(root).max_l<<endl;
    return 0;
}
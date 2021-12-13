#include <iostream>
#include <vector>
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

void restoreBST(node *root, node* &first, node* &mid, node* &last, node* &prev)
{
    if (root == NULL)
    { 
        return;
    }
    restoreBST(root->left, first, mid, last, prev);
    if (prev != NULL && prev->data > root->data)
    {
        if (first == NULL){
            first = prev;
            mid=root;
        }
        else
            last = root;
    }
    prev = root;
    restoreBST(root->right, first, mid, last, prev);
    return;
}

// void restoreBST(node* root)
// {
//     if(root==NULL)
//     {
//         return;
//     }
//     if(root->left!=NULL && root->right!=NULL && root->data<root->left->data && root->data>root->right->data)
//     {
//         int temp=root->left->data;
//         root->left->data=root->right->data;
//         root->right->data=temp;
//     }
//     restoreBST(root->left);
//     restoreBST(root->right);
//     return;
// }

void inOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
    return;
}

int main()
{
    node *root = new node(5);
    root->left = new node(1);
    root->right = new node(6);
    root->right->right = new node(73);
    root->right->left = new node(2);
    root->right->left->left = new node(4);

    inOrder(root);

    // restoreBST(root);
    node* first=NULL;
    node* mid=NULL;
    node* last=NULL;
    node* prev=NULL;
    restoreBST(root, first, mid, last, prev);
    if(first && last)
    {
        int temp=first->data;
        first->data=last->data;
        last->data=temp;
    }
    else if(first && mid)
    {
        int temp=first->data;
        first->data=mid->data;
        mid->data=temp;
    }
    cout << endl;
    inOrder(root);

    return 0;
}
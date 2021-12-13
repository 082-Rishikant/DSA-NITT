#include <iostream>
#include <stack>
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

node *buildBST1(node *root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }
    if (root->data > val)
    {
        root->left = buildBST1(root->left, val);
    }
    else
    {
        root->right = buildBST1(root->right, val);
    }
    return root;
}

void zigZag(node *root)
{
    stack<node *> ltr;
    stack<node *> rtl;
    cout<<root->data<<" ";
    ltr.push(root);
    while (!ltr.empty() || !rtl.empty())
    {
        if (!ltr.empty())
        {
            while (!ltr.empty())
            {
                node *temp = ltr.top();
                ltr.pop();
                if(temp->right!=NULL){
                    rtl.push(temp->right);
                    cout<<temp->right->data<<" ";
                }
                if(temp->left!=NULL){
                    rtl.push(temp->left);
                    cout<<temp->left->data<<" ";
                }
            }
        }
        else
        {
            while (!rtl.empty())
            {
                node *temp = rtl.top();
                rtl.pop();
                if(temp->left!=NULL){
                    ltr.push(temp->left);
                    cout<<temp->left->data<<" ";
                }
                if(temp->right!=NULL){
                    ltr.push(temp->right);
                    cout<<temp->right->data<<" ";
                }
            }
        }
    }
}

int main()
{
    node *root = NULL;
    int arr[] = {2, 11, 73, 9, 1, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    root = buildBST1(root, arr[0]);
    for (int i = 1; i < n; i++)
    {
        buildBST1(root, arr[i]);
    }

    zigZag(root);
    return 0;
}
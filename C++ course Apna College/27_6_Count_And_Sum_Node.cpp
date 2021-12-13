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

int countNode(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    // int sum=0;
    // sum+=countNode(root->left);
    // sum+=countNode(root->right);
    // return sum+1;
    return countNode(root->left)+countNode(root->right)+1;
}

int countSumofNode(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    // int sum=0;
    // sum+=countSumofNode(root->left);
    // sum+=countSumofNode(root->right);
    // return (sum+root->data);
    return countSumofNode(root->left)+countSumofNode(root->right)+root->data;
}

int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);

    cout<<countNode(root)<<endl;
    cout<<countSumofNode(root)<<endl;
    return 0;
}
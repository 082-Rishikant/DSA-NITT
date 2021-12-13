#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;

public:
    node(int n)
    {
        data = n;
        left = NULL;
        right = NULL;
    }
};

void preOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
    return;
}


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

void postOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
    return;
}

int main()
{
    struct node *root = NULL;
    root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    // the following tree has created.
    /*
         1
        / \
       2   3
      / \
     4   5
    */
    // cout<<"PreOrder Traversal:\n";
    // preOrder(root);

    // cout<<"inOrder Traversal:\n";
    // inOrder(root);

    cout << "postOrder Traversal:\n";
    postOrder(root);
    return 0;
}

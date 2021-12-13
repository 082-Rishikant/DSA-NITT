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

bool isIdenticalBST(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    else
    {
        if (root1->data == root2->data)
        {
            if (isIdenticalBST(root1->left, root2->left) && isIdenticalBST(root1->right, root2->right))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    node *root1 = new node(2);
    root1->left = new node(1);
    root1->right = new node(11);
    root1->right->right = new node(73);
    root1->right->left = new node(9);
    root1->right->left->left = new node(4);

    node *root2 = new node(2);
    root2->left = new node(1);
    root2->right = new node(11);
    root2->right->right = new node(73);
    root2->right->left = new node(9);
    // root2->right->left->left=new node(4);

    cout << isIdenticalBST(root1, root2);
    return 0;
}
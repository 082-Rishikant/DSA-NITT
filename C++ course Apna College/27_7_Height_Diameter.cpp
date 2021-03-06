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

int Height(node* root) // O(n) where n is the number of nodes
{
    if(root==NULL)
    {
        return 0;
    }
    return max(Height(root->left), Height(root->right))+1;
}

int treeDiameter(node* root, int &ans) // O(n) where n is the number of nodes
{
    if(root==NULL)
    {
        return 0;
    }
    else if(root->left!=NULL && root->right!=NULL)
    {
        ans=max(ans, treeDiameter(root->left, ans)+treeDiameter(root->right, ans)+1);
    }
    return max(treeDiameter(root->left, ans), treeDiameter(root->right, ans))+1;
}

// int ans=0;
// // Function to return the diameter of a Binary Tree.
// int diameter(node* root) {
//     if(root==NULL)
//         return 0;
    
//     int leftHeight=Height(root->left);
//     int rightHeight=Height(root->right);
    
//     int leftDiameter=diameter(root->left);
//     int rightDiameter=diameter(root->right);
    
//     return max(leftHeight+rightHeight+1, max(leftDiameter, rightDiameter));
// }

int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->left->left=new node(6);
    root->right->right=new node(7);

    cout<<Height(root)<<endl; // O(n) where n is the number of nodes
    int ans=0;

    treeDiameter(root, ans); // O(n) where n is the number of nodes
    cout<<ans;  
    return 0;
}
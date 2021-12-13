#include<iostream>
#include<queue>
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

void rightView(node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int prev;
    while(!q.empty())
    {
        node* newNode=q.front();
        q.pop();
        if(newNode!=NULL)
        {
            prev=newNode->data;
            if(newNode->left!=NULL)
                q.push(newNode->left);
            if(newNode->right!=NULL)
                q.push(newNode->right);
        }
        else if(!q.empty())
        {
            q.push(NULL);
            cout<<prev<<" ";
        }
        else
        {
            cout<<prev<<" ";
            break;
        } 
    }
    return;
}

void rightView2(node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*> q;
    q.push(root);
    while (!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            if(i==n-1)
            {
                cout<<q.front()->data<<" ";
            }
            if(q.front()->left!=NULL)
            {
                q.push(q.front()->left);
            }
            if(q.front()->right!=NULL)
            {
                q.push(q.front()->right);
            }
            q.pop();
        }
    }
    return;
}

int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->left->left=new node(6);
    root->right->right=new node(7);

    rightView(root);  // My method
    cout<<"\n";
    rightView2(root); // teacher mathod

    return 0;
}
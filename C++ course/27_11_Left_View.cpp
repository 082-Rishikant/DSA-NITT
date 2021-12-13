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

void leftView(node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    cout<<q.front()->data<<" ";
    while (!q.empty())
    {
        node* curr=q.front();
        q.pop();
        if(curr!=NULL)
        {
            // cout<<curr->data<<" ";
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
        else if(!q.empty())
        {
            cout<<q.front()->data<<" ";
            q.push(NULL);
        }
        else
        {
            break;
        }
        
    }
    
}

void leftView2(node* root)
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
            if(i==0)
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
    // root->left->right=new node(5);
    root->left->left->left=new node(6);
    root->right->right=new node(7);

    leftView(root); // my ethod
    cout<<"\n";
    leftView2(root); // teacher method
    return 0;
}
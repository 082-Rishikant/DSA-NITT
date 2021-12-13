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

void levelOrder(queue<node*> &q)
{
    while(!q.empty())
    {
        node* newNode=q.front();
        q.pop();
        if(newNode!=NULL)
        {
            cout<<newNode->data<<" ";
            if(newNode->left!=NULL)
                q.push(newNode->left);
            if(newNode->right!=NULL)
                q.push(newNode->right);
        }
        else if(!q.empty())
        {
            q.push(NULL);
        }
        else
        {
            continue;  
        }
    }

}

int sumAtKthLevel(node* root, int k)
{
    if(root==NULL)
    {
        return -1;
    }
    int sum=0;
    int level=0;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* newNode=q.front();
        q.pop();
        if(newNode!=NULL)
        {
            if(level==k)
            {
                sum+=newNode->data;
            }
            if(newNode->left!=NULL)
                q.push(newNode->left);
            if(newNode->right!=NULL)
                q.push(newNode->right);
        }
        else if(!q.empty())
        {
            q.push(NULL);
            level++;
            if(level>k)
                return sum;
        }
    }
    return sum;
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

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    // levelOrder(q);

    int k=1;
    cout<<sumAtKthLevel(root, k);
    return 0;
}
#include<iostream>
#include<vector>
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

void preOrder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    return;
}

int catalanNum(int n)
{
    int sum=0;
    if(n==1 || n==0)
    {
        return 1;
    }
    for(int i=0;i<n;i++)
    {
        sum=sum+catalanNum(n-1-i)*catalanNum(i);
    }
    return sum;
}

vector<node*> possibleBST(int l, int r)
{
    // vector<int> ans;
    vector<node*> ans;
    if(l>r)
    {
        ans.push_back(NULL);
        return ans;
    }
    for(int i=l;i<=r;i++)
    {
        vector<node*> lSubtree=possibleBST(l, i-1);
        vector<node*> rSubtree=possibleBST(i+1, r);
        
        for(int j=0;j<lSubtree.size();j++)
        {
            node* left=lSubtree[j];
            for(int k=0;k<rSubtree.size();k++)
            {
                node* right=rSubtree[k];
                node* newNode=new node(i);
                newNode->left=left;
                newNode->right=right;
                ans.push_back(newNode);
            }
        }
    }
    return ans;
}

int main()
{
    // int n=5;
    // for(int i=0;i<=n;i++)
    // {
    //     cout<<catalanNum(i)<<" ";
    // }
    vector<node*> vec = possibleBST(1, 3);
    for(auto it:vec)
    {
        preOrder(it);
        cout<<"\n";
    }
    return 0;
}
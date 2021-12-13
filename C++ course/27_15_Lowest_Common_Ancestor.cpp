#include<iostream>
#include<vector>
using namespace std;

struct node
{
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

bool givePath(node* root, int k, vector<int> &vec)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==k)
    {
        vec.push_back(root->data);
        return true;
    }
    if(givePath(root->left, k, vec))
    {
        vec.push_back(root->data);
        return true;
    }
    if(givePath(root->right, k, vec))
    {
        vec.push_back(root->data);
        return true;;
    }
    return false;
}

int  lowest_C_Ancestor(node* root, int n1, int n2)
{
    if(root==NULL)
    {
        return -1;
    }
    vector<int> v1;
    vector<int> v2;
    if(!givePath(root,n1,v1) || !givePath(root, n2, v2))
    {
        return -1;
    }  
    int ans=-1;
    vector<int>::reverse_iterator it1=v1.rbegin();
    vector<int>::reverse_iterator it2=v2.rbegin();
    while(*it1==*it2)
    {
        ans=*it1;
        it1++;
        it2++;
    }
    return ans;
}

bool optimizedApproach(node* root, int n1, int n2)
{
    // static bool flag1=false;
    // static bool flag2=false;
    if(root==NULL)
    {
        return false;
    }
    if(root->data==n1)
    {
        return true;
    }
    if(root->data==n2)
    {
        return true;
    }
    
    
    if(optimizedApproach(root->left, n1, n2)==true && optimizedApproach(root->right, n1, n2)==true)
    {
        cout<<root->data<<endl;
        return true;
    }
    if(optimizedApproach(root->left, n1, n2)==true || optimizedApproach(root->right, n1, n2)==true)
    {
        return true;
    }
    return false;
}

int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(8);
    root->left->left->left=new node(6);
    root->right->right=new node(7);

    // int ans=lowest_C_Ancestor(root, 8, 7);
    // if(ans== -1)
    // {
    //     cout<<"Given Input is wrong";
    // }
    // else
    // {
    //     cout<<"LCA: "<<ans;
    // }

    optimizedApproach(root, 8, 7);
    return 0;
}
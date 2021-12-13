#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void permute(vector<int> &a, int i)
{
    if(i==a.size())
    {
        ans.push_back(a);
        return;
    }
    for(int j=i;j<a.size();j++)
    {
        swap(a[j],a[i]);
        permute(a,i+1);
        swap(a[j], a[i]);
    }
}

int main()
{
    // int n;
    // cout<<"\nEnter the size:  ";
    // cin>>n;
    vector<int> a{1,2,3};
    // cout<<"\nEnter the array: ";
    // for(auto &i:a)
    // {
    //     cin>>i;
    // }
    permute(a,0);
    for(auto &v:ans)
    {
        for(auto &i:v)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
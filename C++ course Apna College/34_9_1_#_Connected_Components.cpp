#include<iostream>
#include<vector>
using namespace std;

int getComp(int src, vector<vector<int>> adjL, vector<bool> &vis)
{
    vis[src]=true;
    int ans=1;
    for(int item:adjL[src])
    {
        if(!vis[item])
            ans+=getComp(item, adjL, vis);
    }
    return ans;
}

int main()
{
    int n, e;cin>>n>>e;
    vector<vector<int>> adjL(n);
    vector<bool> vis(n, false);
    vector<int> components;
    for(int i=0;i<e;i++)
    {
        int x, y;
        cin>>x>>y;
        adjL[x].push_back(y);
        adjL[y].push_back(x);
    }

    for(int i=0;i<n;i++)
        if(!vis[i])
            components.push_back(getComp(i, adjL, vis));
    
    int l=components.size();

    for(int i:components)
        cout<<i<<" ";
    return 0;
}
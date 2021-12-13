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
    int n, e;
    cout<<"Enter the #boys and #between links\n";
    cin>>n>>e;
    vector<vector<int>> adjL(n);
    vector<bool> vis(n, false);
    vector<int> components;
    components.push_back(0);
    for(int i=0;i<e;i++)
    {
        int x, y;
        cout<<"Enter edge through wich two boys are connencted\n";
        cin>>x>>y;
        adjL[x].push_back(y);
        adjL[y].push_back(x);
    }

    for(int i=0;i<n;i++)
        if(!vis[i])
            components.push_back(getComp(i, adjL, vis));
    
    int l=components.size();
    int ans=0;

    // First Way
    /*for(int i=1;i<l;i++)
    {
        components[i]=components[i]+components[i-1];
    }
    for(int i=1;i<l-1;i++)
    {
        ans+=(components[i]-components[i-1])*(components[l-1]-components[i]);
    }*/

    // Second Way
    for (int i = 1; i < l; i++) // at zeroth position there is a extra zero for previous method
    {
        ans+=components[i]*(n-components[i]);
    }
    ans/=2;

    cout<<ans;
    return 0;
}
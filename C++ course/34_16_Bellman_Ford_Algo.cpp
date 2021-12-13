#include<iostream>
#include<vector>
using namespace std;
const int N=1e5;
int main()
{
    int n, e;cin>>n>>e;
    vector<vector<int>> edges(n, vector<int>(3));
    for (int i = 0; i < e; i++)
    {
        int x,y,w;cin>>x>>y>>w;
        edges.push_back({x,y,w});
    }
    vector<int> dist(n, N);
    cout<<"Enter the source(0-n): \n";
    int src;cin>>src;
    dist[src]=0;
    for (int i = 0; i < n-1; i++)
    {
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            dist[v]=min(dist[v], dist[u]+w);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<dist[i]<<" ";
    }
    return 0;
}
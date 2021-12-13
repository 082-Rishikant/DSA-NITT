#include<iostream>
#include<vector>
#include<map>
using namespace std;
const int N=1e3;
vector<pair<int, int>> adjL[N];
vector<int> dist(N, N);
map<int, int> st;
// vector<int> cost;

void dijkstra(int source)
{
    dist[source]=0;
    st.insert({0, source});
    while(!st.empty())
    {
        int u=(st.begin())->second;
        int prev=(st.begin())->first;
        st.erase(st.begin());
        for (pair<int, int> p:adjL[u])
        {
            int v=p.first;
            if(dist[v]>(p.second+prev))
            {
                if(st.find(dist[v])!=st.end())
                    st.erase(st.find(dist[v]));
                dist[v]=p.second+prev;
                st.insert({dist[v], v});
            }
        }
    }
}

int main()
{
    int n, e;cin>>n>>e;
    // vector<pair<int, int>> adjL[n];
    // vector<int> dist(n, 1e4);
    // vector<int> cost(n, 0);
    for (int i = 0; i < e; i++)
    {
        int x, y, w;cin>>x>>y>>w;
        adjL[x].push_back({y, w});
        adjL[y].push_back({x, w});
    }
    dijkstra(0);
    for(int i=0;i<n;i++)
    {
        if(dist[i]<N)
            cout<<dist[i]<<" ";
        else
            cout<<-1<<" ";
    }
    return 0;
}
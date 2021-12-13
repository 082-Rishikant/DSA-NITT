#include <iostream>
#include <bits/stdc++.h>
// #include<unordered_set>
#include <vector>
#include <map>
using namespace std;
const int N = 1e5;
int cost = 0, n;
int e;
vector<pair<int, int>> adjL[N]; // u->{{v1,w1},{v2, w2}} vector of pairs
vector<bool> vis(N, false);
vector<int> dist(N, N);
vector<int> parent(N);
map<int, int> st;

void primsAlgo(int a)
{ // {(a:b):w}
    // for (int i = 0; i < n; i++)
    // {
    //     dist[i] = N;
    // }
    st.insert({0, a});//{w, v}
    dist[0] = 0;

    while (!st.empty())
    {
        auto it = st.begin(); // it is a vector
        int w = it->first;
        int u = it->second;
        int v = parent[u];
        st.erase(st.begin());
        vis[u] = true;
        cost = cost + w;
        cout << v << " " << u << " " << w << endl;
        for (pair<int, int> b : adjL[u]) //u->{v, w}
        {
            if (vis[b.first]==true)
            {
                continue; // this is important
            }
            else if (dist[b.first] > b.second) // also importent part
            {
                if (st.find(dist[b.first]) != st.end())
                    st.erase(dist[b.first]);
                dist[b.first] = b.second;
                st.insert({dist[b.first], b.first});
                parent[b.first] = u;
            }
        }
    }
}

int main()
{
    
    cin >> n >> e;
    // vector<pair<int, int>> adjL[n]; // u->{{v1,w1},{v2, w2}} vector of pairs
    // vector<bool> vis(n, false);
    // vector<int> dist(n, N);
    // vector<int> parent(n);
    // map<int, int> st;
    for (int i = 0; i < e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adjL[x].push_back({y, w});
        adjL[y].push_back({x, w});
    }

    primsAlgo(0);
    cout << cost;
    return 0;
}
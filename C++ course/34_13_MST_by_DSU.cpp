#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> pt;
vector<int> Rank;

int find_Parent(int src)
{
    if(src==pt[src])
        return src;
    return find_Parent(pt[src]);
}

void Union(int a, int b)
{
    a=find_Parent(a);
    b=find_Parent(b);
    if(Rank[b]>Rank[a])
        swap(a, b);
    else if(Rank[a]==Rank[b])
        Rank[a]++;
    pt[b]=a;
}

int main()
{
    int n, e;cin>>n>>e;
    pt=vector<int>(n);
    Rank=vector<int>(n, 0);
    vector<vector<int>> adjL;
    for(int i=0;i<n;i++)
    {
        pt[i]=i;
    }
    int wt=0;
    for(int i=0;i<e;i++)
    {
        int x,y,w;cin>>x>>y>>w;
        adjL.push_back({w, x, y});
    }
    sort(adjL.begin(), adjL.end());
    for(auto p:adjL)
    {
        int a=p[1];
        int b=p[2];
        int pa=find_Parent(a);
        int pb=find_Parent(b);
        if(pa!=pb)
        {
            Union(a, b);
            wt+=p[0];
            cout<<a<<" "<<b<<endl;
        }
    }
    cout<<wt;
    return 0;
}
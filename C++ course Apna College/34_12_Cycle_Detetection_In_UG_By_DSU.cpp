#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
unordered_map<int, int> pt;

int parent(int src)
{
    if(src==pt[src])
        return src;
    return pt[src]=parent(pt[src]);
}

int main()
{
    int n;cin>>n;
    pt=unordered_map<int, int>(n);
    for (int i = 0; i < n; i++)
    {
        pt[i]=i;
    }
    vector<int> rank(n, 0);
    cout<<"Enter th #egdes\n";
    int e;cin>>e;
    while (e--)
    {
        int a, b;cin>>a>>b;
        a=parent(a);
        b=parent(b);
        if(pt[a]==pt[b]){
            cout<<"Cycle found\n";
            return 0;
        }
        if(rank[b]>rank[a])
            swap(a, b);
        else if(rank[a]==rank[b])
            rank[a]++;
        pt[b]=a;
    }
    cout<<"No Cycle Found\n";
    return 0;
}
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
unordered_map<int, int> pt;

int findParent(int src)
{
    if(pt[src]==src)
    {
        return src;
    }
    return pt[src] = findParent(pt[src]);
}

int main()
{
    int n;
    cin>>n;
    pt=unordered_map<int, int>(n);
    vector<int> rank(n, 0);
    for(int i=0;i<n;i++)
    {
        pt[i]=i;
    }
    cout<<"Enter the #union operations\n";
    int U; cin>>U;
    while(U--)
    {
        int a, b; cin>>a>>b;
        a=findParent(a);
        b=findParent(b);
        if(rank[b]>rank[a])
            swap(a, b);
        else if(rank[a]==rank[b])
            rank[a]++;
        pt[b]=a;
        cout<<"Now the parent of "<<b<<" is "<<pt[b]<<endl;
    }
    cout<<"Enter the #Findpt operations\n";
    int P; cin>>P;
    while(P--)
    {
        int a; cin>>a;
        cout<<findParent(a)<<endl;
    }
    return 0;
}
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
unordered_map<int, int> pt;

// 1- Naive Implamentation  -  O(n)
/*int findParent(int src)
{
    if(pt[src]==src)
    {
        return src;
    }
    return findParent(pt[src]);
}*/

// 2- Path Compression Method   - O(logn)
int findParent(int src)
{
    if(pt[src]==src)
    {
        return src;
    }
    pt[src]=findParent(pt[src]);
    return pt[src];
}

int main()
{
    int n;
    cin>>n;
    pt=unordered_map<int, int>(n);
    // vector<int> rank(n, 0);
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
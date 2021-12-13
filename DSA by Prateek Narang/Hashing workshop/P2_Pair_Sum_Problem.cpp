#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
int main()
{
    int n; cin>>n; int k; cin>>k;
    vector<int> s1;
    unordered_set<int> s2;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        s1.push_back(x);
    }
    for(int it:s1)
    {
        if(s2.find(k-it)!=s2.end())
            cout<<it<<","<<k-it<<endl;
        s2.insert(it);
    }
    return 0;
}
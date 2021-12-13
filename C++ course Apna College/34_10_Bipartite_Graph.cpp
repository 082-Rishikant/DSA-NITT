#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> adjL;
vector<bool> vis;
vector<int> col;
bool ans;
void checkBP(int src, int color)
{
    col[src]=color;
    for(int item:adjL[src])
    {
        if(col[item]==0)
            checkBP(item, -color);
        else if(col[item]==color)
        {
            ans=false;
            return;
        }
    }
}

int main()
{
    ans=true;
    int n, e;cin>>n>>e;
    adjL=vector<vector<int>>(n);
    vis=vector<bool>(n,false);
    col=vector<int>(n, 0);
    for(int i=0;i<e;i++)
    {
        int x,y;cin>>x>>y;
        adjL[x].push_back(y);
        adjL[y].push_back(x);
    }

    for(int i=0;i<n;i++)
    {
        if(col[i]==0)
            checkBP(i,1);
    }
    if(ans==false)
        cout<<"Not a bipartite\n";
    else
        cout<<"A Bipartite\n";
    return 0;
}
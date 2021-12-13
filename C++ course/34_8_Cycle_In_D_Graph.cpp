#include<iostream>
#include<vector>
using namespace std;

bool isCycle(int src, vector<int> adjL[], vector<bool> &visited, vector<bool> &st)
{
  st[src]=true;
  visited[src]=true;
  for(int it:adjL[src])
  {
    if(!visited[it] && isCycle(it, adjL, visited, st))
    {
      return true;
    }
    if(st[it])
    {
      return true;
    }
  }
  st[src]=false;
  return false;
}

int main()
{
  int n, e;cin>>n>>e;
  vector<int> adjL[n+1];
  vector<bool> st(n+1, false);
  vector<bool> visited(n+1, false);
  for(int i=0;i<e;i++)
  {
    int x, y;cin>>x>>y;
    adjL[x].push_back(y);
  }
  bool ans=false;
  for(int i=1;i<=n;i++)
  {
    if(!visited[i] && isCycle(i, adjL, visited, st))
    {
      ans=true;
    }
  }
  if(ans)
    cout<<"Cycle Found\n";
  else
    cout<<"No Cycle Found\n";
  return 0;
}
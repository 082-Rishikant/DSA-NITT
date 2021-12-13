/*#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e8 + 10;
bool vis[N];
vector<int> adjL[N];
int main()
{
  int n, e;
  cin >> n >> e;
  for (int i = 0; i < e; i++)
  {
    int x, y;
    cin >> x >> y;
    adjL[x].push_back(y);
    adjL[y].push_back(x);
  }
  queue<pair<int, int>> q;
  q.push(make_pair(1, -1));
  vis[1] = true;
  while (!q.empty())
  {
    pair<int, int> d = q.front();
    q.pop();
    vector<int>::iterator it;
    for (it = adjL[d.first].begin(); it != adjL[d.first].end(); it++)
    {
      if (vis[*it] == true && d.second != *it)
      {
        cout << "Cycle Found\n";
        return 0;
      }
      else if (vis[*it] == true)
      {
        continue;
      }
      else
      {
        q.push(make_pair(*it, d.first));
        vis[*it] = true;
      }
    }
  }
  cout<<"Cycle Not Found\n";
  return 0;
}*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isCycle(int src, vector<vector<int>> adjL, vector<bool> vis, int parent)
{
  vis[src]=true;
  vector<int>::iterator it;
  for(it=adjL[src].begin();it!=adjL[src].end();it++)
  {
    if(*it!=parent)
    {
      if(vis[*it])
        return true;
      else
        if(isCycle(*it, adjL, vis, src))
          return true;
    }
  }
  return false;
}

int main()
{
  int n,e;cin>>n>>e;
  vector<bool> vis(n+1, false);
  vector<vector<int>> adjL(n+1);
  for(int i=0;i<e;i++)
  {
    int x,y;cin>>x>>y;
    adjL[x].push_back(y);
    adjL[y].push_back(x);
  }
  bool ans=false;
  for(int i=1;i<=n;i++)
  {
    if(!vis[i] && isCycle(i, adjL, vis, -1))
      ans=true;
  }
  if(ans)
    cout<<"Cycle Found\n";
  else
    cout<<"No Cycle Found\n";
  return 0;
}
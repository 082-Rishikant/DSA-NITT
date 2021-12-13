#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N=1e8+2;
bool vis[N];
vector<int> adjL[N];

int main()
{
  for(int i=0;i<N;i++)
    vis[i]=false;

  int n,e;
  cin>>n>>e;
  for (int i = 0; i < e; i++)
  {
    int x; int y;
    cin>>x>>y;
    adjL[x].push_back(y);
    adjL[y].push_back(x);
  }
  queue<int> q;
  q.push(1);
  vis[1]=true;
  while(!q.empty())
  {
    int data=q.front();
    cout<<data;
    q.pop();
    vector<int> :: iterator it;
    for(it=adjL[data].begin();it!=adjL[data].end();it++)
    {
      if(vis[*it]==false)
      {
        vis[*it]=true;
        q.push(*it);
      }
    }
  }
  
}
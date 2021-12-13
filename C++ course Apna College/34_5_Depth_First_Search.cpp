#include<iostream>
#include<vector>
#include<stack>
using namespace std;
const int N=1e8+10;
bool vis[N];
vector<int> adjL[N];

void dfs(int node)
{
  // preorder
  vis[node]=true;
  // cout<<node<<" ";

  // Inorder 
  vector<int>::iterator it;
  for(it=adjL[node].begin();it!=adjL[node].end();it++)
  {
    if(vis[*it]==false)
    {
      dfs(*it);
    }
  }

  // Postorder
  cout<<node<<" ";
}

int main()
{
  for(int i=0;i<N;i++)
  {
    vis[i]=false;
  }
  int n, e;
  cin>>n>>e;
  for(int i=0;i<e;i++)
  {
    int x,y;
    cin>>x>>y;
    adjL[x].push_back(y);
    adjL[y].push_back(x);
  }
  // Firts way

  /*stack<int> st;
  st.push(1);
  vis[1]=true;
  while(!st.empty())
  {
    int data=st.top();
    cout<<data<<" ";
    st.pop();
    vector<int>::iterator it;
    for(it=adjL[data].begin();it!=adjL[data].end();it++)
    {
      if(vis[*it]==false)
      {
        vis[*it]=true;
        st.push(*it);
      }
    }
  }*/

  // 2nd Way
  dfs(1);
  return 0;
}
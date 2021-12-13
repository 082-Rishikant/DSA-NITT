#include<iostream>
#include<vector>
using namespace std;
int main()
{
  int n, e;
  cin>>n>>e;
  vector<vector<int>> adjm(n+1, vector<int>(n+1, 0));
  for(int i=1;i<=e;i++)
  {
    int x, y;
    cin>>x>>y;
    adjm[x][y]=1;
    adjm[y][x]=1;
  }
  cout<<"   ";
  for(int i=1;i<=n;i++)
  {
    cout<<"["<<i<<"]";
  }
  cout<<endl;
  for(int i=1;i<=n;i++)
  {
    cout<<"["<<i<<"]";
    for(int j=1;j<=n;j++)
    {
      cout<<" "<<adjm[i][j]<<" ";
    }
    cout<<endl;
  }

  cout<<"\n\n\n\n";
  vector<int> adjL[n+1];
  for(int i=1;i<=e;i++)
  {
    int x, y;
    cin>>x>>y;
    adjL[x].push_back(y);
    adjL[y].push_back(x);
  }
  for(int i=1;i<=n;i++)
  {
    cout<<i<<"->";
    for(int item:adjL[i])
    {
      cout<<item<<" ";
    }
    cout<<endl;
  }
  return 0;
}
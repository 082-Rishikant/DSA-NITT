#include<bits/stdc++.h>

using namespace std;
const int N=1e3+7;
vector<vector<int>> t(N, vector<int>(N, -1));

int minSteps(int n, int m, int currx, int curry)
{
  if(currx==n && curry==m)
    return t[currx][curry]=0;
  if(currx>n || curry>m)
    return -1;
  
  if(t[currx][curry]!=-1)
    return t[currx][curry];

  int down=minSteps(n,m,currx, curry+currx);
  int forward=minSteps(n,m,curry+currx,currx);
  if(down==-1 && forward==-1)
    return -1;
  else if(down==-1)
    return t[currx][curry]=forward+1;
  else if(forward==-1)
    return t[currx][curry]=down+1;
  else
    return t[currx][curry]=min(down, forward)+1;
}

int main()
{
  int n, m; n=4,m=3;
  cout<<minSteps(n, m, 1, 1);
  return 0;
}
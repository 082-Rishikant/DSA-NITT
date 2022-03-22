#include<iostream>
#include<cstring>
using namespace std;
int * t;

void solve(int n, int k){
  t[0]=1; t[1]=1; int sum=2;
  for(int i=2;i<=k;i++){
    t[i]=sum;
    sum+=t[i];
  }
  for(int i=k+1;i<=n;i++){
    t[i]+=sum-t[i-(k+1)];
    sum+=t[i];
  }
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n=4;  int k=3;
  t=new int[n+1];
  // memset(t, -1, sizeof(t));
  for(int i=0;i<=n;i++){
    t[i]=0;
  }

  solve(n, k);

  cout<<t[n];
  return 0;
}
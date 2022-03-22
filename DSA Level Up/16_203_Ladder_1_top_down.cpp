#include<iostream>
#include<cstring>
using namespace std;
int * t;

int solve(int curr, int n, int k){
  if(curr==n){
    return 1;
  }
  if(t[curr]!=-1)
    return t[curr];
  int i=1;  int sum=0;
  while(i<=k && (curr+i)<=n){
    sum+=solve(curr+i, n, k);
    i++;
  }
  return t[curr]=sum;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n=4;  int k=3;
  t=new int[n];
  // memset(t, -1, sizeof(t));
  for(int i=0;i<n;i++){
    t[i]=-1;
  }
  cout<<solve(0, n, k);
  return 0;
}
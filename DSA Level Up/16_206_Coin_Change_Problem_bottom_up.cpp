#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
const int N=1e4;
int t[N+1][N+1];

void coinChangeRecursive(int arr[], int n, int target){
  
  for(int i=0;i<=N;i++){
    for(int j=0;j<=N;j++){
      if(j==0)
        t[i][j]=0;
      else if(i==0)
        t[i][j]=INT_MAX-1;
    }
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=target;j++){
      if(arr[i-1]<=j){
        t[i][j]=min(t[i][j-arr[i-1]]+1, t[i-1][j]);
      }else{
        t[i][j]=t[i-1][j];
      }
    }
  }

  return;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n=4;
  int arr[]={1,3,7,10};
  int target=19;

  memset(t, -1, sizeof(t));

  coinChangeRecursive(arr, n, target);
  cout<<t[n][target];
  return 0;
}
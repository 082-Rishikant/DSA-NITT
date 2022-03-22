#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
const int N=1e4;
int t[N][N];

int coinChangeRecursive(int arr[], int n, int target){
  // cout<<"start";
  if(n==0)
    return t[n][target]=INT_MAX-1;
  if(target==0){
    return t[n][target]=0;
  }
  if(t[n][target]!=-1)
    return t[n][target];
  
  int temp=INT_MAX-1;
  // cout<<temp<<" ";
  if(arr[n-1]<=target){
    temp=min(coinChangeRecursive(arr, n, target-arr[n-1])+1, coinChangeRecursive(arr, n-1, target));
  }else{
    temp=coinChangeRecursive(arr, n-1, target);
  }
  
  return t[n][target]=temp;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n=4;
  int arr[]={1,3,7,10};
  int target=12;

  memset(t, -1, sizeof(t));

  coinChangeRecursive(arr, n, target);
  cout<<t[n][target];
  return 0;
}
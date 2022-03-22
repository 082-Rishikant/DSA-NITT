#include<iostream>
#include<climits>
#include<cstring>
using namespace std;

int coinChangeRecursive(int arr[], int n, int target){
  // cout<<"start";
  if(n==0)
    return INT_MAX-1;
  if(target==0){
    return 0;
  }

  int temp=INT_MAX-1;
  // cout<<temp<<" ";
  if(arr[n-1]<=target){
    temp=min(coinChangeRecursive(arr, n, target-arr[n-1])+1, coinChangeRecursive(arr, n-1, target));
  }else{
    temp=coinChangeRecursive(arr, n-1, target);
  }
  
  return temp;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n=4;
  int arr[]={1,3,7,10};
  int target=15;


  cout<<coinChangeRecursive(arr, n, target);
  return 0;
}
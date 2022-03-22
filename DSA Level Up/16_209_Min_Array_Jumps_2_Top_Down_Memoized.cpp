#include<iostream>
#include<vector>
#include <algorithm>
#include<string.h>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<climits>

const int N=1e4;
using namespace std;
int *t;

int minArrJump(int arr[], int n, int curr){
  if(curr>=(n-1))
    return t[curr]=0;
  
  if(t[curr]!=-1)
    return t[curr];

  int temp=INT_MAX-1;
  for(int i=1;i<=arr[curr];i++){
    if((curr+i)>=n)
      continue;
    if(t[curr+i]==-1)
      t[curr+i]=minArrJump(arr, n, curr+i);
    temp=min(temp, t[curr+i]+1);
             
  }
  return t[curr]=temp;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif


  int arr[]={3,4,2,1,2,3,7,1,1,1,2,5};
  int n=sizeof(arr)/sizeof(arr[0]);
  t=new int[n];
  for(int i=0;i<n;i++){
    t[i]=-1;
  }

  minArrJump(arr, n, 0);
  cout<<t[0];
  return 0;
}
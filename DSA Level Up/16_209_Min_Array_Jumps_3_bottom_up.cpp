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

void minArrJump(int arr[], int n){
  // base case matrix initialization
  t[0]=0;

  for(int i=0;i<(n-1);i++){
    for(int curr=1;curr<=arr[i];curr++){
      if((i+curr)>=n)
        break;
      t[i+curr]=min(t[i]+1, t[i+curr]);
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


  int arr[]={3,4,2,1,2,3,7,1,1,1,2,5};
  int n=sizeof(arr)/sizeof(arr[0]);
  
  t=new int[n];
  for(int i=0;i<n;i++){
    t[i]=INT_MAX;
  }

  minArrJump(arr, n);
  cout<<t[n-1];

  return 0;
}
#include<iostream>
#include<vector>
#include <algorithm>
#include<string.h>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<climits>

const int N=1e9+7;
using namespace std;

int minArrJump(int arr[], int n, int curr){
  if(curr>=n)
    return 0;
  
  int temp=INT_MAX-1;
  for(int i=1;i<=arr[curr];i++){
    temp=min(temp, minArrJump(arr, n, curr+i)+1);
  }
  return temp;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int arr[]={3,4,2,1,2,3,7,1,1,1,2,5};
  int n=sizeof(arr)/sizeof(arr[0]);

  cout<<minArrJump(arr, n, 0);

  return 0;
}
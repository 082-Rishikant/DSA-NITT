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
int *t;

int frogMinCost(vector<int> arr, int n, int curr){
  if(curr>=(n-1))
    return 0;
  if(t[curr]!=-1)
    return t[curr];

  int temp=INT_MAX-1;
  for(int i=1;i<=2;i++){
    if((curr+i)>=n)
      continue;
    
    if(t[curr+i]==-1)
      t[curr+i]=frogMinCost(arr, n, curr+i);

    temp=min(temp, t[curr+i]+abs(arr[curr]-arr[curr+i]));
  }
  return t[curr]=temp;
}

int main()
{
// #ifndef ONLINE_JUDGE
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
// #endif

  vector<int> arr={30,10,60,10,60,50};
  int n=arr.size();

  t=new int[n];
  for(int i=0;i<n;i++){
    t[i]=-1;
  }

  cout<<frogMinCost(arr, n, 0);
  return 0;
}
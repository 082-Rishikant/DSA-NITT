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

int frogMinCost(vector<int> arr, int n, int curr){
  if(curr>=(n-1))
    return 0;

  int temp=INT_MAX-1;
  for(int i=1;i<=2;i++){
    if((curr+i)>=n)
      continue;
    temp=min(temp, frogMinCost(arr, n, curr+i)+abs(arr[curr]-arr[curr+i]));
  }
  return temp;
}

int main()
{
// #ifndef ONLINE_JUDGE
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
// #endif

  vector<int> arr={30,10,60,10,60,50};
  int n=arr.size();

  cout<<frogMinCost(arr, n, 0);
  return 0;
}
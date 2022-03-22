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

int longestIncSeq(vector<int> arr, int n, int prev, int next, int l){
  if(next==n)
  {
    return l;
  }

  int temp;
  if(arr[prev]<arr[next]){
    temp=longestIncSeq(arr, n, prev+1, next+1, l+1);
  }else{
    temp=max(longestIncSeq(arr, n, prev, next+1, l), longestIncSeq(arr, n, prev+1, next+1, l));
  }
  
  return temp;
}

int main()
{
  vector<int> arr={50,4,10,8,30,100};
  int n=arr.size();

  cout<<longestIncSeq(arr, n, 0, 1, 1);

  return 0;
}
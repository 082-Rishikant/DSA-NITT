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

int rodCutting(int len[], int val[], int n, int length){
  if(n==0)
    return 0;
  if(length==0)
    return 0;
  
  int temp=0;
  if(len[n-1]<=length){
    temp=max(rodCutting(len, val, n, length-len[n-1])+val[n-1], rodCutting(len, val, n-1, length));
  }else{
    temp=rodCutting(len, val, n-1, length);
  }
  return temp;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int len[]={1,2,3,4,5,6,7,8};
  int n=sizeof(len)/sizeof(len[0]);
  int val[]={3,5,8,9,10,17,17,20};
  int target=8;

  cout<<rodCutting(len, val, n, target);
  return 0;
}
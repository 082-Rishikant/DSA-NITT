#include<iostream>
#include<vector>
#include <algorithm>
#include<string.h>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<climits>

const int N=1e4+7;
int t[N][N];

using namespace std;

int rodCutting(int len[], int val[], int n, int length){
  if(n==0)
    return t[n][length]=0;
  if(length==0)
    return t[n][length]=0;
  
  if(t[n][length]!=-1)
    return t[n][length];

  int temp=0;
  if(len[n-1]<=length){
    temp=max(rodCutting(len, val, n, length-len[n-1])+val[n-1], rodCutting(len, val, n-1, length));
  }else{
    temp=rodCutting(len, val, n-1, length);
  }
  return t[n][length]=temp;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  memset(t, -1, sizeof(t));

  int len[]={1,2,3,4,5,6,7,8};
  int n=sizeof(len)/sizeof(len[0]);
  int val[]={3,5,8,9,10,17,17,20};
  int length=8;

  rodCutting(len, val, n, length);
  cout<<t[n][length];

  return 0;
}
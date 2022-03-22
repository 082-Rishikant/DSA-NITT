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

int solveUsingBinary(int arr[], int n, int p) //O(nlogn)
{
  int ans=0;
  int l=0;int r=arr[n-1]-arr[0];
  while(l<=r)
  {
    int mid=(l+r)/2;
    int prevLocation=arr[0];
    int cnt=1; int idx=1;
    while(idx<n)
    {
      if((prevLocation+mid)<=arr[idx])
      {
        cnt++;
        prevLocation=arr[idx];
      }
      idx++;
    }
    if(cnt>=p)
    {
      ans=mid;
      l=mid+1;
    }
    else if(cnt<p)
    {
      r=mid-1;
    }
  }
  return ans;
}

int solveUsingLinearSearch(int arr[], int n, int p) // O(n*n)
{
  int ans=0;
  for(int i=0;i<(arr[n-1]-arr[0]);i++)
  {
    int prevLocation=arr[0];
    int cnt=1; int idx=1;
    while(idx<n)
    {
      if((prevLocation+i)<=arr[idx])
      {
        cnt++;
        prevLocation=arr[idx];
      }
      idx++;
    }
    if(cnt>=p)
    {
      ans=i;
    }
    else if(cnt<p)
    {
      break;
    }
  }
  return ans;
}

int main()
{
  int arr[]={1,2,4,8,9};int n=5;int b=3;
  cout<<solveUsingBinary(arr, n, b)<<endl; // O(nlogn)
  cout<<solveUsingLinearSearch(arr, n, b); // O(n*n)
  return 0;
}
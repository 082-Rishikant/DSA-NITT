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

int rotatedSearchUsingBinarySearch(int arr[], int n, int k)
{
  int l=0;int r=n-1;
  while(l<=r)
  {
    int mid=(l+r)/2;
    if(arr[mid]==k)
      return mid;
    // if mid lies on first Line
    else if(arr[l]<=arr[mid]) 
    {
      if(arr[l]<=k && k<=arr[mid-1])
        r=mid-1;
      else 
        l=mid+1;
    }
    // if mid lies on Second Line
    else if(arr[mid]<arr[r])
    {
      if(arr[mid+1]<=k && k<=arr[r])
        l=mid+1;
      else 
        r=mid-1;
    }
  }
  return -1;
}

int main()
{
  int arr[]={4,5,10,0,1,2,3};
  cout<<rotatedSearchUsingBinarySearch(arr, 7, 3);
  return 0;
}
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

int feqCount(int arr[], int idx, int k, int n)
{
  int count=1;
  int prev=idx-1;int next=idx+1;
  while(prev>=0)
  {
    if(arr[prev]==k)
    {
      count++;
      prev--;
    }
    else
      break;
  }
  while (next<n)
  {
    if(arr[next]==k)
    {
      count++;
      next++;
    }
    else  
      break;
  }
  return count;
}

int BinarySearch(int arr[], int n, int k)
{
  int l=0;int r=n-1;int ans=0;
  while(l<=r)
  {
    int mid=(l+r)/2;
    if(arr[mid]==k)
    {
      ans=feqCount(arr, mid, k, n);
      return ans;
    }
    else if(arr[mid]>k)
    {
      r=mid-1;
    }
    else if(arr[mid]<k)
    {
      l=mid+1;
    }
  }
  return ans;
}

int BinarySearchForFirstOccurence(int arr[], int n, int k)
{
  int l=0;int r=n-1;int ans=-1;
  while(l<=r)
  {
    int mid=(l+r)/2;
    if(arr[mid]==k)
    {
      ans=mid;
      r=mid-1;
    }
    else if(arr[mid]>k)
    {
      r=mid-1;
    }
    else if(arr[mid]<k)
    {
      l=mid+1;
    }
  }
  return ans;
}
int BinarySearchForLastOccurence(int arr[], int n, int k)
{
  int l=0;int r=n-1;int ans=-1;
  while(l<=r)
  {
    int mid=(l+r)/2;
    if(arr[mid]==k)
    {
      ans=mid;
      l=mid+1;
    }
    else if(arr[mid]>k)
    {
      r=mid-1;
    }
    else if(arr[mid]<k)
    {
      l=mid+1;
    }
  }
  return ans;
}

int mostOptimizedBinaryTech(int arr[], int n, int k)
{
  //But Atleast 1 element must be there otherwise this code wil wrong ans;
  int left=BinarySearchForFirstOccurence(arr, n, k);
  int right=BinarySearchForLastOccurence(arr, n, k);
  return (right-left+1);
}

int main()
{
  int arr[]={0,1,1,1,1,2,2,2,3,4,4,5,10};
  cout<<BinarySearch(arr, 13,2); // Average Case-O(logn) Worst Case-O(n)
  cout<<endl<<mostOptimizedBinaryTech(arr, 13, 2);
  return 0;
}
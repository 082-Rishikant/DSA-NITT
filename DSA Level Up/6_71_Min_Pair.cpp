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

int low_Bound(int el, int a[], int al)
{
  int l=0;int r=al-1;int idx=al-1;
  while(l<=r)
  {
    int mid=(l+r)/2;
    if(a[mid]==el)
      return mid;
    else if(a[mid]>el)
    {
      r=mid-1;
      idx=min(idx, mid);
    }
    else if(a[mid]<el)
    {
      l=mid+1;
    }
  }
  return idx;
}

pair<int, int> solve(int a[], int b[], int al, int bl)
{
  pair<int, int> ans={-1, -1};
  sort(a, a+al); int minD=INT_MAX;
  for(int i=0;i<bl;i++)
  {
    int idx=low_Bound(b[i], a, al);
    if(abs(a[idx]-b[i])<minD){
      minD=abs(a[idx]-b[i]);
      ans.first=a[idx];
      ans.second=b[i];
    }
    if(idx>0 && abs(a[idx-1]-b[i])<minD)
    {
      minD=abs(a[idx-1]-b[i]);
      ans.first=a[idx-1];
      ans.second=b[i];
    }
  }
  return ans;
}

int main()
{
  int a[]={5,1,7,25,25};int al=5;
  int b[]={-4,25,27,22};int bl=4;
  pair<int, int> ans=solve(a, b, al, bl);
  cout<<ans.first<<" "<<ans.second;
  return 0;
}
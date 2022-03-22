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

int quickSelect(int arr[], int l, int r, int k)
{
  if(l==r)
    return arr[r];
  int i=l;int j=l;
  while(i<r)
  {
    if(arr[i]<arr[r])
    {
      swap(arr[j], arr[i]);
      j++;
    }
    i++;
  }
  swap(arr[j], arr[i]);
  if(j==(k-1))
    return arr[j];
  else if(j>(k-1))
    return quickSelect(arr, l, j-1, k);
  else
    return quickSelect(arr, j+1, r, k);
}

int main()
{
  int arr[] = {0,5,2,3,1};
  int k=5; // k<-[1, N];
  // where N=size of array
  cout<<quickSelect(arr, 0, 4, k);
    return 0;
}
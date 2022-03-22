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

void quickSort(int arr[], int l, int r)
{
  if(l>=r)
    return;
  int i=l;int j=l;
  while(i<r)
  {
    if(arr[i]<arr[r])
    {
      int temp=arr[i];
      arr[i]=arr[j];
      arr[j]=temp;
      j++;
    }
    i++;
  }
  int temp=arr[r];
  arr[r]=arr[j];
  arr[j]=temp;
  quickSort(arr, l, j-1);
  quickSort(arr, j+1, r);
  return;
}

int main()
{
  int arr[] = {0,5,2,3,1};
  quickSort(arr, 0, 4);
  for(auto it:arr)
  {
    cout<<it<<" ";
  }
  return 0;
}
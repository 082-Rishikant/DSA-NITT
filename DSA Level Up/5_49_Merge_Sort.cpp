#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>

const int N = 1e9 + 7;
using namespace std;

void Merge(int arr[], int l, int mid, int r)
{
  int Larr[mid - l + 1];
  int j = 0;
  for (int i = l; i <= mid; i++)
  {
    Larr[j] = arr[i];
    // cout<<Larr[j]<<" ";
    j++;
  }
  int Rarr[r - mid];
  j = 0;
  for (int i = mid + 1; i <= r; i++)
  {
    Rarr[j] = arr[i];
    // cout<<Larr[j]<<" ";
    j++;
  }
  int i = 0;
  j = 0;
  int c = 0;
  while (i < (mid - l + 1) && j < (r - mid))
  {
    if (Larr[i] < Rarr[j])
    {
      arr[l + c] = Larr[i];
      i++;
    }
    else
    {
      arr[l + c] = Rarr[j];
      j++;
    }
    c++;
  }
  while (i < (mid - l + 1))
  {
    arr[l + c] = Larr[i];
    i++;
    c++;
  }
  while (j < (r - mid))
  {
    arr[l + c] = Rarr[j];
    j++;
    c++;
  }
}

void mergeSort(int arr[], int l, int r)
{
  if (l >= r)
    return;
  int mid = (l + r) / 2;
  mergeSort(arr, l, mid);
  mergeSort(arr, mid + 1, r);
  Merge(arr, l, mid, r);
  return;
}

int main()
{
  int arr[] = {19, 2923, 29, 0, 23, 2, 1, 3, 3, 90,23092};
  mergeSort(arr, 0, 10);
  // for (auto it : arr)
  // {
  //   cout << it << " ";
  // }
  for(int i=0;i<11;i++)
    cout<<arr[i]<<" ";
  return 0;
}
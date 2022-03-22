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

long long int Merge(long long int arr[], long long int l, long long int mid, long long int r)
{
  long long int inversion=0;
  long long int Larr[mid - l + 1];
  long long int j = 0;
  for (long long int i = l; i <= mid; i++)
  {
    Larr[j] = arr[i];
    // cout<<Larr[j]<<" ";
    j++;
  }
  long long int Rarr[r - mid];
  j = 0;
  for (long long int i = mid + 1; i <= r; i++)
  {
    Rarr[j] = arr[i];
    // cout<<Larr[j]<<" ";
    j++;
  }
  long long int i = 0;
  j = 0;
  long long int c = 0;
  while (i < (mid - l + 1) && j < (r - mid))
  {
    if (Larr[i] <= Rarr[j])
    {
      arr[l + c] = Larr[i];
      i++;
    }
    else
    {
      inversion=inversion+((mid - l)-i+1);
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
  return inversion;
}


long long int countinversion(long long int arr[], long long int l, long long int r)
{
  if (l >= r)
    return 0;
  long long int mid = (l + r) / 2;
  long long int li=countinversion(arr, l, mid);
  long long int ri=countinversion(arr, mid + 1, r);
  long long int ci=Merge(arr, l, mid, r);
  return (li+ri+ci);
}

int main()
{
  long long int arr[] = {0,5,2,3,1};
  cout<<"Number of inversion: "<<countinversion(arr, 0, 4)<<endl;
  return 0;
}
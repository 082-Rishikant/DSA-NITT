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

void merge(string arr[], int l, int mid, int r)
{
  // the basic idea is that Either "x"+"y" or "y"+"x" be lexicagraphically small
  string Larr[mid - l + 1];
  int j = 0;
  for (int i = l; i <= mid; i++)
  {
    Larr[j] = arr[i];
    j++;
  }
  string Rarr[r - mid];
  j = 0;
  for (int i = mid + 1; i <= r; i++)
  {
    Rarr[j] = arr[i];
    j++;
  }
  int i = 0;
  j = 0;
  int c = 0;
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
  while (i < (mid - l + 1) && j < (r - mid))
  {
    if (Larr[i] < Rarr[j])
    {
      if ((arr[l + c - 1] + Larr[i]) > (Larr[i] + arr[l + c - 1]))
      {
        string temp = arr[l + c - 1];
        arr[l + c - 1] = Larr[i];
        arr[l + c] = temp;
      }
      else
        arr[l + c] = Larr[i];
      i++;
    }
    else
    {
      if ((arr[l + c - 1] + Rarr[j]) > (Rarr[j] + arr[l + c - 1]))
      {
        string temp = arr[l + c - 1];
        arr[l + c - 1] = Rarr[j];
        arr[l + c] = temp;
      }
      else
        arr[l + c] = Rarr[j];
      j++;
    }
    c++;
  }
  while (i < (mid - l + 1))
  {
    if ((arr[l + c - 1] + Larr[i]) > (Larr[i] + arr[l + c - 1]))
    {
      string temp = arr[l + c - 1];
      arr[l + c - 1] = Larr[i];
      arr[l + c] = temp;
    }
    else
      arr[l + c] = Larr[i];
    i++;
    c++;
  }
  while (j < (r - mid))
  {
    if ((arr[l + c - 1] + Rarr[j]) > (Rarr[j] + arr[l + c - 1]))
      {
        string temp = arr[l + c - 1];
        arr[l + c - 1] = Rarr[j];
        arr[l + c] = temp;
      }
      else
        arr[l + c] = Rarr[j];
    j++;
    c++;
  }
}

void findSmallestString(string arr[], int l, int r)
{
  if (l >= r)
    return;
  int mid = (l + r) / 2;
  findSmallestString(arr, l, mid);
  findSmallestString(arr, mid + 1, r);
  merge(arr, l, mid, r);
  return;
}

bool comp(string a, string b)
{
  return (a+b)<(b+a);
}

int main()
{
  string arr[] = {"a", "ab", "aba"};
  int n=3;
  // 1st Method
  // findSmallestString(arr, 0, n-1);

  // 2nd Method
  // So here we will use our own custom comparetor
  sort(arr, arr+n, comp); 
  for (auto it : arr)
  {
    cout << it << " ";
  }
  return 0;
}
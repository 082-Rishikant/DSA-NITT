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

int sparseStr(string arr[], string s, int l, int r)
{
  if (l == r)
  {
    if (arr[l] == s)
      return (r + 1);
    else
      return -1;
  }
  if (l > r)
    return -1;
  int mid = (l + r) / 2;
  if (arr[mid] == "")
  {
    int prev = mid;
    int next = mid;
    while (true)
    {
      prev--;
      if (arr[prev] != "")
      {
        mid = prev;
        break;
      }
      next++;
      if (arr[next] != "")
      {
        mid = next;
        break;
      }
    }
  }
  if (arr[mid] == s)
    return (mid + 1);
  if (arr[mid] > s)
  {
    return sparseStr(arr, s, l, mid - 1);
  }
  else if (arr[mid] < s)
  {
    return sparseStr(arr, s, mid + 1, r);
  }
}

int sparseStrUsingWhileLoop(string arr[], string s, int l, int r)
{
  while (l <= r)
  {
    int mid = (l + r) / 2;
    if (arr[mid] == "")
    {
      int prev = mid;
      int next = mid;
      while (true)
      {
        prev--;
        if (arr[prev] != "")
        {
          mid = prev;
          break;
        }
        next++;
        if (arr[next] != "")
        {
          mid = next;
          break;
        }
      }
    }
    if (arr[mid] == s)
      return (mid + 1);
    if (arr[mid] > s)
    {
      r=mid-1;
    }
    else if (arr[mid] < s)
    {
      l=mid+1;
    }
  }
  return -1;
}

int main()
{
  string arr[] = {"aat", "", "", "bat", "", "nat", "", "", "sat", "", "", "tat"};
  // Average TC=O(logn) && Worst TC=O(n)
  cout << sparseStr(arr, "oat", 0, 11)<<endl;
  cout << sparseStrUsingWhileLoop(arr, "oat", 0, 11);
  return 0;
}
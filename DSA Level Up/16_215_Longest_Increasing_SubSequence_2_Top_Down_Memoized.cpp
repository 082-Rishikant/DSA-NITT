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
int *t;

int longestIncSeq(int arr[], int n, int curr, int next)
{
  if (next == n)
    return 1;
  if (t[curr] != -1)
    return t[curr];

  if (arr[curr] < arr[next])
  {
    return t[curr] = max(longestIncSeq(arr, n, next, next + 1) + 1, longestIncSeq(arr, n, curr, next + 1));
  }

  return t[curr] = longestIncSeq(arr, n, curr, next + 1);
}

// Function to find length of longest increasing subsequence.
int longestSubsequence(int n, int arr[])
{
  t = new int[n];
  for (int i = 0; i < n; i++)
  {
    t[i] = -1;
  }

  for (int i = 0; i < n; i++)
  {
    t[i] = longestIncSeq(arr, n, i, i + 1);
  }

  int maxi = 1;
  for (int i = 0; i < n; i++)
  {
    maxi = max(maxi, t[i]);
  }

  return maxi;
}

int main()
{
  int arr[] = {50, 4, 10, 8, 30, 100};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << longestSubsequence(n, arr);

  return 0;
}
// Passed all test cases on GFG
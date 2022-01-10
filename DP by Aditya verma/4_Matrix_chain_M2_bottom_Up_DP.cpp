#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <cstring>

const int N = 1e9 + 7;
using namespace std;

int t[101][101];

int solve(int arr[], int i, int j)
{
  if (i >= j)
  {
    return t[i][j] = 0;
  }
  if (t[i][j] != -1)
  {
    return t[i][j];
  }
  int mini = INT_MAX;
  for (int k = i; k < j; k++)
  {
    int temp = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
    mini = min(mini, temp);
  }
  return t[i][j] = mini;
}

int main()
{
  memset(t, -1, sizeof(t));
  int arr[] = {10, 30, 5, 60};
  int n = 4;
  cout << solve(arr, 1, n - 1);
  return 0;
}
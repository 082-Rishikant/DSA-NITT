#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>

const int N = 1e4 + 7;
int t[N + 1][N + 1];

using namespace std;

void rodCutting(int len[], int val[], int n, int length)
{
  // base case initialization of matrix
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= length; j++)
    {
      if (i == 0 || j == 0)
        t[i][j] = 0;
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= length; j++)
    {
      if (len[i - 1] <= j)
      {
        t[i][j] = max(t[i][j - len[i - 1]] + val[i - 1], t[i - 1][j]);
      }
      else
      {
        t[i][j] = t[i - 1][j];
      }
    }
  }

  return;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  memset(t, -1, sizeof(t));

  int len[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int n = sizeof(len) / sizeof(len[0]);
  int val[] = {3, 5, 8, 9, 10, 17, 17, 20};
  int length = 8;

  rodCutting(len, val, n, length);
  cout << t[n][length];

  return 0;
}
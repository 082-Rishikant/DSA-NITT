#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

const int N = 1e9 + 7;
using namespace std;

int minimumNumberOfDeletions(string x)
{
  int n = x.size();
  string y = x;
  reverse(y.begin(), y.end());
  int t[n + 1][n + 1];
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      if (i == 0 || j == 0)
        t[i][j] = 0;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (x[i - 1] == y[j - 1])
      {
        t[i][j] = 1 + t[i - 1][j - 1];
      }
      else
      {
        t[i][j] = max(t[i - 1][j], t[i][j - 1]);
      }
    }
  }
  return n - t[n][n];
}

int main()
{
  // cout<<minimumNumberOfDeletions("agbcba");
  cout<<minimumNumberOfDeletions("bbbab");
  return 0;
}
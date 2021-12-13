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

int longestCommonSubstr(string x, string y, int m, int n)
{
  int maxi = 0;
  int t[m + 1][n + 1];
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= n; j++)
      if (i == 0 || j == 0)
        t[i][j] = 0;

  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (x[i - 1] == y[j - 1])
      {
        t[i][j] = 1 + t[i - 1][j - 1];
        maxi = max(maxi, t[i][j]);
      }
      else
        t[i][j] = 0;
    }
  }
  return maxi;
}

int main()
{
  string x = "ABCDGH", y = "ACDGHR";
  // string x = "ABC", y = "ACB";
  int m=x.length(), n=y.length();
  cout<<longestCommonSubstr( x,  y,  m,  n);
  return 0;
}
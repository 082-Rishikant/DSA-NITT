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

int lcs(int m, int n, string x, string y)
{
  int t[m + 1][n + 1];
  memset(t, -1, sizeof(t));
  if (m == 0 || n == 0)
    return t[m][n] = 0;
  else if (t[m][n] != -1)
    return t[m][n];
  else if (x[m - 1] == y[n - 1])
  {
    return t[m][n] = 1 + lcs(m - 1, n - 1, x, y);
  }
  else
  {
    return t[m][n] = max(lcs(m, n - 1, x, y), lcs(m - 1, n, x, y));
  }
}

int main()
{
  // int m = 6, n = 6;
  // string x = "ABCDGH";
  // string y = "AEDFHR";
  int m = 3, n = 2;
  string x = "ABC";
  string y = "AC";
  cout<<lcs(m,n,x,y);
  return 0;
}
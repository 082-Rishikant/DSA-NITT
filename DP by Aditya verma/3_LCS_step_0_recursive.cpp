#include<iostream>
#include<vector>
#include <algorithm>
#include<string.h>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>

const int N=1e9+7;
using namespace std;

int lcsRecursive(int m, int n, string x, string y)
{
  if (m == 0 || n == 0)
    return 0;
  else if (x[m - 1] == y[n - 1])
  {
    return 1 + lcsRecursive(m - 1, n - 1, x, y);
  }
  else
  {
    return max(lcsRecursive(m, n - 1, x, y), lcsRecursive(m - 1, n, x, y));
  }
}

int main()
{
  int m = 6, n = 6;
  string x = "ABCDGH";
  string y = "AEDFHR";
  // int m = 3, n = 2;
  // string x = "ABC";
  // string y = "AC";
  cout<<lcsRecursive(m,n,x,y);
  return 0;
}
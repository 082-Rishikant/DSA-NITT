#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include<climits>

const int N = 1e9 + 7;
using namespace std;

int t[501][501];
bool isPalindrome(string s, int i, int j)
{
  while (i < j)
  {
    if (s[i] != s[j])
    {
      return false;
    }
    i++;
    j--;
  }
  return true;
}

int solve(string s, int i, int j)
{
  if (i >= j)
    return t[i][j] = 0;
  else if (t[i][j] != -1)
    return t[i][j];
  else if (isPalindrome(s, i, j))
    return t[i][j] = 0;
  else
  {
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
      int left, right;
      if (t[i][k] != -1)
        left = t[i][k];
      else
        left = solve(s, i, k);

      if (t[k + 1][j] != -1)
        right = t[k + 1][j];
      else
        right = solve(s, k + 1, j);

      int temp = left + right + 1;
      ans = min(ans, temp);
    }
    return t[i][j] = ans;
  }
}

int main()
{
  memset(t, -1, sizeof(t));
  string str = "nitik";
  cout << solve(str, 0, str.size() - 1);
  return 0;
}
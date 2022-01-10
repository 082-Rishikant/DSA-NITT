#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <cmath>

const int N = 1e9 + 7;
using namespace std;

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
    return 0;
  else if (isPalindrome(s, i, j))
    return 0;
  else
  {
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
      int temp = solve(s, i, k) + solve(s, k + 1, j) + 1;
      ans = min(ans, temp);
    }
    return ans;
  }
}

int main()
{
  cout << solve("nitik", 0, 4);
  return 0;
}
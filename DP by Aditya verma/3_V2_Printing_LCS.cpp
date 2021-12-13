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

vector<int> longestCommonSubsequence(vector<int> a, vector<int> b)
{
  vector<int> ans;
  int m = a.size();
  int n = b.size();
  int t[m + 1][n + 1];
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= n; j++)
      if (i == 0 || j == 0)
        t[i][j] = 0;

  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (a[i - 1] == b[j - 1])
      {
        t[i][j] = t[i - 1][j - 1] + 1;
      }
      else
      {
        t[i][j] = max(t[i - 1][j], t[i][j - 1]);
      }
    }
  }
  int i = m, j = n;
  while (i && j)
  {
    if (a[i - 1] == b[j - 1])
    {
      ans.push_back(a[i - 1]);
      i--;
      j--;
    }
    else
    {
      if (t[i][j - 1] > t[i - 1][j])
      {
        j--;
      }
      else
      {
        i--;
      }
    }
  }
  int l = ans.size();
  for (int i = 0; i < l / 2; i++)
  {
    swap(ans[i], ans[l - 1 - i]);
  }
  return ans;
}

int main()
{
  vector<int> a={1, 2, 3, 4, 1};
  vector<int> b={3, 4, 1, 2, 1, 3};  
  vector<int> ans=longestCommonSubsequence(a,b);
  for(auto it:ans) cout<<it<<" ";
  return 0;
}
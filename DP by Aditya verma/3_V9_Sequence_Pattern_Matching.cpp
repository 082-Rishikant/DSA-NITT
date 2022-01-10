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

bool sequencePatternMatching(string x, string y)
{
  int m=x.size();int n=y.size();
  int t[m + 1][n + 1];
  memset(t, -1, sizeof(t));

  // intialization of tha matrix
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= n; j++)
      if (i == 0 || j == 0)
        t[i][j] = 0;

  // fullfill the rest matrix
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (x[i - 1] == y[j - 1]) // if last chars are equal
        t[i][j] = 1 + t[i - 1][j - 1];
      else // if last chars not equal
        t[i][j] = max(t[i - 1][j], t[i][j - 1]);
    }
  }

  //return the final result
  return t[m][n]==m;
}

int main()
{
  cout<<sequencePatternMatching("AXY", "ADXCPY")<<endl;
  cout<<sequencePatternMatching("axb", "axmk");
  return 0;
}
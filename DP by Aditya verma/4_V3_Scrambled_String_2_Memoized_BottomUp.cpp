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

unordered_map<string, bool> mp;
bool isScramble(string s1, string s2)
{
  if (s1.size() < 1)
  {
    return false;
  }
  if (s1.compare(s2) == 0)
  {
    return true;
  }
  string key = s1 + "_" + s2;
  if (mp.find(key) != mp.end())
    return mp[key];
  else
  {
    int n = s1.size();
    for (int k = 1; k < n; k++)
    {
      if ((isScramble(s1.substr(0, k), s2.substr(n - k, k)) && isScramble(s1.substr(k, n - k), s2.substr(0, n - k))) || (isScramble(s1.substr(0, k), s2.substr(0, k)) && isScramble(s1.substr(k, n - k), s2.substr(k, n - k))))
      {
        return mp[key] = true;
      }
    }
    return mp[key] = false;
  }
}
int main()
{
  // string s1 = "abcde", s2 = "caebd";
  string s1 = "great", s2 = "rgeat";
  cout << isScramble(s1, s2);
  return 0;
}
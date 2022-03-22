#include <iostream>
#include <unordered_map>
#include <queue>

const int N = 1e9 + 7;
using namespace std;

void firstNonrep_char(string s)
{
  int l = s.length();
  int i = 0;
  queue<char> q;
  unordered_map<char, int> mp;
  while (i < l)
  {
    if (mp.find(s[i]) == mp.end())
    {
      q.push(s[i]);
      mp[s[i]] = 1;
    }
    else
      mp[s[i]]++;

    // Find NonRepeated elemant
    if (!q.empty() && mp[q.front()] > 1)
      while (mp[q.front()] > 1)
        q.pop();

    // store in the ans vector
    if (!q.empty())
      cout<<q.front();
    else
      cout<<-1;
    i++;
  }
  return;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  string s;
  cin >> s;
  firstNonrep_char(s);
  return 0;
}
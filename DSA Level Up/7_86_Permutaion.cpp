#include<iostream>
#include<vector>
#include <algorithm>
#include<string.h>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<climits>

const int N=1e9+7;
using namespace std;

void solve(string s, int l, int r)
{
  if(l>=r)
  {
    cout<<s<<" ";
    return;
  }
  for(int i=l;i<=r;i++)
  {
    swap(s[l], s[i]);
    solve(s, l+1, r);
  }
  return;
}

void solve2(string s2)
{
  s2="Rishi";
  cout<<s2<<endl;
}

int main()
{
  string s="abc";
  solve(s, 0, s.length()-1);
  // string s2="Patel";
  // cout<<s2<<endl;
  // solve2(s2);
  // cout<<s2<<endl;
  return 0;
}
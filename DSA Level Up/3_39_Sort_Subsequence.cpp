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
vector<string> ans;

void solve(string input, string output, int curr, int n)
{
  if(curr==n)
  {
    ans.push_back(output);
    return;
  }
  solve(input, output, curr+1, n);
  solve(input, output+input[curr], curr+1, n);
}

bool comp(string s1, string s2)
{
  if(s1.length()<s2.length())
  {
    return true;
  }
  else if(s1.length()==s2.length())
  {
    if(s1<s2)
      return true;
    else  
      return false;
  }
  else 
  {
    return false;
  }
}

int main()
{
  string s="abcd";
  solve(s, "", 0, 4);
  sort(ans.begin(), ans.end(), comp);
  for(auto it:ans)
  {
    cout<<it<<" ";
  }
  return 0;
}
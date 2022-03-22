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

string solve(string s1, string s2)
{
  int m=s1.size();int n=s2.size();
  if(m<n)
  {
    swap(s1, s2);
  }
  m=s1.size();n=s2.size();
  int i=0,j=0;
  while(i<m && j<n)
  {
    if(s1[i]==s2[j])
    {
      if(j==(n-1))
        return "Yes";
      i++;j++;
    }
    else
    {
      i++;
    }
  }
  return "No";
}

int main()
{
  string s1="codingminuts";string s2="diyus";
  cout<<solve(s1, s2);
    return 0;
}
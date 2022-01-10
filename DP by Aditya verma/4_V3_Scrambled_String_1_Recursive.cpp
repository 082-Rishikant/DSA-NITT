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

bool solve(string s1, string s2)
{
  if(s1.size()<1)
    return false;
  if(s1.compare(s2)==0)
    return true;
  else
  {
    int n=s1.size();
    for(int k=1;k<n;k++)
    {
      if((solve(s1.substr(0, k), s2.substr(n-k, k)) && solve(s1.substr(k, n-k), s2.substr(0, n-k))) 
      || (solve(s1.substr(0, k), s2.substr(0, k)) && solve(s1.substr(k, n-k), s2.substr(k, n-k))))
      {
        return true;
      }
    }
    return false;
  }
}

int main()
{
  string s1="great",s2="rgaet";
  if(s1.size()!=s2.size())
    cout<<0;
  else if(s1.size()==0)
    cout<<1;
  else
    cout<<solve(s1, s2);
  return 0;
}
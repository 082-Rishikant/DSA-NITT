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

int solve(string s, int i, int j, bool isTrue)
{
  if(i>j)
  {
    return 0;
  }
  else if(i==j)
  {
    if(isTrue==true && s[i]=='T')
      return 1;
    else if(isTrue==false && s[i]=='F')
      return 1;
    else
      return 0;
  }
  else
  {
    int ans=0;
    for(int k=i;k<=j-2;k=k+2)
    {
      int lt=solve(s, i, k, true);
      int lf=solve(s, i, k, false);
      int rt=solve(s, k+2, j, true);
      int rf=solve(s, k+2, j, false);
      if(s[k+1]=='&')
      {
        if(isTrue)
          ans=ans+lt*rt;
        else
          ans=ans+lf*rf+lf*rt+lt*rf;
      }
      else if(s[k+1]=='|')
      {
        if(isTrue)
          ans=ans+lt*rt+lt*rf+lf*rt;
        else
          ans=ans+lf*rf;
      }
      else if(s[k+1]=='^')
      {
        if(isTrue)
          ans=ans+lt*rf+lf*rt;
        else
          ans=ans+lf*rf+lt*rt;
      }
    }
    return ans;
  }
}

int main()
{
  cout<<solve("T|T&F^T", 0, 6, true);
  return 0;
}
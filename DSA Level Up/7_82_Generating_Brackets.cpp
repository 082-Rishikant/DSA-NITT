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

void geberateBrackets(string opening, string closing, int o, int c, string op)
{
  if(o==0 && c==0)
  {
    cout<<op<<" ";
    return;
  }
  else if(o==0)
  {
    op=op+closing.substr(0, c);
    cout<<op<<" ";
    return;
  }
  else{
    if(c>o)
    {
      geberateBrackets(opening, closing, o, c-1, op+")");
    }
    geberateBrackets(opening, closing, o-1, c, op+"(");
    return;
  }
}

int main()
{
  int n;
  string opening="(((";
  string closing=")))";
  n=opening.size();
  geberateBrackets(opening, closing, n, n, "");
  return 0;
}
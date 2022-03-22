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

int solve(int n)
{
  if(n==0)
    return 1;
  if(n==1)
    return 1;
  if(n==2)
    return 2;
  else
  {
    return solve(n-1)+solve(n-2)+solve(n-3);
  }
  
}

int main()
{
  cout<<solve(4);
  return 0;
}
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

void solve(string ip, string op, int n)
{
  if(n==0)
  {
    cout<<op<<"  ,";
    return;
  }
  solve(ip, ip[n-1]+op, n-1);
  solve(ip, op, n-1);
  return;
}
int main()
{
  solve("abs", "", 3);
  return 0;
}
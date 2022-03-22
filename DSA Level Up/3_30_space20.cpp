#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>

const int N = 1e9 + 7;
using namespace std;

string gen_OP(string s)
{
  int idxOf_space=s.find(" ");
  while(idxOf_space!=-1)
  {
    string s1=s.substr(0, idxOf_space);
    s1=s1.append("%20");
    s1=s1.append(s.substr(idxOf_space+1));
    s=s1;
    idxOf_space=s.find(" ", idxOf_space+1);
  }
  return s;
}

int main()
{
  string s;
  getline(cin,s);
  cout<<gen_OP(s);
  return 0;
}
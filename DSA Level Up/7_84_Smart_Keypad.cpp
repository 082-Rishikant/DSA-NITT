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
unordered_map<int, string> mp;

void genKeypadPermu(int n, string op)
{
  if (n == 0)
  {
    cout << op << " ";
    return;
  }
  int temp = n % 10;
  n = n / 10;
  string ip = mp[temp];
  if (ip.length() != 0)
  {
    for (int i = 0; i < ip.length(); i++)
    {
      genKeypadPermu(n, op + ip[i]);
    }
  }
  else
    genKeypadPermu(n, op);
  return;
}

int main()
{
  mp = {{0, ""}, {1, ""}, {2, "ABC"}, {3, "DEF"}, {4, "GHI"}, {5, "JKL"}, {6, "MNO"}, {7, "PQRS"}, {8, "TUV"}, {9, "WXYZ"}};
  int n = 230014;
  genKeypadPermu(n, "");
  return 0;
}
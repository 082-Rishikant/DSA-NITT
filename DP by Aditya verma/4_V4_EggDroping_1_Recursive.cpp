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

int eggDrop(int e, int f)
{
  if (e == 1 || f == 1 || f == 0)
    return f;
  else
  {
    int ans = INT_MAX;
    for (int k = 1; k < f; k++)
    {
      int temp = 1 + max(eggDrop(e - 1, k - 1), eggDrop(e, f - k));
      ans = min(ans, temp);
    }
    return ans;
  }
}

int main()
{
  cout << eggDrop(1, 2)<<endl;
  cout << eggDrop(2, 10);
  return 0;
}
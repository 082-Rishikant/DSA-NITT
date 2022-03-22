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
int *t;
int maxi=1;

void longestIncSeq(vector<int> arr, int n)
{
  t = new int[n];
  for (int i = 0; i < n; i++)
  {
    t[i] = 1;
  }

  for (int i = (n - 2); i >= 0; i--)
  {
    for (int j = i+1; j < n; j++)
    {
      if (arr[i] < arr[j])
      {
        t[i] += t[j];
        maxi=max(maxi, t[i]);
        break;
      }
    }
  }
  return;
}

int main()
{
  vector<int> arr = {50, 4, 10, 8, 30, 100};
  int n = arr.size();

  longestIncSeq(arr, n);
  cout << maxi;

  return 0;
}
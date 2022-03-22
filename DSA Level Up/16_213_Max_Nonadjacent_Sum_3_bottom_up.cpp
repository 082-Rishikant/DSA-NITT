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

void maxNonadjacentSum(vector<int> arr, int n, int curr)
{ //base case
  t[0]=arr[0];
  t[1]=max(arr[0], arr[1]);

  for (int i = 2; i < n; i++)
  {
    t[i]=max(t[i-2]+arr[i], t[i-1]);
  }

  return;
}

int main()
{

  vector<int> arr = {6, 10, 12, 7, 9, 14};
  int n = arr.size();

  t = new int[n];
  for (int i = 0; i < n; i++)
  {
    t[i] = -1;
  }

  maxNonadjacentSum(arr, n, 0);
  cout << t[n-1];

  return 0;
}
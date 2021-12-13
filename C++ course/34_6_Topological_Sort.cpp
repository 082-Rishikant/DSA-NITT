#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
int main()
{
  int n, e;
  cin >> n >> e;
  map<int, int> in_deg;
  for (int i = 0; i <= n; i++)
  {
    in_deg[i] = 0;
  }

  vector<int> adjL[n + 1];
  for (int i = 0; i < e; i++)
  {
    int x;
    int y;
    cin >> x >> y;
    in_deg[y]++;
    adjL[x].push_back(y);
  }
  queue<int> q;
  for (int i = 1; i <= n; i++)
  {
    if (in_deg[i] == 0)
    {
      q.push(i);
    }
  }
  while (!q.empty())
  {
    int d = q.front();
    cout << d << " ";
    q.pop();
    for (int it : adjL[d])
    {
      in_deg[it]--;
      if (in_deg[it] == 0)
      {
        q.push(it);
      }
    }
  }

  return 0;
}
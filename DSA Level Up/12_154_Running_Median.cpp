#include <iostream>
#include <queue>
using namespace std;

void solve(int n)
{
  priority_queue<int> maxh;
  priority_queue<int, vector<int>, greater<int>> minh;
  float median = 0;
  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    if (temp > median)
    {
      //  push into minheap
      if (minh.size() > maxh.size())
      {
        int ele = minh.top();
        minh.pop();
        maxh.push(ele);
      }
      minh.push(temp);
    }
    else
    {
      //  push into maxheap
      if (maxh.size() > minh.size())
      {
        int ele = maxh.top();
        maxh.pop();
        minh.push(ele);
      }
      maxh.push(temp);
    }
    if (minh.size() == maxh.size())
    {
      median = (minh.top() + maxh.top()) / (float)2;
    }else if(minh.size()>maxh.size()){
      median = minh.top();
    }else{
      median = maxh.top();
    }
    cout<<median<<" ";
  }
  return;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  solve(n);
  return 0;
}
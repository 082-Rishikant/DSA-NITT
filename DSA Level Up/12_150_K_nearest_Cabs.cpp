#include<iostream>
#include<queue>
using namespace std;

void solve(pair<string, pair<int, int>> arr[], int n, int k)
{
  priority_queue<pair<int, string>> p;
  //Other way also there by using the min heap 
  // But this more optimized 
  for(int i=0;i<k;i++)
  {
    int x=arr[i].second.first; int y=arr[i].second.second;
    int temp=x*x+y*y;
    p.push({temp, arr[i].first});
  }
  for(int i=k;i<n;i++)
  {
    int x=arr[i].second.first; int y=arr[i].second.second;
    int temp=x*x+y*y;
    if(temp<p.top().first)
    {
      p.pop();
      p.push({temp, arr[i].first});
    }
  }
  while (!p.empty())
  {
    cout<<p.top().second<<endl;
    p.pop();
  }// We may also need to reverse the output
  return;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;  cin>>n;
  int k;  cin>>k;
  pair<string, pair<int, int>> arr[n];
  for(int i=0;i<n;i++)
  {
    string s; int t1,t2;
    cin>>s>>t1>>t2;
    arr[i]={s, {t1, t2}};
  }
  solve(arr, n, k);
  // for(auto it:arr)
  //   cout<<it.first<<"=>"<<it.second.first<<" "<<it.second.second<<endl;
  
  return 0;
}
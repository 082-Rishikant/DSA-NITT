#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2)
{
  if (p1.second < p2.second)
    return true;
  else
    return false;
}

int main()
{
  int n;
  cin >> n;
  vector<pair<int, int>> vec;
  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    vec.push_back(make_pair(a, b));
  }
  sort(vec.begin(), vec.end(), comp);
  int ans = 1;

  // int i=0;
  // while(i<vec.size())
  // {
  //   int j=i+1;
  //   while(vec[i].second>vec[j].first)
  //   {
  //     if(j>=vec.size()){
  //       cout<<ans;
  //       return 0;
  //     }
  //     j++;
  //   }
  //   i=j;
  //   ans++;
  // }


  // Best way of Code
  int end=vec[0].second;
  for (int i = 1; i < vec.size(); i++)
  {
    if(vec[i].first>=end)
    {
      ans++;
      end=vec[i].second;
    }
  }
  cout << ans;
  return 0;
}
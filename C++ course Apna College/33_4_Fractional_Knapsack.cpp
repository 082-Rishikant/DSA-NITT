#include<iostream>
#include<vector>
#include<algorithm>
// #include<map>
using namespace std;
bool comp(pair<int, int> p1, pair<int, int> p2)
{
  return (p1.first>p2.first);
}
int main()
{
  int ans=0;
  vector<pair<int, int>> mp;
  int n, X;
  cin>>n>>X;
  for(int i=0;i<n;i++)
  {
    float price; 
    int weight;
    cin>>price>>weight;
    price=price/weight;
    mp.push_back({price, weight});
  }
  sort(mp.begin(), mp.end(), comp);
  for(pair<int, int> item:mp)
  {
    if(X<item.second)
    {
      ans+=X*item.first;
      X=0;
      break;
    }
    else
    {
      ans+=item.first*item.second;
      X=X-item.second;
    }
  }
  cout<<ans;
}
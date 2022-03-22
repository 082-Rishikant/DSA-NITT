#include <iostream>
#include <unordered_map>
#include<unordered_set>
#include<set>
using namespace std;

void solveWithPoints(unordered_multimap<int, int> points, int & ans)
{
  set<pair<int, int>> st;
  unordered_map<int, int> x_axis;
  unordered_map<int, int> y_axis;
  for(auto it:points)
  {
    st.insert({it.first, it.second});

    if(x_axis.find(it.first)==x_axis.end())
      x_axis[it.first]=1;
    else  
      x_axis[it.first]++;

    if(y_axis.find(it.second)==y_axis.end())
      y_axis[it.second]=1;
    else  
      y_axis[it.second]++;
  }

  for(auto p1=st.begin(); p1!=st.end(); p1++)
  {
     int x=x_axis[p1->first]-1;
     int y=y_axis[p1->second]-1;

     ans=ans+x*y;
  }
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  unordered_multimap<int, int> points = {{1, 2}, {2, 0}, {2, 2}, {2, 3}, {4, 2}, {4, 3}};

  int ans=0;

  solveWithPoints(points, ans);
  
  cout<<(ans)<<endl; // O(nlogn)
  return 0;
}
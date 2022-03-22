#include <iostream>
#include <unordered_map>
#include<unordered_set>
#include<set>
using namespace std;

int fact(int n)
{
  int ans=1;
  if(n==0)
    return ans;
  for(int i=1;i<=n;i++)
    ans=ans*i;
  return ans;
}

void solveForGivenLines(unordered_multimap<int, int> points, int &ans)
{
  int n=points.size();
  unordered_map<int, int> arrEqualX;
  unordered_map<int, int> arrEqualY;

  // all points with equal x-axis 
  for(auto it:points)
  {
    if(arrEqualX.find(it.first)==arrEqualX.end())
      arrEqualX[it.first]=1;
    else  
      arrEqualX[it.first]++;
  }

  // all points with equal y-axis 
  for(auto it:points)
  {
    if(arrEqualY.find(it.second)==arrEqualY.end())
      arrEqualY[it.second]=1;
    else  
      arrEqualY[it.second]++;
  }
  
  // #Lines those are parrallel to x-axis
  int linesParallel_To_X_axis=0;
  for(auto it:arrEqualX)
  {
    if(it.second>1)
      linesParallel_To_X_axis++;
  }
  // #Lines those are parrallel to y-axis
  int linesParallel_To_Y_axis=0;
  for(auto it:arrEqualY)
  {
    if(it.second>1)
      linesParallel_To_Y_axis++;
  }

  if(linesParallel_To_X_axis<2 || linesParallel_To_Y_axis<2)
    return;

  int temp1=fact(linesParallel_To_X_axis)/(fact(linesParallel_To_X_axis-2)*2);
  int temp2=fact(linesParallel_To_Y_axis)/(fact(linesParallel_To_Y_axis-2)*2);
  
  ans=temp1*temp2;
  return;
}

void solveForGivenPoints(unordered_multimap<int, int> points, int &ans)
{
  set<pair<int, int>> st;
  for(auto it:points)
    st.insert({it.first, it.second});
  
  for(auto p1=st.begin();p1!=prev(st.end());p1++)
  {
    for(auto p3=next(p1);p3!=st.end();p3++)
    {
      if(p1->first==p3->first || p1->second==p3->second)
        continue;
      pair<int, int> p2={p3->first, p1->second};
      pair<int, int> p4={p1->first, p3->second};
      if(st.find(p2)==st.end() && st.find(p4)==st.end())
        continue;
      ans++;
    }
  }
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  unordered_multimap<int, int> points = {{0, 0}, {0, 1}, {1, 1}, {1, 0}, {2, 1}, {2, 0}, {3, 0}, {3, 1}};

  int ans=0;

  // solveForGivenLines(points, ans);  // O(n)
  // cout<<ans<<endl;

  solveForGivenPoints(points, ans);  // O(n*n*logn)
  cout<<(ans/2)<<endl;
  return 0;
}
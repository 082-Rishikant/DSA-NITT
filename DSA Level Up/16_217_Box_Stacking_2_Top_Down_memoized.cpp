#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int *t;

int boxStack(vector<vector<int>> boxes, int n, int curr, int next)
{
  if(next==n)  
    return 0;
  if(t[curr]!=-1)
    return t[curr];
  
  if(boxes[curr+1][0]<boxes[curr][0] && boxes[curr+1][1]<boxes[curr][1]){
    if(t[next]==-1)
      t[next]=boxStack(boxes, n, next, next+1);
    return t[curr]=max(t[next]+boxes[next][2], boxStack(boxes, n, curr, next+1));
  }

  return t[curr]=boxStack(boxes, n, curr, next+1);
}

bool comp(vector<int> vec1, vector<int> vec2)
{
  if (vec1[2] > vec2[2])
    return true;
  else if(vec1[2] == vec2[2])
    if(vec1[1]>vec2[1] && vec1[0]>vec2[0])
      return true;

  return false;
}

int main()
{
  vector<vector<int>> boxes = {{2, 1, 2}, {3, 2, 3}, {2, 2, 8}, {2, 3, 4}, {2, 2, 1}, {4, 4, 5}};
  sort(boxes.begin(), boxes.end(), comp);

  int n = boxes.size(); int maxi=0;
  t=new int[n];
  for(int i=0;i<n;i++)
    t[i]=-1;

  for(int i=0;i<n;i++)
    maxi=max(maxi, boxStack(boxes, n, i, i+1)+boxes[i][2]);

  cout<<maxi;
  return 0;
}
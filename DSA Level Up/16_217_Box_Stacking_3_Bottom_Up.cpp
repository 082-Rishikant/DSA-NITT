#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int *t;

void boxStack(vector<vector<int>> boxes, int n)
{
  for(int i=n-2;i>=0;i--){
    int maxi=t[i];
    for(int j=i+1;j<n;j++){
      if(boxes[i][0]>boxes[j][0] && boxes[i][1]>boxes[j][1]){
        maxi=max(t[j]+boxes[i][2], maxi);
      }
    }
    t[i]=maxi;
  }
  
  return;
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

  int n = boxes.size();
  t=new int[n];
  for(int i=0;i<n;i++)
  {
    t[i]=boxes[i][2];
    // cout<<boxes[i][2]<<" ";
  }
  // cout<<endl;

  
  boxStack(boxes, n);
  int maxi=0;
  for(int i=0;i<n;i++)
    maxi=max(maxi, t[i]);
    // cout<<t[i]<<" ";

  cout<<maxi;
  return 0;
}
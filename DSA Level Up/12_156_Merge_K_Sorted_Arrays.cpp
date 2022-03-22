#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, pair<int, int>> pi;

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  vector<int> ans;
  priority_queue<pi, vector<pi>, greater<pi>> minh;
  
  vector<vector<int>> vec={{1,3,5}, {2,4,6}, {0,9,10,11}};

  // pair={element, {index, arrayNo.}}
  int k=vec.size();
  for(int i=0;i<k;i++){
    minh.push({vec[i][0], {0, i}});
  }

  while(minh.size()!=0){
    pi p=minh.top();
    int ele=p.first;
    int idx=p.second.first;
    int arrNo=p.second.second;
    ans.push_back(ele);
    minh.pop();
    idx++;
    if(idx<vec[arrNo].size()){
      minh.push({vec[arrNo][idx], {idx, arrNo}});
    }
  }
  for(auto it:ans){
    cout<<it<<" ";
  }
  return 0;
}
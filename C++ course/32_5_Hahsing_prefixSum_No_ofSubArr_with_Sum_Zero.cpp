#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main()
{
  /*int ans=0;
  int n=6;
  int arr[n]={1, -1, 1, -1, 1,-1};
  int preSum[n+1]={0};
  int hsh[100]={0};
  for(int i=0;i<6;i++)
  {
    preSum[i+1]=arr[i]+preSum[i];
    hsh[preSum[i]]++;
  }
  hsh[0]+=1;
  for(int i=0;i<100;i++)
  {
    ans=ans+hsh[i]*(hsh[i]-1)/2;
  }
  cout<<ans;*/


  // Best way
  int ans=0;
  vector<int> vec={1, -1, 1, -1, 1, -1};
  int preSum=0; 
  unordered_map<int, int> hsh;
  hsh[0]=1;
  for(int item:vec)
  {
    preSum+=item;
    hsh[preSum]++;
  }
  for(pair<int, int> p:hsh)
  {
    ans+=p.second*(p.second-1)/2;
  }
  cout<<ans;
  return 0;
}
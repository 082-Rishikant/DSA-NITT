#include<iostream>
#include<vector>
using namespace std;
const int N=1e6+2;

vector<int> solve(int arr[], int n)  
{
  vector<int> ans;
  vector<int> hsh(N, 0);;
  for(int i=0;i<n;i++)
  {
    hsh[arr[i]]++;
  }
  for(int i=0;i<N;i++)
  {
    if(hsh[i]>1)
      ans.push_back(i);
  }
  if(ans.size()==0)
    return {-1};
  return ans;
}

int main()
{
  int arr[]={4,4,7,7,7,1,1,8,8,9};
  int n=sizeof(arr)/sizeof(arr[0]);
  vector<int> ans=solve(arr, n);
  for(auto it:ans)
    cout<<it<<" ";
  return 0;
}
#include<iostream>
using namespace std;

void solve(int arr[], int n, int r, int &ans)
{
  int ltor[100]={0};
  int rtol[100]={0};
  for(int i=0;i<n;i++)
  {
    rtol[arr[i]]++;
  }
  for(int i=0;i<n;i++)
  {
    int a=arr[i];
    rtol[a]--;
    if(a%r==0){
      ans+=ltor[a/r]*rtol[a*r];
    }
    ltor[a]++;
  }
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;  cin>>n;
  int r;  cin>>r;
  int ans=0;
  int arr[n];
  for(int i=0;i<n;i++)
  {
    int temp; cin>>temp;
    arr[i]=temp;
  }
  solve(arr, n, r, ans);
  cout<<ans;
  return 0;
}
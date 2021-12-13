#include<iostream>
#include<queue>
using namespace std;
int main()
{
  int n=4;  int ans=0;
  priority_queue<int, vector<int>, greater<int>> minh;
  for(int i=0;i<n;i++)
  {
    int a;
    cin>>a;
    minh.emplace(a);
  }
  while (minh.size()>1)
  {
    int num1=minh.top();
    minh.pop();
    int num2=minh.top();
    minh.pop();
    ans+=num1+num2;
    minh.emplace(num1+num2);
  }
  cout<<ans;
  return 0;
}
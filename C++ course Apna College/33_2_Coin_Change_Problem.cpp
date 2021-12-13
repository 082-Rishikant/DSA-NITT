#include<iostream>
using namespace std;
int main()
{
  int arr[]={1, 2, 5, 10, 20, 50, 100, 500, 2000};
  int X=1500;
  int i=8;
  int ans=0;
  while (i>=0 && X>0)
  {
    ans+=X/arr[i];
    X=X%arr[i];
    i--;
  }
  cout<<ans;
  return 0;
}
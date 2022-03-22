#include<iostream>
#include<vector>
#include <algorithm>
#include<string.h>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<climits>
#include<math.h>

const int N=1e9+7;
using namespace std;

float solve(int n, int p)
{
  int l=0;int r=n;
  float ans=0.0;
  while(l<=r)
  {
    int mid=(l+r)/2;
    if(mid*mid==n)
      return mid;
    else if(mid*mid<n)
    {
      ans=mid;
      l=mid+1;
    }
    else if(mid*mid>n)
    {
      r=mid-1;
    }
  }
  cout<<"Integer Part: "<<ans<<endl;

  float inc=0.1;
  for(int i=1;i<=p;i++)
  {
    float temp=ans;
    for(int j=1;j<=9;j++)
    {
      if((ans+inc*j)*(ans+inc*j)<=n)
      {
        temp=ans+inc*j;
        // cout<<temp;
      }
      else{
        break;
      }
    }
    ans=temp;
    inc=inc/10;
  }
  return ans;
}

int main()
{
  int n=10;int p=4;
  cout<<"Final Answer: "<<solve(n, p);
  return 0;
}
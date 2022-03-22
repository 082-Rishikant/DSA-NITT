#include<iostream>
using namespace std;
int *t;

int countBST(int n){
  if(n==0 || n==1)
    return 1;
  if(t[n]!=-1)
    return t[n];
  
  int temp=0;
  for(int i=1;i<=n;i++){
    if(t[i-1]==-1)
      t[i-1]=countBST(i-1);
    if(t[n-i]==-1)
      t[n-i]=countBST(n-i);
    temp+=t[i-1]*t[n-i];
  }
  return t[n]=temp;
}

int main()
{
  int n=5;
  
  t=new int[n+1];
  for(int i=0;i<=n;i++){
    t[i]=-1;
  }
  t[0]=1; t[1]=1;

  cout<<countBST(n);
  return 0;
}
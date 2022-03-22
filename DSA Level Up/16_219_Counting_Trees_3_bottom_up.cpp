#include<iostream>
using namespace std;
int *t;

void countBST(int n){
  // base condition
  t[0]=1; t[1]=1;
  
  // DP started
  for(int i=2;i<=n;i++){
    for(int j=1;j<=i;j++){
      t[i]+=t[j-1]*t[i-j];
    }
  }
  return;
}

int main()
{
  int n=4;
  
  t=new int[n+1];
  for(int i=0;i<=n;i++){
    t[i]=0;
  }

  countBST(n);
  cout<<t[n];
  return 0;
}
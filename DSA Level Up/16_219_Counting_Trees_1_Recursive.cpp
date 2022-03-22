#include<iostream>
using namespace std;

int countBST(int n){
  if(n==0 || n==1)
    return 1;
  
  int temp=0;
  for(int i=1;i<=n;i++){
    temp+=countBST(i-1)*countBST(n-i);
  }
  return temp;
}

int main()
{
  int n=3;
  cout<<countBST(n);
  return 0;
}
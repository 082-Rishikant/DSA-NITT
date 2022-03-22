#include<iostream>
#include<vector>
#include <algorithm>
#include<string.h>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<climits>

const int N=1e9+7;
using namespace std;
int *t;

void frogMinCost(vector<int> arr, int n){
  t[0]=0;

  for(int curr=0;curr<n;curr++){
    for(int j=1;j<=2;j++){
      t[curr+j]=min(t[curr]+abs(arr[curr]-arr[curr+j]), t[curr+j]);
    }
  }

  return;
}

int main()
{
  vector<int> arr={10, 30, 40, 20};
  int n=arr.size();

  t=new int[n];
  for(int i=0;i<n;i++){
    t[i]=INT_MAX;
  }

  frogMinCost(arr, n);
  cout<<t[n-1];
  return 0;
}
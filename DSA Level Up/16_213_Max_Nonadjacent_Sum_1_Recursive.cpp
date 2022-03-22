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

int maxNonadjacentSum(vector<int> arr, int n, int curr){
  if(curr==(n-1))
    return arr[curr];
  if(curr>=n)
    return 0;
  
  int temp=max(maxNonadjacentSum(arr, n, curr+2)+arr[curr], maxNonadjacentSum(arr, n, curr+1));

  return temp;
}

int main()
{


  vector<int> arr={6,10,12,7,9,14};
  int n=arr.size();

  cout<<maxNonadjacentSum(arr, n, 0);

  return 0;
}
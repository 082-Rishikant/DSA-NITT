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
int total=0;

bool solve(int arr[], int n, int x, int sum)
{
  if(sum==x){
    total++;
    return true;
  }
  else if(sum>x)return false;
  else if(n==0)return false;
  else{
    bool temp1=solve(arr, n-1, x, sum);
    bool temp2=solve(arr, n-1, x, sum+arr[n-1]);
    return (temp1 || temp2);
    //******** this below statement will execute only first function if first function returns true and thats why we did not get all subsets count with sum==x *********
    // return (solve(arr, n-1, x, sum) || solve(arr, n-1, x, sum+arr[n-1]));
  }
}

int main()
{
  // lets count the total number of subsetswith sum=x
  int arr[]={10, 10, 15, 6, 19, 20};int n=6;int x=16;
  cout<<solve(arr, n, x, 0)<<endl;
  cout<<total;
  return 0;
}
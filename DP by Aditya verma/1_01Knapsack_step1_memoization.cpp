#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
using namespace std;
const int n=3; //size of wt and val array
const int w=4; // capacity of knapSack
vector<int> wt{4,5,1},val{1,2,3};
int t[n+1][w+1];

//Recursive memoized function -  DP
int knapSack_memoized(int n, int w)
{
    if(n==0 || w==0)
        return t[n][w]=0;
    else if(t[n][w]!=-1)
        return t[n][w];
    else if(wt[n-1]<=w)
    {
        return t[n][w]= max(val[n-1]+knapSack_memoized(n-1, w-wt[n-1]), knapSack_memoized(n-1, w));
    }
    else{
        return t[n][w]= knapSack_memoized(n-1, w);
    }
}

int main()
{
    memset(t, -1, sizeof(t));  // not for vector
    cout<<knapSack_memoized(n,w)<<endl;
    return 0;
}
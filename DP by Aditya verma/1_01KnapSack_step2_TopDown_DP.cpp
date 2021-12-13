#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
using namespace std;
const int n=3; //size of wt and val array
const int w=4; // capacity of knapSack
vector<int> wt{4,5,1},val{1,2,3};
int t[n+1][w+1];

//  top down Approach -  Real DP
int knapSack_topdown(int n, int w)
{
    for(int i=0;i<=n;i++)
    {
        for (int j = 0; j <= w; j++)
            if(i==0 || j==0)
                t[i][j]=0; 
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if(wt[i-1]<=j)
            {
                t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]], t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][w];
}

int main()
{
    memset(t, -1, sizeof(t));  // not for vector
    cout<<knapSack_topdown(n,w)<<endl;
    return 0;
}
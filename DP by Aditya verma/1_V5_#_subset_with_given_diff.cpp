#include<iostream>
#include<vector>
#include <algorithm>
#include<string.h>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>

const int N=1e9+7;
using namespace std;

int subset_with_diff(vector<int> vec, int s)
{
    int n=vec.size();
    int t[n+1][s+1];
    memset(t, 0, sizeof(t));
    for(int i=0;i<=n;i++)
        for(int j=0;j<=s;j++)
            if(j==0)
                t[i][j]=1;
            else if(j!=0 && i==0)
                t[i][j]=0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s;j++)
        {
            if(vec[i-1]<=j)
            {
                t[i][j]=t[i-1][j-vec[i-1]]+t[i-1][j];
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][s];
}

int main()
{
    vector<int> vec={1,1,2,3};
    int diff=1;
    int n=vec.size();
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=vec[i];
    }
    if((diff+sum)%2==0)
        cout<<subset_with_diff(vec, (sum+diff)/2)<<endl;
    else
        cout<<0;
    return 0;
}
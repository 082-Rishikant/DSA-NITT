#include<iostream>
#include<vector>
using namespace std;
vector<vector<bool>> t(1001, vector<bool>(1001, false));

bool subsetSum(int arr[], int n, int s)
{
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= s; j++)
            if(j==0)
                t[i][j]=true;
            else if(j!=0 || i==0)
                t[i][j]=false;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if(arr[i-1]<=j)
            {
                t[i][j]=(t[i-1][j-arr[i-1]] || t[i-1][j]);
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
    int arr[]={2,3,7,8,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int s=11;
    if(subsetSum(arr, n, s))
    {
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}
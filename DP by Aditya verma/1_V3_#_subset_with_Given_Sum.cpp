#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>

const int N=1e9+7;
using namespace std;

int no_subsetSum(vector<int> vec, int s)
{
    int n=vec.size();
    vector<vector<int>> t(n+1, vector<int>(s+1, -1));
    for (int i = 0; i <= n; i++)
        for(int j=0;j<=s;j++)
            if(j==0)
                t[i][j]=1;
            else if(j!=0 && i==0)
                t[i][j]=0;

    for (int i = 1; i <= n; i++)
    {
        for(int j=1;j<=s;j++)
        {
            if(vec[i-1]<=j)
            {
                t[i][j]=(t[i-1][j-vec[i-1]]+t[i-1][j])%N;
            }
            else
            {
                t[i][j]=(t[i-1][j])%N;
            }
        }
    }
    return t[n][s];
}

int main()
{
    vector<int> vec={2, 3, 5, 6, 8, 10};
    int s=10;
    cout<<no_subsetSum(vec,s);
    return 0;
}
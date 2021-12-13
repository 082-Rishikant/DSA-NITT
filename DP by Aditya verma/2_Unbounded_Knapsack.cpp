#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

const int N = 1e9 + 7;
using namespace std;

int unbounded_knapsack(int n, int W, int val[], int wt[])
{
    vector<vector<int>> t(n + 1, vector<int>(W + 1, 0));
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= W; j++)
            if(i==0 || j==0)
                t[i][j]=0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = max(t[i][j - wt[i - 1]]+val[i-1],  t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][W];
}

int main()
{
    int n = 2, W = 3;
    int val[] = {1, 1};
    int wt[] = {2, 1};
    cout<<unbounded_knapsack(n, W, val, wt);
    return 0;
}
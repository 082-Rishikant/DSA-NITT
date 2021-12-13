#include <iostream>
#include <vector>
#include <algorithm>
#include<string.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

const int N = 1e9 + 7;
using namespace std;

int findDifference(int arr[], int n, int s)
{
    int t[n + 1][s + 1];
    memset(t, 0, sizeof(t));

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= s; j++)
            if (j == 0)
                t[i][j] = 1;
            else if (j != 0 && i == 0)
                t[i][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = (t[i - 1][j - arr[i - 1]] | t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    int i = n;
    for (int j = s; j >= 0; j--)
    {
        if (t[i][j] == 1)
        {
            return j;
        }
    }
}

int minDifference(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int s1 = findDifference(arr, n, sum / 2);
    int s2 = sum - s1;
    return abs(s1 - s2);
}

int main()
{
    int arr[]={1,6,16,5};
    cout<<minDifference(arr, 4);
    return 0;
}
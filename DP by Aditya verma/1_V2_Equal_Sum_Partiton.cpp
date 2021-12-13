#include <iostream>
#include <vector>
using namespace std;

bool subsetSum_topDown(int n, vector<int> arr, int s)
{
    vector<vector<bool>> t(201, vector<bool>(1e5 + 1, false));
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= s; j++)
            if (j == 0)
                t[i][j] = true;
            else if (j != 0 && i == 0)
                t[i][j] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][s];
}

bool canPartition(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    if (sum % 2 != 0)
        return false;
    else
        return subsetSum_topDown(n, arr, sum / 2);
}

int main()
{
    vector<int> vec = {2, 5, 16, 2, 5};
    cout << canPartition(vec);
    return 0;
}
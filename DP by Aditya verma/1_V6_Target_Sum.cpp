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

int targetSum(vector<int> vec, int s)
{
    int n = vec.size();
    vector<vector<int>> t(n + 1, vector<int>(s + 1, 0));
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= s; j++)
            if (j == 0 && i == 0) // here j is the sum
                t[i][j] = 1;
            else if (j != 0 && i == 0)
                t[i][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (vec[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - vec[i - 1]] + t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][s];
}

int main()
{
    vector<int> vec = {1, 1, 1, 1, 1};
    int target = 3;
    int sum = 0;
    for (int i = 0; i < (int)vec.size(); i++)
    {
        sum += vec[i];
    }
    if (target < 0)
        target = -target;
    if ((sum + target) % 2 != 0)
        cout<< 0;
    else
        cout<< targetSum(vec, (sum + target) / 2);
    return 0;
}
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

int cutRod(int price[], int n)
{
    int t[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            if (i == 0 || j == 0)
                t[i][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i <= j)
            {
                t[i][j] = max(price[i - 1] + t[i][j - i], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][n];
}

int main()
{
    int n=8;
    int price[] = {3, 5, 8, 9, 10, 17, 17, 20};
    cout<<cutRod(price, n);
    return 0;
}
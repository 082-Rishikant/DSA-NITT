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

long long int count(int s[], int m, int n)
{

    long long int t[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            if (j == 0)
                t[i][j] = 1;
            else if (j != 0 && i == 0)
                t[i][j] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] <= j)
            {
                t[i][j] = t[i][j - s[i - 1]] + t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[m][n];
}

int main()
{
    int n = 4 , m = 3;
    int s[] = {1,2,3};
    cout<<count(s, m, n);
    return 0;
}
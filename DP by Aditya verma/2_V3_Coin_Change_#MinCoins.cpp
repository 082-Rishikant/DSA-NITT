#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include<climits>

const int N = INT_MAX;
using namespace std;

int minCoins(int coins[], int m, int v)
{
	int t[m + 1][v + 1];
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= v; j++)
			if (j == 0)
				t[i][j] = 0;
			else if (j != 0 && i == 0)
				t[i][j] = INT_MAX-1;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			if (coins[i - 1] <= j)
			{
				t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j]);
			}
			else
			{
				t[i][j] = t[i - 1][j];
			}
		}
	}
	if (t[m][v] < INT_MAX-1)
		return t[m][v];
	return -1;
}

int main()
{
	int v = 11, m = 4,coins[] = {9, 6, 5, 1};
	cout<<minCoins(coins, m, v);
	return 0;
}
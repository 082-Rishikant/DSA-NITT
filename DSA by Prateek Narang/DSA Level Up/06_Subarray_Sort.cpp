#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> subarraySort_usingSort(vector<int> vec) //O(nlogn)
{
    vector<int> ans;
    int n = vec.size();
    int s = n - 1, e = 0;
    vector<int> sorted = vec;
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < n; i++)
    {
        if (vec[i] != sorted[i])
        {
            s = min(s, i);
        }
        if (vec[n - 1 - i] != sorted[n - 1 - i])
        {
            e = max(e, n - 1 - i);
        }
    }
    if (s == (n - 1))
    {
        return {-1, -1};
    }
    return ans = {s, e};
}

vector<int> subarraySort_Optimized(vector<int> vec)
{
    int n = vec.size();
    int s = n, e = 0;
    int maxi = -1e6, mini = 1e6;
    for (int i = 0; i < n - 1; i++)
    {
        if (vec[i] > vec[i + 1])
        {
            maxi = max(maxi, vec[i]);
            mini = min(mini, vec[i + 1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (mini < vec[i])
            s = min(s, i);
        if (maxi > vec[i])
            e = max(e, i);
    }
    if (s == n)
    {
        return {-1, -1};
    }
    return {s, e};
}

int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    vector<int> ans1 = subarraySort_usingSort(vec); // O(nlogn) and O(n)
    vector<int> ans2 = subarraySort_Optimized(vec); // O(n) and O(1)
    cout << ans1[0] << " " << ans1[1]<<endl;
    cout << ans2[0] << " " << ans2[1];
    return 0;
}
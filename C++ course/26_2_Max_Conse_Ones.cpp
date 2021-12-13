#include <iostream>
#include <vector>
using namespace std;

int bruteForce(vector<int> a, int k) // O(n*n)
{
    int n = a.size();
    int l = 0, ans = 0, zero = 0;
    for (int i = 0; i < n; i++)
    {
        l = 0;
        for (int j = i; j < n; j++)
        {
            if (a[j] == 0)
            {
                zero++;
            }
            if (zero > k)
            {
                zero = 0;
                break;
            }
            l++;
        }
        ans = max(ans, l);
    }
    return ans;
}

int optimizedApproach(vector<int> a, int k)
{
    int n = a.size();
    int ans = 0;
    int l = 0;
    int zero = 0;
    int i = 0;
    int j = 0;
    while (i < n && j < n)
    {
        if (a[j] == 0)
        {
            zero++;
        }
        if (zero > k)
        {
            ans = max(ans, l);
            while (a[i]!=0)
            {
                i++;
                l--;
            }
            zero--;
            i++;
            l--;
        }
        l++;
        j++;
    }
    return ans;
}

int main()
{
    // vector<int> a = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    vector<int> a = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 3;
    cout << bruteForce(a, k)<<endl;        // O(n*n)
    cout << optimizedApproach(a, k); // O(n)
    return 0;
}
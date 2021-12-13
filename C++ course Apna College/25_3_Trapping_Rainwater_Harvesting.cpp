#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int bruteForce(vector<int> a) // O(n)
{
    int n = a.size();
    vector<int> l(n);
    vector<int> r(n);
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        l[i] = max;
        if (max < a[i])
        {
            max = a[i];
        }
    }

    max = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        r[i] = max;
        if (max < a[i])
        {
            max = a[i];
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        l[i] = min(l[i], r[i]);
        l[i] = l[i] - a[i];
        if (l[i] < 0)
        {
            l[i] = 0;
        }
        sum += l[i];
    }
    return sum;
}

int optimizedApproach(vector<int> a)  // O(n)
{
    int n = a.size();
    stack<int> st;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[st.top()] < a[i])
        {
            int height = a[st.top()];
            st.pop();
            if (!st.empty())
            {
                int length = i - st.top() - 1;
                sum = sum + (min(a[st.top()], a[i]) - height) * (length);
            }
        }
        st.push(i);
    }
    return sum;
}

int main()
{
    vector<int> a{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    // cout<<bruteForce(a); // O(n)
    cout << optimizedApproach(a); // O(n)
    return 0;
}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int bruteForceApproach(vector<int> vec)  // O(n*n)
{
    int n = vec.size();
    int maxSum = 0;
    int minHeight = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        minHeight=INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (minHeight > *(vec.begin() + j))
            {
                minHeight = *(vec.begin() + j);
            }
            if (minHeight * (j + 1 - i) > maxSum)
            {
                maxSum = minHeight * (j + 1 - i);
            }
            else if(vec[j]>maxSum)
            {
                maxSum=vec[j];
            }
            else
            {
                continue;
            }
        }
    }
    return maxSum;
}

int optimizedApproach(vector<int> vec)  // O(n)
{
    int n=vec.size();
    int ans=0;
    stack<int> st;
    vec.push_back(0);
    for(int i=0;i<=n;i++)
    {
        while (!st.empty() && vec[st.top()]>vec[i])
        {
            int height=vec[st.top()];
            st.pop();
            if(st.empty())
            {
                ans=max(ans, height*i);
            }
            else
            {
                int len=i-st.top()-1;
                ans=max(ans, height*len);
            }
        }
        st.push(i);
    }
    return ans;
}

int main()
{
    vector<int> vec{6, 3, 1, 9, 8, 3};

    // cout<<bruteForceApproach(vec); // O(n*n)
    cout<<optimizedApproach(vec); // O(n)
    return 0;
}
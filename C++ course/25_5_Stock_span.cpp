#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> bruteForceApproach(vector<int> a) // O(n*n)
{
    int n=a.size();
    vector<int> ans(n, 0);
    for(int i=0;i<n;i++)
    {
        int j=i;
        while (j>=0 && a[j]<=a[i])
        {
            ans[i]++;
            j--;
        }
    }
    return ans;
}

vector<int> optimizedApproach(vector<int> a) ///O(n)
{
    int n=a.size();
    vector<int> ans(n, 1);
    stack<pair<int, int>> st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && a[st.top().first]<a[i])
        {
            ans[i]=ans[i]+st.top().second;
            st.pop();
        }
        pair<int, int> pr={i, ans[i]};
        // st.push(pr);
        st.push({i, ans[i]});
    }
    return ans;
}

int main()
{
    vector<int> a = {100, 80, 60, 70, 60, 75, 85};

    // vector<int> ans= bruteForceApproach(a); // O(n*n)
    // for(auto it:ans)
    // {
    //     cout<<it<<"  ";
    // }

    vector<int> ans= optimizedApproach(a);
    for(auto it:ans)
    {
        cout<<it<<"  ";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;


void broute(vector<int> vec, int k)  // O(n*k)
{
    int n=vec.size();
    for(int i=0;i<n-2;i++)
    {
        int max=INT_MIN;
        for(int j=i;j<i+3;j++)
        {
            if(*(vec.begin()+j)>max)
            {
                max=*(vec.begin()+j);
            }
        }
        cout<<max<<" ";
    }
}

vector<int> usingMultiSet(vector<int> vec, int k) // O(nlogn)
{
    int n=vec.size();
    multiset<int,greater<int>> ms;
    vector<int> ans;
    for(int i=0;i<k;i++)
    {
        ms.insert(*(vec.begin()+i));
    }
    int x=0;
    ans.push_back(*(ms.begin()));
    for(int i=k;i<n;i++)
    {
        ms.erase(ms.lower_bound(*(vec.begin()+x)));
        ms.insert(*(vec.begin()+i));
        ans.push_back(*(ms.begin()));
        x++;
    }
    return ans;
}

vector<int> maxiMumSlid(vector<int> vec, int k) // O(n)
{
   deque<int> dq;
   vector<int> ans;
   int n=vec.size();
   for(int i=0;i<k;i++)
   {
       while (!dq.empty() && vec[i]>vec[dq.back()])
       {
           dq.pop_back();
       }
       dq.push_back(i);
   }
   ans.push_back(vec[dq.front()]);
   for(int i=k;i<n;i++)
   {
       if(dq.front()==(i-k))
       {
           dq.pop_front();
       }
       while(!dq.empty() && vec[i]>vec[dq.back()])
       {
           dq.pop_back();
       }
       dq.push_back(i);
       ans.push_back(vec[dq.front()]);
   }
   return ans;
}

int main()
{
    int n,k;
    cout<<"Enter n and k: \n";
    cin>>n>>k;
    vector<int> vec(n);
    for(auto &i:vec)
    {
        cin>>i;
    }

    // broute(vec, k);  // O(n*k)

    // vector<int> ans=usingMultiSet(vec, k);  // O(nlogn)
    // for(auto i:ans)
    //     cout<<i<<" ";

    vector<int> ans=maxiMumSlid(vec, k); // O(n)
    for(auto i:ans)
        cout<<i<<" ";
    return 0;
}
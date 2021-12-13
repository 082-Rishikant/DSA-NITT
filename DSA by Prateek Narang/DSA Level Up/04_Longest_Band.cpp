#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int findlband(vector<int> vec, int n)
{
    unordered_set<int> st;
    for(int it:vec)
    {
        st.insert(it);
    }
    int maxi=0;
    for(int it:st)
    {
        if(st.find(it-1)==st.end())
        {
            int cnt=1;
            int item=it;
            cout<<item<<" ";
            while (st.find(item+1)!=st.end())
            {
                cnt++;
                item++;
                cout<<item<<" ";
            }
            cout<<endl;
            maxi=max(maxi,cnt);
        }
    }
    return maxi;
}

int main()
{
    vector<int> vec{1,9,3,0,18,5,2,4,10,7,12,6};
    int n=vec.size();
    cout<<findlband(vec,n);
    return 0;
}
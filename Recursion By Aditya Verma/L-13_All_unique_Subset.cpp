#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

unordered_set<string> uSubset(string s, unordered_set<string> st, string op)
{
    if(s=="")
    {
        st.insert(op);
        return st;
    }
    st=uSubset(s.substr(1, s.length()-1), st, op);
    st=uSubset(s.substr(1, s.length()-1), st, op+s[0]);
    return st;
}

int main()
{
    // vector<string> vec;
    unordered_set<string> st; 
    st=uSubset("aaa", st, "");
    // for(auto it:vec)
    // {
    //     st.insert(it);
    // }
    for(auto it:st)
    {
        cout<<it<<" ";
    }
    return 0;
}
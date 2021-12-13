#include<iostream>
#include<stack>
using namespace std;

bool bal(string s)
{
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            if(st.empty() || st.top()!='(')
            {
                return 0;
            }
            st.pop();
        }
        else if(s[i]=='}')
        {
            if(st.empty() || st.top()!='{')
            {
                return 0;
            }
            st.pop();
        }
        else if(s[i]==']')
        {
            if(st.empty() || st.top()!='[')
            {
                return 0;
            }
            st.pop();
        }
        else
        {
            continue;
        }      
    }
    if(!st.empty())
    {
        return 0;
    }
    return 1;
}

int main()
{
    cout<<bal("{,jkhh(gh,h,[fsgd]mgj)hgf}");
    return 0;
}
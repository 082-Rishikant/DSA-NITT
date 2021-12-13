#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int prec(char c)
{
    if(c=='^')
    {
        return 3;
    }
    else if(c=='*' || c=='/')
    {
        return 2;
    }
    else if(c=='+' || c=='-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infToPre(string s)
{
    stack<char> st;
    int l=s.length();
    string newS;
    for(int i=0;i<l;i++)
    {
        if(s[i]=='(')
        {
            newS=')'+newS;
        }
    // Also we can consider '(' as ')' and vice-versa
        else if(s[i]==')')
        {
            newS='('+newS;
        }
        else
        {
            newS=s[i]+newS;
        }
    }
    // cout<<newS<<endl;
    string ans="";
    for(int i=0;i<l;i++)
    {
        // cout<<newS[i]<<endl;
        if((newS[i]>='a' && newS[i]<='z') || (newS[i]>='A' && newS[i]<='Z'))
        {
            ans=ans+newS[i];
        }
        else if(newS[i]=='(')
        {
            st.push(newS[i]);
        }
        else if(newS[i]==')')
        {
            while (st.top()!='(')
            {
                ans=ans+st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && prec(newS[i])<prec(st.top()))
            {
                ans=ans+st.top();
                st.pop();
            }
            st.push(newS[i]);
        }
    }

    while (!st.empty())
    {
        ans=ans+st.top();
        st.pop();
    }
    // cout<<ans<<endl;
    string a="";
    for(int i=ans.length()-1;i>=0;i--)
    {
        a=a+ans[i];
    }
    return a;
}

int main()
{
    cout<<infToPre("(a-b/c)*(a/k-l)");
    return 0;
}
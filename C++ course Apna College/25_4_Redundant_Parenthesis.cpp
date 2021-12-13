#include <iostream>
#include <stack>
using namespace std;

int redundantParentheses(string s)
{
    int ans = 0;
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (st.empty())
            {
                cout << "INVALID\n";
                return -1;
            }
            if (st.top() == '(')
            {
                ans++;
                st.pop();
            }
            else
            {
                st.pop();
                st.pop();
            }
        }
        else
        {
            continue;
        }
    }
    return ans;
}

int main()
{
    string s = "((a+b)";
    cout << redundantParentheses(s);
    return 0;
}
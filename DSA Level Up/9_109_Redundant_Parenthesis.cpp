#include<iostream>
#include<stack>
using namespace std;

string isParenthesisRedundant(string s)
{
  stack<char> st; int l=s.length(); int i=0;
  while (i<l)
  {
    if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='%')
      st.push(s[i]);
    else if(s[i]==')' || s[i]=='}' || s[i]==']')
    {
      if(st.empty())
        return "Yes";
      st.pop();
    }
    i++;
  }
  return "No";
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  string s; cin>>s;
  cout<<isParenthesisRedundant(s);
  return 0;
}
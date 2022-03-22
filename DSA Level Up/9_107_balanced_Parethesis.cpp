#include<iostream>
#include<stack>
using namespace std;

bool is_Balanced(string exp)
{
  stack<char> st; int i=0;
  int l=exp.length();
  while(i<l)
  {
    if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
      st.push(exp[i]);
    else if(exp[i]==')')
    {
      if(st.empty())
        return false;
      else if(st.top()=='(')
        st.pop();
      else  
        return false;
    }
    else if(exp[i]=='}')
    {
      if(st.empty())
        return false;
      else if(st.top()=='{')
        st.pop();
      else
        return false;

    }
    else if(exp[i]==']')
    {
      if(st.empty())
        return false;
      else if(st.top()=='[')
        st.pop();
      else
        return false;
    }
    i++;
  }
  if(st.empty())
    return true;
  return false;
}

int main()
{
// #ifndef ONLINE_JUDGE
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
// #endif
  // string exp; cin>>exp;
  cout<<is_Balanced("()(({[]}))[]}{}");
  return 0;
}
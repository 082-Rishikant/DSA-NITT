#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st, int ele)
{
    if(st.empty())
    {
        st.push(ele);
        return;
    }
    int temp=st.top();
    st.pop();
    insertAtBottom(st, ele);
    st.push(temp);
    return;
}

void reverseStack(stack<int> &st)
{
    if(st.empty())
    {
        return;
    }
    int temp=st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, temp);
    return;
}

int main()
{
    stack<int> st;
    st.push(4);
    st.push(1);
    st.push(7);
    st.push(9);
    st.push(34);
    // cout<<st.size();
    reverseStack(st);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}
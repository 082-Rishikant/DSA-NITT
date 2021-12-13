#include<iostream>
#include<stack>
using namespace std;

void print(stack<int> st)
{
    if(st.size()==0)
    {
        return;
    }
    int temp=st.top();
    st.pop();
    print(st);
    cout<<temp<<" ";
    return;
}

void insert(stack<int> &st, int temp)
{
    if(st.empty())
    {
        st.push(temp);
        return;
    }
    int val=st.top();
    st.pop();
    insert(st, temp);
    st.push(val);
    return;
}

void reverse(stack<int> &st)
{
    if(st.size()==1)
    {
        return;
    }
    int temp=st.top();
    st.pop();
    reverse(st);
    insert(st, temp);
    return;
}

int main()
{
    stack<int> st;
    st.push(4);
    st.push(1);
    st.push(5);
    st.push(3);
    st.push(19);
    print(st);
    cout<<endl;

    reverse(st);

    print(st);
    return 0;
}
#include<iostream>
#include<stack>
using namespace std;

void  place(stack<int> &st, int temp)
{
    if(st.empty()==true || st.top()<temp)
    {
        st.push(temp);
        return;
    }
    int val=st.top();
    st.pop();
    place(st, temp);
    st.push(val);
    return;
}

void sort(stack<int> &st)
{
    if(st.size()==1)
    {
        return;
    }
    int temp=st.top();
    st.pop();
    sort(st);
    place(st, temp);
    return;
}

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

void deleteAnelement(stack<int> &st, int k)
{
    if(k==1)
    {
        st.pop();
        return;
    }
    int temp=st.top();
    st.pop();
    deleteAnelement(st, k-1);
    st.push(temp);
    return;
}

void reverse(stack<int> st)
{
    if(st.empty())
    {
        return;
    }
    st.pop();
    reverse(st);
}

int main()
{
    stack<int> st;
    st.push(4);
    st.push(1);
    st.push(5);
    st.push(3);
    st.push(19);

    // sort(st);

    // int k=st.size()/2+1;
    // deleteAnelement(st, k);

    reverse(st);

    print(st);
    return 0;
}
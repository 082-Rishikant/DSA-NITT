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

int main()
{
    stack<int> st;
    st.push(4);
    st.push(1);
    st.push(5);
    st.push(3);
    st.push(19);


    int k=st.size()/2+1;
    deleteAnelement(st, k);

    print(st);
    return 0;
}
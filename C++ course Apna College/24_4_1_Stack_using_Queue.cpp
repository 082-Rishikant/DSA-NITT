#include<iostream>
#include<queue>
using namespace std;

class stack
{
    queue<int> q1;
    queue<int> q2;
    public:
    void push(int n)  // time complexity is O(n);
    {
        q2.push(n);
        while (!q1.empty())
        {
            int temp=q1.front();
            q2.push(temp);
            q1.pop();
        }
        // swap(q1, q2);
        queue<int> temp=q1;
        q1=q2;
        q1=temp;
        return;
    }
    int pop() // O(1) means Constant;
    {
        if(q1.empty())
        {
            cout<<"EMPTY!\n";
            return -1;
        }
        int temp=q1.front();
        q1.pop();
        return temp;
    }
    bool empty()
    {
        if(q1.empty())
        {
            return 1;
        }
        return 0;
    }
};

int main()
{
    stack st;
    st.push(4);
    st.push(5);
    st.push(6);

    cout<<st.empty()<<endl;

    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;

    cout<<st.empty()<<endl;
    return 0;
}
#include<iostream>
#include<queue>
using namespace std;

class stack
{
    int N;
    queue<int> q1;
    queue<int> q2;
    public:
    stack()
    {
        N=0;
    }
    void push(int n)  // time complexity is O(1);
    {
        q1.push(n);
        N++;
        return;
    }
    int  size()
    {
        return N;
    }
    int pop() // O(n) 
    {
        if(q1.empty())
        {
            cout<<"EMPTY!\n";
            return -1;
        }
        N--;
        int temp;
        while (q1.size()!=1)
        {
            q2.push(q1.front()); 
            q1.pop();
        }
        temp=q1.front();
        q1.pop();
        queue<int> q3=q1;
        q1=q2;
        q2=q3;
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

    cout<<"Size: "<<st.size()<<endl;

    cout<<"EMPTY: "<<st.empty()<<endl;

    cout<<"POPED: "<<st.pop()<<endl;
    cout<<"POPED: "<<st.pop()<<endl;
    cout<<"POPED: "<<st.pop()<<endl;
    cout<<"POPED: "<<st.pop()<<endl;
    
   
    cout<<"Size: "<<st.size()<<endl;

    cout<<"EMPTY: "<<st.empty()<<endl;
    
    return 0;
}
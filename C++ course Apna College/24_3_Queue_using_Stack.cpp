#include <iostream>
#include <stack>
using namespace std;

// First Method****************

// class que
// {
//     stack<int> st1;
//     stack<int> st2;

// public:
//     void push(int n)
//     {
//         st1.push(n);
//         return;
//     }
//     int pop()
//     {
//         int temp = 0;
//         if (st1.empty() && st2.empty())
//         {
//             // cout << "Queue is EMPTY!\n";
//             return -1;
//         }
//         if (st2.empty())
//         {
//             while (!st1.empty())
//             {
//                 int val = st1.top();
//                 st2.push(val);
//                 st1.pop();
//             }
//         }
//         temp = st2.top();
//         st2.pop();
//         return temp;
//     }

//     bool empty()
//     {
//         if(st1.empty() && st2.empty())
//             return true;
//         return false;
//     }
// };

// int main()
// {
//     que q;
//     q.push(2);
//     q.push(3);
//     q.push(4);
//     q.push(5);

//     cout<<"EMPTY OR NOT: "<<q.empty()<<endl;

//     cout << q.pop() << endl;
//     cout << q.pop() << endl;
//     cout << q.pop() << endl;
//     cout << q.pop() << endl;
//     cout << q.pop() << endl;

//     cout<<"EMPTY OR NOT: "<<q.empty()<<endl;

//     q.push(6);
//     cout << q.pop() << endl;
//     cout << q.pop() << endl;
//     return 0;
// }

// Second Method

class que{
    stack<int> st;
    public:
    void push(int n)
    {
        st.push(n);
        return;
    }
    int Pop()
    {
        if(st.empty())
        {
            cout<<"Empty Queue!\n";
            return -1;
        }
        int temp=st.top();
        st.pop();
        if(st.empty())
        {
            return temp;
        }
        int item=Pop();
        st.push(temp);
        return item;
    }

    bool empty()
    {
        if(st.empty())
            return true;
        return false;
    }
};

int main()
{
    que q;

    q.push(3);
    q.push(4);
    q.push(5);

    cout<<"IS EMPTY: "<<q.empty()<<endl;

    cout<<q.Pop()<<endl;
    cout<<q.Pop()<<endl;
    cout<<q.Pop()<<endl;
    cout<<q.Pop()<<endl;
    cout<<q.Pop()<<endl;
    
    cout<<"IS EMPTY: "<<q.empty()<<endl;
    return 0;
}
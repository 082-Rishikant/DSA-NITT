#include<iostream>
using namespace std;

#define n 4

class stack{
    int *arr=new int[n];
    // int arr[n];
    int top=-1;
    public:
    void push(int data)
    {
        if(top==n-1)
        {
            cout<<"STACK FULL!\n";
            return;
        }
        top++;
        arr[top]=data;
        cout<<"PUSHED: "<<arr[top]<<"\n";
        return;
    }

    void pop()
    {
        if(top==-1)
        {
            cout<<"POPED: EMPTY!\n";
            return;
        }
        cout<<"POPED: "<<arr[top]<<endl;
        top--;
        return;
    }

    bool empty()
    {
        cout<<"Empty stastus: ";
        return top==-1;
    }

    void Top()
    {
        if(top==-1)
        {
            cout<<"TOP: NO ELEMENT!\n";
            return;
        }
        cout<<"TOP: "<<arr[top]<<endl;
        return;
    }
};

int main()
{
    // int n;
    // int arr[5];
    // int top=-1;
    // cout<<"Enter the number:\n";
    // cin>>n;
    // for(int i=0;i<n;i++)
    // {
    //     int data;
    //     cin>>data;
    //     arr[++top]=data;
    //     if(top==4)
    //     {
    //         cout<<"Now stack is FULL\n";
    //         break;
    //     }
    // }
    // cout<<"poped:";
    // char s;
    // do
    // {
    //     cout<<arr[top]<<endl; 
    //     top--;
    //     if(top==-1)
    //     {
    //         cout<<"Now stack is Empty\n";
    //         break;
    //     }
    //     cout<<"More POP(y/n)\n"; 
    //     cin>>s; 
    // } while (s=='y');
    
    stack st;
    st.push(3);
    st.push(7);
    st.push(33);
    st.push(32);
    st.push(90);
    st.push(34);

    st.pop();
    st.pop();
    st.pop();

    st.Top();

    cout<<st.empty()<<endl;

    return 0;
}
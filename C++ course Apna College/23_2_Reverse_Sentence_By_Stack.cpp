// #include<iostream>
// // #include<math.h>
// using namespace std;

// #define n 6

// class stack{
//     string *arr=new string[n];
//     int top=-1;
//     public:
//     void push(string s)
//     {
//         if(top==n-1)
//         {
//             cout<<"Stack Full!: "<<s<<endl;
//             return;
//         }
//         top++;
//         arr[top]=s;
//         return;
//     }

//     string pop()
//     {
//         if(top==-1)
//         {
//             cout<<"POPED: empty!\n";
//             return "empty!";
//         }
//         string s=arr[top];
//         top--;
//         return s;
//     }
// };

// int main()
// {
//     stack st;
//     string s[]={"Hey,", "how", "are", "you", "doing?"};
//     int l=sizeof(s)/sizeof(s[0]);
//     for(int i=0;i<l;i++)
//     {
//         st.push(s[i]);
//     }
//     for(int i=0;i<l;i++)
//     {
//         s[i]=st.pop();
//     }
//     for(int i=0;i<l;i++)
//     {
//         cout<<s[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }





#include<iostream>
#include<stack>
using namespace std;

string reverseSenetnce(string s)
{
    stack<string> st;
    int l=s.length();
    for(int i=0;i<l;i++)
    {
        string word="";
        while(s[i]!=' ' && i<l)
        {
            word=word+s[i];
            i++;
        }
        st.push(word);
    }
    s="";
    while (!st.empty())
    {
        // cout<<st.top()<<" ";
        s=s+st.top()+" ";
        st.pop();
    }
    return s;
}

int main()
{
    string s="hey, how are you doing?";

    cout<<reverseSenetnce(s);
    return 0;
}
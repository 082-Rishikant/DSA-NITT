#include<iostream>
#include<vector>
using namespace std;

void l_case_change(string s, string op, int n)
{
    if(s=="")
    {
        cout<<op<<" ";
        return;
    }
    if((s[0]>='a' && s[0]<='z') || (s[0]>='A' && s[0]<='Z'))
    {
        // if(s[0]>='a' && s[0]<='z')
        // {
        //     l_case_change(s.substr(1, n-1), op+s[0], n-1);
        //     char c=(s[0]-'a')+'A';
        //     l_case_change(s.substr(1, n-1), op+c, n-1);
        // }
        // else{
        //     l_case_change(s.substr(1, n-1), op+s[0], n-1);
        //     char c=(s[0]-'A')+'a';
        //     l_case_change(s.substr(1, n-1), op+c, n-1);
        // }
        
        char c=toupper(s[0]);
        l_case_change(s.substr(1, n-1), op+c, n-1);
        c=tolower(s[0]);
        l_case_change(s.substr(1, n-1), op+c, n-1);
    }
    else{
        l_case_change(s.substr(1, n-1), op+s[0], n-1);
    }
    return;
}

int main()
{
    l_case_change("A1B2", "", 4);
    return 0;
}
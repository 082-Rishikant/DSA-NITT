#include<iostream>
using namespace std;

void subset(string s, string op)
{
    if(s=="")
    {
        cout<<op<<" ";
        return;
    }
    subset(s.substr(1, s.length()-1), op+s[0]);
    subset(s.substr(1, s.length()-1), op);
}

int main()
{
    string s="abc";
    string op="";
    subset(s, op);
    return 0;
}
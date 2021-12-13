#include<iostream>
#include<vector>
using namespace std;

void p_w_caseChange(string s, string op)
{
    if(s=="")
    {
        cout<<op<<" ";
        return;
    }
    p_w_caseChange(s.substr(1, s.length()-1), op+s[0]);
    char c=(s[0]-'a'+'A');
    p_w_caseChange(s.substr(1, s.length()-1), op+c);
    return;
}


int main()
{
    p_w_caseChange("ab","");
    return 0;
}
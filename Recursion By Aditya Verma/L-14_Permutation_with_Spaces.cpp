#include<iostream>
#include<vector>
using namespace std;

void pws(string s, int n, string op)
{
    if(n==0)
    {
        cout<<op<<" ";
        return;
    }
    pws(s, n-1, s);
    pws(s, n-1, s.insert(n, "_"));
    return;
}

void pws2(vector<char> ip, string op)
{
    if(ip.size()==0)
    {
        cout<<op<<" ";
        return;
    }
    char c=ip[0];
    ip.erase(ip.begin());
    pws2(ip, op+c);
    pws2(ip, op+'_'+c);
    return;
}

int main()
{
    // pws("abc", 2, "abc");
    vector<char> ip={'a', 'b', 'c'};
    ip.erase(ip.begin());
    pws2(ip, "a");
    return 0;
}
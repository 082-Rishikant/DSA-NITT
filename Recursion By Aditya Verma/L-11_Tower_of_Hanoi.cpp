#include<iostream>
using namespace std;

void solve(int n, char s, char d, char h)
{
    if(n==0)
    {
        return;
    }
    solve(n-1, s, h, d);
    cout<<"Moving plate no. "<<n<<" from "<<s<<" to "<<d<<endl;
    solve(n-1, h, d, s);
    return;
}

int main()
{
    int n=15;
    solve(n, 'A', 'C', 'B');
    return 0;
}
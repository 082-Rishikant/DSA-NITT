#include<iostream>
using namespace std;

void binary_less_0(string op, int n, int zero, int one)
{
    if(n==0)
    {
        if(zero<=one)
            cout<<op<<" ";
        return;
    }
    if(zero>one)
    {
        binary_less_0(op+'1', n-1, zero, one+1);
    }
    else{
        binary_less_0(op+'0', n-1, zero+1, one);
        binary_less_0(op+'1', n-1, zero, one+1);
    }
    return;
}

void binary_less_0_2(string op, int n, int zero, int one)
{
    if(n==0)
    {
        cout<<op<<" ";
        return;
    }
    if(zero==one)
    {
        binary_less_0_2(op+'1', n-1, zero, one+1);
    }
    else{
        binary_less_0_2(op+'0', n-1, zero+1, one);
        binary_less_0_2(op+'1', n-1, zero, one+1);
    }
    return;
}

int main()
{
    // binary_less_0("", 4, 0, 0);
    binary_less_0_2("", 4, 0, 0);
    return 0;
}
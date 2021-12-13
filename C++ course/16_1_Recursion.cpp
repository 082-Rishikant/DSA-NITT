#include<iostream>
using namespace std;

int power(int n,int p);
int fact(int n);
int fib(int n);

int main()
{
    int n,p;
    cout<<"Enter a number:"<<"\n";
    cin>>n;

    /*
    cout<<"Enter a pow:"<<"\n";
    cin>>p;
    cout<<power(n,p)<<"\n";
    */

    // cout<<fact(n)<<"\n";

    cout<<fib(n)<<"\n";
    return 0;
}

int fib(int n)
{
    if(n==0 || n==1)   
    {
        return n;
    }
    return fib(n-1)+fib(n-2);
    
}

int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    return n*fact(n-1);
}

int power(int n,int p)
{
    if(p==0)
    {
        return 1;
    }
    int pw=power(n,p-1);
    return n*pw;
}
#include<iostream>
#include<math.h>
using  namespace std;

int solve(int n, int k)
{
    if(n==1)
    {
        return 0;
    }
    int mid=pow(2,n-1)/2;
    if(k>mid)
    {
        return !solve(n-1, k-mid);
        // if(ans==0)
        // {
        //     return 1;
        // }
        // return 0;
    }
    return solve(n-1, k);
}

int main()
{
    cout<<solve(3,3);
    return 0;
}
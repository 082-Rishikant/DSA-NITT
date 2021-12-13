#include<iostream>
using namespace std;

bool isPowerOf2(int n)
{
    // here we are checking for a AND in case if n is ZERO!
    // return !(n & (n-1)); 
    return (n  && !(n & (n-1))); 
}

int noOf1BasicMethod(int n)
{
    int count=0;
    while(n>0)
    {
        if(n%2==1)
        {
            count++;
        }
        n=n/2;
    }
    return count; 
}

int noOf1BestMethod(int n)
{
    int count=0;
    while(n>0)
    {
        n=n&(n-1);
        count++;
    }
    return count; 
}

void totalSubsets(int size,int arr[])
{
    for(int i=0;i<(1<<size);i++)
    {
        for(int j=0;j<size;j++)
        {
            if(i&(1<<j))
            {
                cout<<arr[j]<<" ";
            }
            
        }
        cout<<endl;
    }
    
    return; 
}

int main()
{
    // int n;
    // cout<<"Enter a no."<<endl;
    // cin>>n;

    // cout<<isPowerOf2(n)<<endl;

    // cout<<noOf1BasicMethod(n)<<endl;

    // cout<<noOf1BestMethod(n)<<endl;

    int arr[]={1,2,3};
    totalSubsets(3,arr);

    return 0;
}
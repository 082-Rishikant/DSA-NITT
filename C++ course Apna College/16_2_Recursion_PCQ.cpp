#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n)
{
    if(n==1)
    {
        return true;
    }
    /*
    if(arr[0]<=arr[1])
    {
        return isSorted(arr+1,n-1);
    }
    else
    {
        return false;
    }
    */
    return (arr[0]<=arr[1])&&(isSorted(arr+1,n-1));
}

void dec(int n)
{
    if(n==0)
    {
        return;
    }
    cout<<n<<" ";
    dec(n-1);
}

void inc(int n)
{
    if(n==0)
    {
        return;
    }
    inc(n-1);
    cout<<n<<" ";
}

void inc2(int n, int i)
{
    if(i==n)
    {
        cout<<i;
        return;
    }
    cout<<i<<" ";
    inc2(n,i+1);
}

int firstOccur(int arr[], int n, int i, int key)
{
    if(i==n)
    {
        return -1;
    }
    if(arr[i]==key)
    {
        return i;
    }
    return firstOccur(arr, n, i+1, key);
}

int lastOccur(int arr[], int n, int i, int key)
{
    if(i==n)
    {
        return -1;
    }
    int rest=firstOccur(arr, n, i+1, key);
    if(rest!=-1)
    {
        return rest;
    }
    if(arr[i]==key)
    {
        return i;
    }
    return -1;
}

int main()
{
    /*
    int arr[]={1,1,3,5,6,7,3};
    cout<<isSorted(arr,7)<<"\n";
  
    int n;
    cout<<"Enter the number"<<"\n";
    cin>>n;

    dec(n);
    cout<<"\n";

    inc(n);
    cout<<"\n";

    inc2(n,1);
    cout<<"\n";
    */

    int arr[]={1,1,5,3,6,7,4};
    // cout<<firstOccur(arr, 7, 0, 3);

    cout<<lastOccur(arr, 7, 0, 3);
    return 0;
}

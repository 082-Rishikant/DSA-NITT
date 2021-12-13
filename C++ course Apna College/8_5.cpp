#include<bits/stdc++.h>
// #include "bits/stdc++.h"
using namespace std;

void firstRepeatElement(int n, int arr[])
{
    const int N = 100;
    int a[N];
    for(int i=0;i<N;i++)
    {
        a[i]=-1;
    }
    int minIndex = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if(a[arr[i]]!=-1)
        {
            if (a[arr[i]] < minIndex)
            {
                minIndex = a[arr[i]];
            }
        }
        a[arr[i]]=i+1;
    }
    cout << minIndex;
    // cout<<"Error\n";
    return;
}

void subArrSum(int arr[], int n)
{
    int s;
    cout<<"Enter the Sum:\n";
    cin>>s;
    int sum=arr[0];
    int st=0;
    int en=0;
    while(st<n && en<n-1)
    {
        if(sum==s)
        {
            cout<<(st+1)<<" "<<(en+1)<<endl;
            return;
        }
        else if(sum<s)
        {
            en++;
            sum=sum+arr[en];
        }
        else if(st==en && sum>s)
        {
            sum=sum-arr[en];
            st++;
            en++;
            sum=sum+arr[en];
        }
        else
        {
            sum=sum-arr[st];
            st++;
        }
    }
    while(st<n)
    {
        if(sum==s)
        {
            cout<<(st+1)<<" "<<(en+1)<<endl;
            return;
        }
        sum=sum-arr[st];
        st++;
    }
    cout<<"NO\n";
    return;
}

int smallPosMiss(int arr[], int n)
{
    const int N=100;
    int mark[N]={0};
    for(int i=0;i<n;i++)
    {
        if(arr[i]>=0)
        {
            mark[arr[i]]=1;
        }
    }
    for(int i=1;i<N;i++)
    {
        if(mark[i]==0)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout<<"Enter the Size:\n";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    // firstRepeatElement(n, arr);
    // subArrSum(arr, n);
    cout<<smallPosMiss(arr, n)<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n)
{
    int max=arr[0];
    for(int i=1;i<n;i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
        }
    }
    int countArr[max+1]={0};
    for(int i=0;i<n;i++)
    {
        countArr[arr[i]]++;
    }
    for(int i=1;i<max+1;i++)
    {
        countArr[i]=countArr[i]+countArr[i-1];
    }
    int sortedArr[n];
    for(int i=n-1;i>=0;i--)
    {
        int index=--countArr[arr[i]];
        sortedArr[index]=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<sortedArr[i]<<" ";
    }
}

int main()
{
    int n;
    cout<<"\nEnter the size\n";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    countSort(arr, n);
    return 0;
}
#include<iostream>
using namespace std;

// Linear Search
int linearSearch(int n,int arr[],int val)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==val)
        {
            return i;
        }
    }
    cout<<"Element not found"<<endl;
    return -1;
}

// Binary Search
int binarySearch(int n,int arr[],int val)
{
    int s=0;
    int e=n-1,mid;
    while(s<=e)
    {
        mid=(s+e)/2;
        if(arr[mid]>val)
        {
            e=mid-1;
        }
        else if(arr[mid]<val)
        {
            s=mid+1;
        }
        else
        {
            return mid;
        }  
    }
    cout<<"Element not found"<<endl;
    return -1;
}

int main()
{
    int n;
    cin>>n;
    cout<<"Enter the array ascending order";
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int  val;
    cout<<"Enter the element which you want to search"<<endl;
    cin>>val;

    // Linear Search
    cout<<"Searching using Linear Search"<<endl; 
    cout<<linearSearch(n,arr,val)<<endl;

    // Binary Search
    cout<<"Searching using Binary Search"<<endl; 
    cout<<binarySearch(n,arr,val)<<endl;
    return 0;
}
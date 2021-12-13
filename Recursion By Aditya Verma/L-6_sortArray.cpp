#include<iostream>
using namespace std;

void place(int arr[], int size, int temp)
{
    if(size==0 || arr[size-1]<=temp)
    {
        arr[size]=temp;
        return;
    }
    int val=arr[size-1];
    place(arr, size-1, temp);
    arr[size]=val;
    return;
}

void sort(int arr[], int n)
{
    if(n==1)
    {
        return;
    }
    sort(arr, n-1);
    place(arr, n-1, arr[n-1]);
    return;
}

int main()
{
    int arr[]={5,1,7,2,9,3};
    sort(arr, 6);
    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
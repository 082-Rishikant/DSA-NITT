#include<bits/stdc++.h>
using namespace std;
long long totalinv=0;

void Merge(int arr[], int l, int mid, int r)
{
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1], b[n2];
    for(int i=0;i<n1;i++)
    {
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        b[i]=arr[mid+1+i];
    }
    int k=l;
    int i=0; int j=0;
    while(i<n1 && j<n2)
    {
        if(a[i]>b[j])
        {
            totalinv=totalinv+n1-i;
            arr[k]=b[j];
            k++,j++;
            
        }
        else
        {
            arr[k]=a[i];
            k++,i++;
        }
    }
    while (i<n1)
    {
        arr[k]=a[i];
        k++, i++;
    }
    while (j<n2)
    {
        arr[k]=b[j];
        k++, j++;
    }
    return;
}

void mergeSort(int arr[], int l, int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);

        Merge(arr, l, mid, r);
    }
    return;
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
    mergeSort(arr, 0, n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n"<<totalinv;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void Merge(int arr[], int s, int mid, int e)
{
    int n1=mid-s+1;
    int n2=e-mid;
    int a[n1], b[n2]; //make two temporary arrays
    for(int i=0;i<n1;i++)
    {
        a[i]=arr[s+i];
    }
    for(int i=0;i<n2;i++)
    {
        b[i]=arr[mid+1+i];
    }

    int i=0;
    int j=0;
    int k=s;
    while(i<n1 && j<n2)
    {
        if(a[i]>b[j])
        {
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
}

void mergeSort(int arr[], int s, int e)
{
    if(s>=e)
    {
        return;
    }
    int mid=(s+e)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);

    Merge(arr, s, mid, e);
}

int main()
{
    int n;
    cout<<"\nEnter the size of the array\n";
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);

    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void dnfSort(int arr[], int mid, int high)
{
    int low=mid;
    while (mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else if(arr[mid]==2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
        else
        {
            cout<<"You have entered a element other than 0, 1 ,2 \n";
            break;
        }
    }
    return;
}

int main()
{
    int n;
    cout<<"Enter the size:\n";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    dnfSort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
#include <iostream>
using namespace std;

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
    return;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        // for (int j = i; j > 0; j--)
        // {
        //     if (arr[j - 1] > arr[j])
        //     {
        //         swap(arr[j], arr[j - 1]);
        //     }
        // }

        // int j=i;
        // while (arr[j-1]>arr[j] && j>0)
        // {
        //     swap(arr[j],arr[j - 1]);
        //     j--;
        // }

        int j=i;
        int current = arr[j];
        while (arr[j-1]>current && j>0)
        {
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=current;
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
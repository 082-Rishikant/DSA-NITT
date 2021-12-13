#include <iostream>
using namespace std;

void longestArithmaticArray(int n, int arr[])
{
    int max_l = 1, cur_l = 1;
    int p_diff = arr[0] - arr[1];
    for (int i = 1; i < n; i++)
    {
        if (p_diff == (arr[i-1] - arr[i]))
        {
            cur_l++;
        }
        else
        {
            if (max_l < cur_l)
            {
                max_l = cur_l;
            }
            cur_l = 2;
            p_diff = arr[i-1] - arr[i];
        }
    }
    if (max_l < cur_l)
    {
        max_l = cur_l;
    }
    cout << (max_l);
}

void longestArithmaticArray2(int n, int arr[])
{
    int max_l = 1, cur_l = 1;
    int p_diff = arr[0] - arr[1];
    for (int i = 1; i < n; i++)
    {
        if (p_diff == (arr[i-1] - arr[i]))
        {
            cur_l++;
            max_l=max(max_l, cur_l);
        }
        else
        {
            cur_l = 2;
            p_diff = arr[i-1] - arr[i];
        }
    }
    cout << (max_l);
}

int recordBreaker(int n,int arr[])
{
    int p_max=-1,n_rbday=0;
    int i;
    for(i=0;i<=n-2;i++)
    {
        if(arr[i]>p_max)
        {
            p_max=arr[i];
            if(arr[i]>arr[i+1])
            {
                n_rbday++;
            }
        }
    }
    if(arr[i]>p_max)
    {
        n_rbday++;
    }
    return n_rbday;
}

int recordBreaker2(int n,int arr[])
{
    int p_max=-1,n_rbday=0;
    int i;
    for(i=0;i<=n-1;i++)
    {
        if(arr[i]>p_max)
        {
            p_max=arr[i];
            if(arr[i]>arr[i+1])
            {
                n_rbday++;
            }
        }
    }
    return n_rbday;
}

void maxTilli(int arr[], int n)
{
    int max=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
        else
        {
            arr[i]=max;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

void sumAllSubArray(int arr[], int n)
{
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum+=arr[j];
            cout<<sum<<" ";
        }
        cout<<endl;
        sum=0;
    }
    
}

int main()
{
    int n;
    cout<<"\nEnter the size:\n";
    cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // cout<<recordBreaker(n,arr)<<endl;

    int arr[n+1];
    arr[n]=-1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<recordBreaker2(n,arr)<<endl;

    // longestArithmaticArray(n, arr);
    // longestArithmaticArray2(n, arr);


    // maxTilli(arr,n);

    // sumAllSubArray(arr, n);


    return 0;
}
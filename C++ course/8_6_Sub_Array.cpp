#include<bits/stdc++.h>
using namespace std;

void subArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            for(int k=i;k<=j;k++)
            {
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
    }
}

int maxSubArrBrute(int arr[], int n)
{
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int sum=0;
            for(int k=i;k<=j;k++)
            {
                sum+=arr[k];
            }
            if(sum>max)
            {
                max=sum;
            }
        }
    }
    return max;
}

int maxSubArrCumulativeSum(int arr[], int n)
{
    int currSum[n+1];
    currSum[0]=0;
    for(int i=0;i<n;i++)
    {
        currSum[i+1]=currSum[i]+arr[i];
    }
    
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if((currSum[j]-currSum[i])>max)
            {
                max=currSum[j]-currSum[i];
            }
        }
    }
    return max;
}

int maxSubArrKadaneAlgo(int arr[], int n)
{
    int maxSum=INT_MIN;
    int currSum=0;
    for(int i=0;i<n;i++)
    {
        currSum+=arr[i];
        maxSum=max(currSum, maxSum);
        if(currSum<0)
        {
            currSum=0;
        }
    }
    return maxSum;
}

int maxSubCircularArrKadaneAlgo(int arr[], int n)
{
    int maxSum=INT_MIN;
    int currSum=0;
    int i=0;
    int k=0;
    while (i<n && k<(2*n-1))
    {
        i++;
        currSum=currSum+arr[k%n];
        k++;
        maxSum=max(currSum, maxSum);
        cout<<maxSum<<" "<<currSum<<endl;
        if(currSum<0)
        {
            currSum=0;
            i=0;
        }
    }
    return maxSum;
}

bool pairSumBruteForce(int arr[], int n, int k)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==k)
            {
                cout<<i<<" "<<j<<endl;
                return true;
            }
        }
    }
    return false;
}

bool pairSum(int arr[], int n, int k)
{
    sort(arr, arr+n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int low=0;
    int high=n-1;
    while(low<high)
    {
        if(arr[low]+arr[high]>k)
        {
            high--;
        }
        else if(arr[low]+arr[high]<k)
        {
            low++;
        }
        else
        {
            cout<<low<<" "<<high<<endl;
            return true;
        }   
    }
    return false;
}

int main()
{
    int n=6;
    int arr[]={1,2,6,4,8,-4};

    // subArray(arr, n);
    // cout<<maxSubArrBrute(arr, n)<<endl;
    // cout<<maxSubArrCumulativeSum(arr, n)<<endl;
    // cout<<maxSubArrKadaneAlgo(arr, n)<<endl;
    // cout<<maxSubCircularArrKadaneAlgo(arr, n)<<endl;
    // cout<<pairSumBruteForce(arr, n, 8)<<endl;
    cout<<pairSum(arr, n, 8)<<endl;

    return 0;
}
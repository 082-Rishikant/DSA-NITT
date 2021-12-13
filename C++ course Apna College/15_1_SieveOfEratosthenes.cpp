#include<iostream>
using namespace std;

void sievePrime(int n)
{
    int arr[n+1]={0};
    for(int i=2;i<=n;i++)
    {
        if(arr[i]==0)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                arr[j]=1;
            }
        }
    }

    for(int i=2;i<=n;i++)
    {
        if(arr[i]==0)
        {
            cout<<i<<" ";
        }
    }
    return;
}

void leastPrimeFactors(int n)
{
    int arr[n+1];
    for(int i=2;i<=n;i++)
    {
        arr[i]=i;
    }

    for(int i=2;i<=n;i++)
    {
        if(arr[i]==i)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                if(arr[j]==j)
                {
                    arr[j]=i;
                }
            }
        }
    }

    while(n!=1)
    {
        cout<<arr[n]<<" ";
        n=n/arr[n];
    }
    return;
}

int main()
{
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    // sievePrime(n);
    leastPrimeFactors(n);

    return 0;
}
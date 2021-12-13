#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool bruteForceApproach(vector<int> a, int target) // O(n*n*n)
{
    int n =a.size();
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if((a[i]+a[j]+a[k])==target)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool optimizedApproach(vector<int> a, int target)
{
    int n=a.size();
    sort(a.begin(), a.begin()+n);
    int i=0, j=0;
    for(int k=0;k<n-2;k++)
    {
        i=k+1;j=n-1;
        while(i!=j)
        {
            if(a[i]+a[j]==target-a[k])
            {
                return true;
            }
            else if (a[i]+a[j]>target-a[k])
            {
                j--;
            }
            else
            {
                i++;
            } 
        }
    }
    return false;
}


int main()
{
    vector<int>  a{12, 3, 7, 1, 6, 9};
    int target=28;

    // cout<<bruteForceApproach(a, target); // O(n*n*n)
    cout<<optimizedApproach(a, target);
}
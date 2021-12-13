#include<iostream>
#include<vector>
#include <algorithm>
#include<string.h>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>

const int N=1e9+7;
using namespace std;

void total(string arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        string s=arr[i];
        int sum=0;
        for (int j = 0; j < s.length(); j++)
        {
            int n=(s[j]-'0');
            sum+=n;
            // cout<<n<<" ";
        }
        cout<<sum<<" ";
    }
}

int main()
{
    int n;cin>>n;
    string arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    total(arr, n);
    return 0;
}
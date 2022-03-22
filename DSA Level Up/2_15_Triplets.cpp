#include<iostream> 
#include<vector>
#include<algorithm>
using namespace std;

void twoP(vector<int> arr, vector<vector<int>> &ans, int idx, int n, int target)
{
    int i=idx, j=n-1;
    while(i<j)
    {
        if(arr[i]+arr[j]==target)
        {
            ans.push_back({arr[idx-1], arr[i], arr[j]});
            i++; j--;
        }
        else if(arr[i]+arr[j]>target)
        {
            j--;
        }
        else{
            i++;
        }
    }
    return;
}

int main()
{
    vector<int> arr{2,1,3,4,9,6,7,8,5,15};
    vector<vector<int>> ans;
    int n=10;
    int s=18;
    sort(arr.begin(), arr.end());
    for(int i=0;i<n-2;i++)
    {
        twoP(arr, ans, i+1, n, s-arr[i]);
    }
    for(vector<int> vec:ans)
    {
        for(int it:vec)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}
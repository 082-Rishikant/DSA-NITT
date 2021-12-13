#include<iostream>
#include<vector>
using namespace std;

int find_Unique(vector<int> arr);
void find_2_Unique(vector<int> arr);
int find_Unique_among_3(vector<int> arr);

int main()
{
    vector<int> arr1{1,2,3,4,5,4,3,2,1};
    vector<int> arr2{1,2,3,4,7,5,4,3,2,1};
    vector<int> arr3{1,2,1,2,3,4,7,4,4,3,2,3,1};
    cout<<find_Unique(arr1)<<endl;
    find_2_Unique(arr2);
    cout<<find_Unique_among_3(arr3)<<endl;
    return 0;
}

int find_Unique(vector<int> arr)
{
    int ans=0;
    for(int it:arr)
    {
        ans=ans^it;
    }
    return ans;
}

void find_2_Unique(vector<int> arr)
{
    int ans=0;
    for(int it:arr)
    {
        ans=ans^it;
    }
    // cout<<"ans:"<<ans<<endl;
    int pos=0;
    int setbit=0;
    while(setbit==0)
    {
        setbit=ans & (1<<pos);
        pos++;
    }
    // cout<<"pos:"<<pos<<endl;
    pos--;
    int prevAns=ans;
    for(int i:arr)
    {
        if((i&(1<<pos))!=0)
        {
            ans=ans^i;
        }
    }
    cout<<ans<<" "<<(ans^prevAns)<<endl;
    return;
}

int find_Unique_among_3(vector<int> arr)
{
    int n=arr.size();
    int ans=0;
    for(int i=0;i<64;i++)
    {
        int sum=0;
        for (int j = 0; j < n; j++)
        {
            if((arr[j]&(1<<i))!=0)
            {
                sum++;
            }
        }
        if(sum%3!=0)
        {
            ans=ans|(1<<i);
        }
    }
    return ans;
}
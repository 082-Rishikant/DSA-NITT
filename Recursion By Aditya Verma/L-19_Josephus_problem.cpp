#include<iostream>
#include<vector>
using namespace std;
 
int josephus(vector<int> &vec, int k, int idx, int  n) 
{
    if(n==1)
    {
        return vec[0];
    }
    int temp=(idx+k-1)%n;
    vec.erase(vec.begin()+temp);
    idx=temp;
    int ans=josephus(vec, k, idx, n-1);
    return ans;
}

int main()
{
    vector<int> vec={1,2,3,4,5,6,7};
    cout<<josephus(vec, 3, 0, 7);
    return 0;
}
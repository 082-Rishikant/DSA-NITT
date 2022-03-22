#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main() //O(n) time and O(1e6) space
{
    // vector<int> vec={5,4,3,2,1};
    vector<int> vec={10,11,5,4,3,2,1};

    int n=vec.size();
    vector<int> hsh(1e4, -1);
    for(int i=0;i<n;i++)
    {
        hsh[vec[i]]=i;
    }
    int idx=0,swaps=0;
    for (int i = 0; i < 1e4; i++)
    {
        if(hsh[i]!=-1)
        {
            if(hsh[i]!=idx)
            {
                int temp1=vec[idx];
                int temp2=vec[hsh[i]];
                swap(vec[idx], vec[hsh[i]]);
                swap(hsh[temp1], hsh[temp2]);
                idx++;
                swaps++;
            }
            else{
                idx++;
            }
        }
    }
    cout<<swaps;
}
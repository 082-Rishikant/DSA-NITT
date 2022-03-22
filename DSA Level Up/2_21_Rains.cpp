#include<iostream>
#include<vector>
using namespace std;

int rains(vector<int> vec)
{
    int n=vec.size();
        int water=0;
        vector<int> left(n,0);
        vector<int> right(n, 0);
        left[0]=vec[0];
        right[n-1]=vec[n-1];
        for(int i=1;i<n;i++)
        {
            left[i]=max(left[i-1], vec[i]);
            right[n-1-i]=max(right[n-1-(i-1)], vec[n-1-i]);
        }
        for(int i=0;i<n;i++)
        {
            water=water+min(left[i], right[i])-vec[i];
        }
    return water;
}

int main()
{
   vector<int> vec{1,2,0,1,3,2,0,1,3}; // insert first 0 at 0th position
   cout<<rains(vec);
   return 0;
}
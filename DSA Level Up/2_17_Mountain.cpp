#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> vec;
    vec={5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    int i=1,p=-1;
    int maxi=0;
    while (i<(16-1))
    {
        // int l=0,r=0;
        int count=0;
        if(vec[i]>vec[i-1] && vec[i]>vec[i+1])
        {
            p=i;
            while (p>0 && vec[p]>vec[p-1])
            {
                count++;
                p--;
            }
            while (i<(16-1) && vec[i]>vec[i+1])
            {
                count++;
                i++;
            }
            maxi=max(maxi, count); 
        }
        else
            i++;
    }
    cout<<maxi+1;
    return 0;
}
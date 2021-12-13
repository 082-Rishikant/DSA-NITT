#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &vec, int n, int i)
{
    int large=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && vec[l]>vec[large])
    {
        large=l;
    }
    if(r<n && vec[r]>vec[large])
    {
        large=r;
    }
    if(large!=i)
    {
        swap(vec[i], vec[large]);

        heapify(vec, n, large);
    }
    return;
}

void heapSort(vector<int> &vec)
{
    int n=vec.size();
    for(int i=((n/2)-1);i>=0;i--)
    {
        heapify(vec, n, i);
    }

    for(int i=n-1;i>0;i--)
    {
        swap(vec[0], vec[i]);

        heapify(vec, i, 0);
    }
    return;
}

int main()
{
    vector<int> vec{1,2, 3, 5, 1, 9};
    for(int i:vec)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    heapSort(vec);
    for(int i:vec)
    {
        cout<<i<<" ";
    }
    return 0;
}
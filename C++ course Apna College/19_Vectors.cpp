#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    // Vector
    /*
    vector<int> v;
    v.push_back(1);
    v.push_back(7);
    v.push_back(3);
    v.push_back(4);
    //first method to print the vector
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i];
    }
    cout<<endl;

    //Second method to print the Vector
    vector<int>::iterator it;
    for(it=v.begin();it<v.end();it++)
    {
        cout<<*it;
    }
    cout<<endl;

    v.pop_back();  //to delete a element from the last.

    //Second method to print the Vector
    for(auto element:v)
    {
        cout<<element;
    }
    cout<<"\n";
    //other ways to initialize the Vector
    vector<int> v2(3,30);  //30,30,30
    for(auto element:v2)
    {
        cout<<element;
    }
    cout<<endl;
    swap(v,v2);
    for(auto element:v2)
    {
        cout<<element;
    }
    cout<<endl;
    sort(v2.begin(),v2.end());
    for(auto element:v2)
    {
        cout<<element;
    }
    cout<<endl;
    */

    // Pair

    pair<int , char> p1;
    p1.first=2;
    p1.second='t';
    cout<<p1.first<<"  "<<p1.second<<endl<<"\n";

    // Vector of Pair
    vector<pair<int,int>> v3;
    int arr[5]={76,36,48,19,60};
    for(int i=0;i<5;i++)
    {
        /* //another way to insert pairs into vector
        pair<int, int> p2;
        p2.first=arr[i];
        p2.second=i;
        v3.push_back(p2);
        */
        v3.push_back(make_pair(arr[i],i));
    }
    sort(v3.begin(),v3.end());
    for(int i=0;i<5;i++)
    {
        arr[v3[i].second]=i;
    }
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
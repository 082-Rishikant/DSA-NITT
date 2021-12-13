// #include<bits/stdc++.h>
#include <iostream>
#include <queue>
// #include<vector>
using namespace std;
priority_queue<int, vector<int>> maxh;
priority_queue<int, vector<int>, greater<int>> minh;

void insertVal(int d)
{
    if (maxh.size() == minh.size())
    {
        if (maxh.size() == 0)
        {
            maxh.push(d);
            return;
        }
        else if (d > maxh.top())
        {
            minh.push(d);
        }
        else
        {
            maxh.push(d);
        }
    }
    else
    {
        if (maxh.size() > minh.size())
        {
            if (d > maxh.top())
            {
                minh.push(d);
            }
            else
            {
                int temp = maxh.top();
                maxh.pop();
                maxh.push(d);
                minh.push(temp);
            }
        }
        else
        {
            if (d > minh.top())
            {
                int temp = minh.top();
                minh.pop();
                minh.push(d);
                maxh.push(temp);
            }
            else
            {
                maxh.push(d);
            }
        }
    }
}

int main()
{
    for (int i = 0; i < 6; i++)
    {
        int val;
        cin >> val;
        insertVal(val);
        if (maxh.size() == minh.size())
        {
            cout << (maxh.top() + minh.top()) / 2.0 <<endl;
        }
        else if(maxh.size() > minh.size())
        {
            cout << maxh.top() <<endl;
        }
        else
        {
            cout << minh.top() <<endl;
        }
    }
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"please enter the number :"<<endl;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n-i; j++)
        {
            cout<<j<<" ";
        }
        cout<<"\n";
        
    }
    

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if ((i+j)%2==0)     
            {
                cout<<1<<" ";
            }
            else
            {
                cout<<0<<" ";
            }
            
            
            
        }
        cout<<"\n";
        
    }

    for (int k = 1; k <= n; k++)
    {
        for (int s = 0; s < n-k; s++)
        {
            cout<<" ";
        }
        
        for (int m = 1; m <= n; m++)
        {
            cout<<"*  ";
        }
        cout<<endl;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n-i; j++)
        {
            cout<<" ";
        }
        for (int k = 1; k <= i; k++)
        {
            cout<<k<<" ";
        }
        cout<<endl;
        
    }
    
    
    return 0;
}
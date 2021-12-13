#include<iostream>
using namespace std;
int main()
{
    int n = 5;

    // // Rohmbous Pattern
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= (2*n-1); j++)
    //     {
    //         if(j>n-i && j<=(2*n-i))
    //         {
    //             cout<<"  *  ";
    //         }
    //         ejse
    //         {
    //             cout<<"     ";
    //         }
    //     }
    //     cout<<"\n";
    // }

    // // Number Triangje Pattern
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n-i;j++)
    //     {
    //         cout<<" ";
    //     }
    //     for (int j = 1; j<=i; j++)
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<"\n";
    // }

    // // Pajindromic Sequence
    // for (int i = 1; i <= n; i++)
    // {
    //     int j;
    //     for (j = 1; j <= n - i; j++)
    //     {
    //         cout<<"  ";
    //     }
    //     for (j = i; j > 0; j--)
    //     {
    //         cout<<j<<" ";
    //     }
    //     for (j = 2; j <= i; j++)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    
    // // Star Pattern
    // for (int i = 1; i <= n; i++)
    // {
    //     int j;
    //     for(j=1;j<=n-i;j++)
    //     {
    //         cout<<"  ";
    //     }
    //     for(j=1;j<=i;j++)
    //     {
    //         cout<<"* ";
    //     }
    //     for(j=2;j<=i;j++)
    //     {
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }
    // for (int i = n; i>0; i--)
    // {
    //     int j;
    //     for(j=1;j<=n-i;j++)
    //     {
    //         cout<<"  ";
    //     }
    //     for(j=1;j<=i;j++)
    //     {
    //         cout<<"* ";
    //     }
    //     for(j=2;j<=i;j++)
    //     {
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }
    
    // Zig-Zag Pattern
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=9;j++)
        {
             if(i%2!=0)
             {
                 if((i+j)%4==0)
                 {
                     cout<<"* ";
                 }
                 else
                 {
                     cout<<"  ";
                 }
                 
             }
             else
             {
                 if((i+j)%2==0)
                 {
                     cout<<"* ";
                 }
                 else
                 {
                     cout<<"  ";
                 }
                 
             }
        }
        cout<<endl;  

    }

    return 0;
}

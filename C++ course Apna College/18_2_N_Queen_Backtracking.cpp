#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, int n, int** solArr)
{
    // if(i<n && j<n) // We can avoid this condition because we have already did it in N_queen function
    // {
        for(int row=i-1;row>=0;row--)
        {
            if(solArr[row][j]==1)
            {
                return false;
            }
        }
        int row=i,col=j;
        while (col<n && row>=0)
        {
            if(solArr[row][col]==1)
            {
                return false;
            }
            row--;
            col++;
        }
        row=i,col=j;
        while (row>=0 && col>=0)
        {
            if(solArr[row][col]==1)
            {
                return false;
            }
            row--;
            col--;
        }
        
    // }
    // else
    // {
    //     return false;
    // }
    return true;
}

bool N_queen(int i, int j, int n, int** solArr)
{
    if(i>=n) // this condition also checked in isSafe() we can avoid this check in isSafe()
    {
        return true;
    }
    for(int col=j;col<n;col++)
    {
        if(isSafe(i, col, n, solArr))
        {
            solArr[i][col]=1;
            if(N_queen(i+1, 0, n, solArr))
            {
                return true;
            }
            solArr[i][col]=0;
        }
    }
    return false;
}

int main()
{
    int n;
    cout<<"\nEnter the size:\n";
    cin>>n;
    int** solArr=new int*[n];
    for(int i=0;i<n;i++)
    {
        solArr[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            solArr[i][j]=0;
        }
    }
    cout<<endl;
    if(N_queen(0, 0, n, solArr))  // Here We can also remove one parameter the second one that is colom(int j)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<solArr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
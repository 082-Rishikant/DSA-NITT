#include<iostream>
#include<vector>
using namespace std;
const int N=1e5;;
int main()
{
    vector<vector<int>> adjL={{0,5,N,10},
                              {N,0,3,N},
                              {N,N,0,1},
                              {N,N,N,0}
                             };
    int n=adjL.size();
    for(int k=0;k<n;k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adjL[i][j]=min(adjL[i][j], adjL[i][k]+adjL[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<adjL[i][j]<<" ";
        }
        cout<<endl;
    }
    // cout<<"Enter your source and destination:\n";
    // int u,v;cin>>u>>v;
    // cout<<adjL[u][v];
    
    return 0;
}
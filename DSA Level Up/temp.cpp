#include<bits/stdc++.h>
using namespace std;


int BFS(int i, int j, int r, int c, vector<vector<bool>> &vis, vector<vector<int> > grid){
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j]=true;
    int t=1;
    
    while(!q.empty()){
        pair<int, int> temp=q.front();
        q.pop();
        int dx[]={-1, 0, 1, 0};
        int dy[]={0, 1, 0, -1};
    
        for(int idx=0;idx<4;idx++){
            int ni=temp.first+dx[idx]; int nj=temp.second+dy[idx];
            
            if(ni>=0 && ni<r && nj>=0 && nj<c && grid[ni][nj]==1 && !vis[ni][nj]){
                q.push({ni, nj});
                vis[ni][nj]=true;
                t++;
            }
        }
    }
    return t;
}

int largest_island(vector<vector<int> > grid){
    // cout<<"hii1";
    //return the size of largest island in grid
    int maxi=0; int r=grid.size();  int c=grid[0].size();
    vector<vector<bool>> vis(r, vector<bool>(c, false));
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(!vis[i][j] && grid[i][j]==1)
            {
              cout<<i<<" "<<j<<" ";
              int temp=BFS(i, j, r, c, vis, grid);
              cout<<temp<<" \n";
              maxi=max(maxi, temp);
            }
        }
    }
    
    return maxi;
}

int main(){
  vector<vector<int>> grid={
    {1, 0, 0, 1, 0}, 
    {1, 0, 1, 0, 0}, 
    {0, 0, 1, 0, 1}, 
    {1, 0, 1, 1, 1}, 
    {1, 0, 1, 1, 0}
  };

  cout<<largest_island(grid);

  return 0;
}
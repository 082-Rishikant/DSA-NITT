#include<iostream>
#include<vector>
#include<set>
#include<climits>
#include<algorithm>

#define intl long long int

using namespace std;

vector<pair<int,int>> findIndex(int i, int j){
  vector<pair<int,int>> a={{i-1, j}, {i, j+1}, {i+1, j}, {i, j-1}};
  return a;
}

intl solve(vector<vector<int> >grid, vector<vector<bool>> vis, int i, int j, int r, int c){
    if(i==r-1 && j==c-1)
        return grid[i][j];
    
    vis[i][j]=true;
    
    vector<pair<int, int>> boxidx=findIndex(i, j);
    intl temp=INT_MAX;
    
    for(auto it:boxidx){
        int ni=it.first;
        int nj=it.second;
        
        if((ni>=0 && ni<r) && (nj>=0 && nj<c) && !vis[ni][nj]){
            temp=min(temp, (solve(grid, vis, ni, nj, r, c)+grid[i][j]));
        }
    }
    vis[i][j]=false;
    return temp;
}

int shortest_path(vector<vector<int> > grid){
    //return the shortest path len
    int r=grid.size();
    int c=grid[0].size();
    vector<vector<bool>> vis(r, vector<bool>(c, false));
    return solve(grid, vis, 0, 0, r, c);
}

int main(){
    vector<vector<int>> grid={
        {31, 100, 65, 12, 18},
        {10, 13,  47, 157,6},
        {100,113, 174,11, 33},
        {88, 124, 41, 20, 140},
        {99, 32, 111, 41, 20}
    };

    cout<<shortest_path(grid);

    cout<<" "<<min(4, INT_MAX+2);

    return 0;
}
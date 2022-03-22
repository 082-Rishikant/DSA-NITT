#include<iostream>
#include<vector>
#include<set>
#include<climits>
#include<algorithm>

using namespace std;

class node{
    public:
        int i;
        int j;
        int distance;
        node(int i, int j, int d){
            this->i=i;
            this->j=j;
            this->distance=d;
        }
};

class compare{
    public:
    bool operator()(node a, node b){
        return a.distance<=b.distance;
    }
};

vector<pair<int,int>> findIndex(int i, int j){
  vector<pair<int,int>> a={{i-1, j}, {i, j+1}, {i+1, j}, {i, j-1}};
  return a;
}

void solve(vector<vector<int> >grid, vector<vector<int>> &dist, int r, int c){
   set<node, compare> st;
   dist[0][0]=grid[0][0];
   st.insert(node(0, 0, dist[0][0]));
   
   while(!st.empty()){
       node temp=(*st.begin());
       st.erase(st.begin());
       
       vector<pair<int, int>> boxid=findIndex(temp.i, temp.j);
       
       for(auto it:boxid){
           int ni=it.first;
           int nj=it.second;
           if(ni>=0 && ni<r && nj>=0 && nj<c){
               if(dist[ni][nj]>(temp.distance+grid[ni][nj])){
                   dist[ni][nj]=temp.distance+grid[ni][nj];
                   st.insert(node(ni, nj, dist[ni][nj]));
               }
           }
       }
   }
}

int shortest_path(vector<vector<int> > grid){
    //return the shortest path len
    int r=grid.size();
    int c=grid[0].size();
    vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
    solve(grid, dist, r, c);
    return dist[r-1][c-1];
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
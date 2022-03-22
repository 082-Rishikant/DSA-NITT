#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<char, vector<pair<int, int>>> mp;
string words[]={"SNAKE", "FOR", "QUEZ", "SNACK", "SNACKS", "SENS", "TUNES", "CAT"};

vector<pair<int, int>> boxId(int i, int j){
  vector<pair<int, int>> boxid={{i-1, j-1}, {i-1, j}, {i-1, j+1}, {i, j-1}, {i, j+1}, {i+1, j-1}, {i+1, j}, {i+1, j+1}};
  return boxid;
}

bool helper(string s, int idx, int i, int j, int r, int c, vector<vector<bool>> vis)
{ 
  cout<<"hii \n";
  if(idx>=s.length())
    return true;

  vector<pair<int, int>> boxid=boxId(i, j);
  for(auto it:boxid){
    int rw=it.first; int colm=it.second;
    if((rw>=0 && rw<r) && (colm>=0 && colm<c)){
      if(words[rw][colm]==s[idx] && vis[rw][colm]==false){
        vis[rw][colm]=true;
        if(helper(s, idx+1, rw, colm, r, c, vis))
          return true;
        vis[rw][colm]=false;
      }
    }
  }

  return false;
}

vector<string> solve(int n, string words[], int r, int c){
  vector<string> ans;
  for(int i=0;i<n;i++){
    string s=words[i];  
    vector<vector<bool>> vis(r, vector<bool>(c, false));

    bool flag=false;
    for(auto it:mp[s[0]]){
      vis[it.first][it.second]=true;
      if(helper(s, 1, it.first, it.second, r, c, vis))
      {
    
        flag=true;
        break;
      }
      vis[it.first][it.second]=false;
    }

    if(flag)
      ans.push_back(s);
  }

  return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n=7;

  int r=3, c=4;
  vector<vector<char>> vec={{'S','E','R','T'}, {'U', 'N', 'K', 'S'}, {'T', 'C', 'A', 'T'}};

  for(int i=0;i<vec.size();i++){
    for(int j=0;j<vec[i].size();j++){
      mp[vec[i][j]].push_back({i, j});
    }
  }

  vector<string> ans=solve(n, words, r, c);

  for(auto it:ans){
    cout<<it<<" ";
  }


  return 0;
}
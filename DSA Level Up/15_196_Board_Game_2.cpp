#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int n = 8;
int r = 3, c = 4;
vector<vector<char>> vec = {{'S', 'E', 'R', 'T'}, {'U', 'N', 'K', 'S'}, {'T', 'C', 'A', 'T'}};
string words[] = {"SNAKE", "FOR", "QUEZ", "SNACK", "SNACKS", "SENS", "TUNES", "CAT"};
// 2-make a output vector
unordered_set<string> ans;


class node
{
public:
  char data;
  bool isTerminal;
  unordered_map<char, node *> mp;
  string word;
  node(char c)
  {
    this->data = c;
    isTerminal = false;
    word = "";
  }
};

class trie
{
public:
  node *root;
  trie()
  {
    root = new node('\0');
  }

  void addword(string word)
  {
    node *temp = root;
    for (int i = 0; i < word.length(); i++)
    {
      if (temp->mp.count(word[i]) == 0)
      {
        temp->mp[word[i]] = new node(word[i]);
      }
      temp = temp->mp[word[i]];
    }
    temp->isTerminal = true;
    temp->word = word;
  }

  void helper(node *temp)
  {
    cout<<temp->word<<" \n";
    for (auto it : temp->mp)
    {
      cout << it.first << " ";
      helper(it.second);
    }
  }

  void print()
  {
    helper(root);
  }
};

vector<pair<int,int>> findIndex(int i, int j){
  vector<pair<int,int>> a={{i-1, j-1}, {i-1, j}, {i-1, j+1}, {i, j-1}, {i, j+1}, {i+1, j-1}, {i+1, j}, {i+1, j+1}};

  return a;
}

void DFS(int i, int j, node* root, vector<vector<bool>> &visited){
  char ch=vec[i][j];

  node* temp=root;
  temp=temp->mp[ch];


  if(temp->isTerminal){
    ans.insert(temp->word);
  }
  
  visited[i][j]=true;

  vector<pair<int, int>> boxidx=findIndex(i, j);

  for(auto it:boxidx){
    int ni=it.first;  int nj=it.second;
    if((ni>=0 && ni<r) && (nj>=0 && nj<c)){
      if(temp->mp.count(vec[ni][nj])!=0 && !visited[ni][nj]){
        DFS(ni, nj, temp, visited);
      }
    }
  }
  
  visited[i][j]=false;
  return;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  //1- make the Trie DS
  trie t;
  for(int i=0;i<n;i++){
    t.addword(words[i]);
  }

  // t.print();

  //3- DFS to find the ans for every index in board;
  vector<vector<bool>> visited(r, vector<bool>(c, false));
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      if(t.root->mp.count(vec[i][j])!=0){
        DFS(i, j, t.root, visited);
      }
    }
  }

  // 4- Print the output
  for(auto it:ans){
    cout<<it<<" ";
  }

  return 0;
}
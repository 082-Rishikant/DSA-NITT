#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
using namespace std;

class Graph{
  public:
    int n;//#vertex
    list<int> *l;
    bool * vis;
    Graph(int n){
      this->n=n;
      l=new list<int>[n];
      vis=new bool[n]{false};
    }

    void connectNodes(int i, int j, bool isDir=false){
      l[i].push_back(j);
      if(!isDir)
        l[j].push_back(i);
    }

    void printAdjList(){
      for(int i=0;i<n;i++){
        cout<<i<<"-->  ";
        for(int node:l[i])
          cout<<node<<" ";
        cout<<endl;
      }
    }

    void DFS(int root){
      vis[root]=true;
      cout<<root<<" ";
      for(auto it:l[root]){
        if(!vis[it]){
          DFS(it);
        }
      }
      return;
    }

};

int main()
{
  int n=5;

  Graph g(n);
  g.connectNodes(0,1);
  g.connectNodes(1,2);
  g.connectNodes(2,3);
  g.connectNodes(2,0);
  g.connectNodes(4,0);
  g.connectNodes(4,1);
  g.connectNodes(4,3);

  g.DFS(4);

  // g.printAdjList();
  return 0;
}
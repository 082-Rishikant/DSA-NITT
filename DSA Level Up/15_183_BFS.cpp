#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

class Graph{
  public:
    int n;//#vertex
    list<int> *l;
    Graph(int n){
      this->n=n;
      l=new list<int>[n];
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

    void printBFS(int root){
      queue<int> q; vector<bool> vis(n, false);

      q.push(root); q.push(-1);  vis[root]=true;

      while (!q.empty())
      {
        int temp=q.front();
        q.pop();
        if(temp==-1 && q.size()>0){
          cout<<endl;
          q.push(-1);
          continue;
        }
        if(temp==-1)
          break;
        cout<<temp<<" ";
        for(auto it:l[temp]){
          if(!vis[it]){
            q.push(it);
            vis[it]=true;
          }
        }
      }
    }
};

int main()
{
  int n=4;

  Graph g(n);
  g.connectNodes(0,1);
  g.connectNodes(1,2);
  g.connectNodes(2,3);
  g.connectNodes(2,0);

  // g.printAdjList();

  g.printBFS(3);
  return 0;
}
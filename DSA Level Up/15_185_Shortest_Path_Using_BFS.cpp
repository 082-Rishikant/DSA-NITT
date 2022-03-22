#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

class Graph{
  public:
    int n;
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

    void printAdjcl(){
      for(int i=0;i<n;i++){
        cout<<i<<"-->  ";
        for(int it:l[i])
          cout<<it<<" ";
        cout<<endl;
      }
    }

    void shortPathBFS(int root, int d){
      queue<int> q;
      vector<bool> vis(n, false);
      vector<int> dist(n, 0);
      vector<int> parent(n);
      dist[root]=0; parent[root]=root; vis[root]=true;
      q.push(root);
      while (!q.empty())
      {
        int temp=q.front();
        q.pop();
        cout<<"The Distance from "<<root<<" to "<<temp<<" is: "<<dist[temp]<<endl;
        for(int it:l[temp]){
          if(!vis[it]){
            q.push(it);
            parent[it]=temp;  vis[it]=true; dist[it]=dist[temp]+1;
          }
        }
      }

      int temp=d; cout<<endl;
      while(temp!=root){
        cout<<temp<<" <-- ";
        temp=parent[temp];
      }
      cout<<root;
    }
};

int main()
{
  Graph g(4);

  g.connectNodes(0, 1);
  g.connectNodes(1, 2);
  g.connectNodes(2, 3);
  g.connectNodes(2, 1);

  // g.printAdjcl();

  g.shortPathBFS(1, 3); //between source and destination

  return 0;
}
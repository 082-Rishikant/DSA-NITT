#include<iostream>
#include<list>
#include<unordered_map>
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
};

int main()
{
  int n=4;

  Graph g(n);
  g.connectNodes(0,1);
  g.connectNodes(1,2);
  g.connectNodes(2,3);
  g.connectNodes(2,0);

  g.printAdjList();
  return 0;
}
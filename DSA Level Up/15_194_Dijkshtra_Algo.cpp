#include<iostream>
#include<list>
#include<set>
#include<vector>
#include<climits>
using namespace std;

class Graph{
  public:
    int n;
    list<pair<int, int>> *l; //(node, weight);
    Graph(int n){
      this->n=n;
      l=new list<pair<int, int>>[n];
    }

    void connect(int i,int j, int w, bool isDir=false){
      l[i].push_back({j, w});
      if(!isDir)
        l[j].push_back({i, w});
    }

    void print(){
      for(int i=0;i<n;i++){
        cout<<i<<" --> ";
        for(auto it:l[i]){
          cout<<"("<<it.first<<", "<<it.second<<"), ";
        }
        cout<<endl;
      }
    }

    vector<int> DijkshtraAlgo(int source){
      vector<int> dist(n, INT_MAX);
      dist[source]=0;
      set<pair<int, int>> st; //w, node
      st.insert({0, source});
      while(!st.empty()){
        int parent=(*st.begin()).second;
        st.erase(st.begin());
        for(auto it:l[parent]){
          int nbrNode=it.first;
          int nbrWt=it.second;
          int d=dist[parent]+nbrWt;
          if(dist[nbrNode]>d){
            st.erase({dist[nbrNode], nbrNode});
            dist[nbrNode]=d;
            st.insert({{dist[nbrNode], nbrNode}});
          }
        }
      }
      return dist;
    }

};

int main()
{
  int n=5;
  Graph g(n);
  g.connect(0, 1, 1);
  g.connect(0, 2, 4);
  g.connect(0, 3, 7);
  g.connect(1, 2, 1);
  g.connect(2, 3, 2);
  g.connect(3, 4, 3);

  // g.print();

  int source=0;
  vector<int> ans=g.DijkshtraAlgo(source);
  for(int i=0;i<n;i++){
    cout<<source<<" to "<<i<<": "<<ans[i]<<endl;
  }
  return 0;
}
#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

class node{
  public:
    string name;
    list<string> nbrs;
    node(string name){
      this->name=name;
    }
};

class Graph{
  public:
    unordered_map<string, node*> m;
    Graph(vector<string> names){
      for(auto it:names){
        node* newNode=new node(it);
        m.insert({it, newNode});
      }
    }

    void connectNodes(string s1, string s2, bool isDir=false){
      node* temp=m[s1];
      temp->nbrs.push_back(s2);
      if(!isDir)
        m[s2]->nbrs.push_back(s1);
    }

    void printAdjl(){
      for(pair<string, node*> it:m){
        cout<<it.first<<"-->  ";
        for(string node:it.second->nbrs){
          cout<<node<<" ";
        }
        cout<<endl;
      }
    }
};

int main()
{
  vector<string> vec={"delhi", "noida", "ncr", "budaun"};
  Graph g(vec);

  g.connectNodes("delhi", "noida");
  g.connectNodes("ncr", "noida");
  g.connectNodes("delhi", "budaun");
  g.connectNodes("delhi", "ncr");

  g.printAdjl();
  return 0;
}
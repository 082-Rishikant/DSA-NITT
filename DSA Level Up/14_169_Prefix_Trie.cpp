#include<iostream>
#include<unordered_map>
using namespace std;

class node{
  public:
    char data;
    bool terminal;
    unordered_map<char, node*> mp;
    node(char c)
    {
      data=c;
      terminal=false;
    }
};

node* makePrefixTrie(string words[], int n, node* root)
{
  root=new node('\0');
  for(int i=0;i<n;i++)
  {
    string s=words[i];
    int j=0;  node* curr=root;
    while(s[j]!='\0')
    {
      if(curr->mp.count(s[j])==0){
        node* newNode=new node(s[j]);
        curr->mp[s[j]]=newNode;
        curr=newNode;
      }else{
        curr=curr->mp.find(s[j])->second;
      }
      j++;
    }
    curr->terminal=true;
  }
  return root;
}

void printTrie(node* root)
{
  if(root->mp.size()==0)
    return;
  node* temp=root;
  for(auto it:temp->mp)
  {
    cout<<it.first<<" ";
    printTrie(it.second);
  }
  return;
}

string search_in_PrefixTrie(node* root, string s)
{
  int i=0;  node* temp=root;
  while(s[i]!='\0'){
    if(temp->mp.find(s[i])==temp->mp.end())
      return "No";
    
    auto it=temp->mp.find(s[i]);
    temp=it->second;
    i++;
  }
  if(temp->terminal)
    return "Yes";
  return "No";
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  string words[]={"apple", "ape", "news", "no", "mango"};
  string queries[]={"app", "ape", "news", "mango"};
  node* root=NULL;
  root=makePrefixTrie(words, sizeof(words)/sizeof(words[0]), root);

  // printTrie(root);

  for(int i=0;i<(sizeof(queries)/sizeof(queries[0]));i++)
  {
    cout<<search_in_PrefixTrie(root, queries[i])<<" ";
  }
  return 0;
}
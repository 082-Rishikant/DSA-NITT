#include<iostream>
#include<unordered_set>
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

node* insertTrie(node* root, string words[], int n)
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

void seacrhInDocs(string doc, node* root, unordered_set<string> &ans)
{
  for(int i=0;i<doc.length();i++)
  {
    node* temp=root; string s=""; int j=i;
    while(true)
    {
      char c=doc[j];    
      if(temp->mp.count(c)!=0){
        temp=temp->mp[c];
        s=s+c;
        j++;
      }else{
        if(temp->terminal)
        {
          ans.insert(s);  
          // cout<<s<<" ";
        }

        s="";
        j++;
        break;
      }
    }
  }
  return;
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

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  string doc="the cute cat loves to code in c++, java & python";
  string words[]={"cute cat", "ttle", "cat", "c++,", "big"};

  unordered_set<string> ans;

  int n=sizeof(words)/sizeof(words[0]);
  node* root=insertTrie(root, words, n);

  // printTrie(root);

  seacrhInDocs(doc, root, ans);

  for(auto it:words)
  {
    if(ans.count(it)!=0)
      cout<<"Yes"<<" ";
    else  
      cout<<"No"<<" ";
  }

  // for(auto it:ans)
  //   cout<<it<<" ";

  return 0;
}